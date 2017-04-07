#include "pcaplogger.h"
#include <QApplication>
#include <QProcess>
#include <QDateTime>
#include <QLocalSocket>
#include <QFile>
#include <QDebug>

const quint32 PcapLogger::WIRESHARK_CONNECTION_TIMEOUT = 30000 /* in msecs */;
const quint32 PcapLogger::WIRESHARK_RESTART_TIMEOUT    = 3000  /* in msecs */;
const QString PcapLogger::WIRESHARK_SOCKET_NAME        = "zboss_sniffer";
const quint8  PcapLogger::PCAP_FCS_LEN                 = 2;


PcapLogger::PcapLogger(QObject *parent) :
    QObject(parent)
{
    isWireshark = true;
    needFcs = false;
    needDiagnosticInfo = false;
    path = "";

    iodev = NULL;
    isOpen = false;
}


PcapLogger::~PcapLogger()
{
    qDebug() << "Pcap logger destroy";
    close();
}



bool PcapLogger::open()
{
    bool ret = false;

    if (isOpen)
    {
        qDebug() << "Logger is already opened";
        return ret;
    }

    if (isWireshark)
    {
        qDebug() << "Prepare to connect Wireshark: local socket listen";
        connect(&server, SIGNAL(newConnection()), this, SLOT(wiresharkConnected()));

        serverName = WIRESHARK_SOCKET_NAME/* + QString::number(channel)*/; // don't need it if we have several channels
        server.removeServer(serverName);
        ret = server.listen(serverName);

        if (ret)
        {
            qDebug() << QString("Listen to socket %1").arg(serverName);
            ret = connectWireshark();
        }
        else
        {
            qDebug() << QString("Cannot listen to local socket %1, error %2").arg(serverName, server.errorString());
            disconnect(&server, SIGNAL(newConnection()), this, SLOT(wiresharkConnected()));
            server.removeServer(serverName);
        }
    }
    else
    {
        qDebug() << "Sniffing to file";
        iodev = new QFile(path);
        ret = iodev->open(QIODevice::WriteOnly);

        if (ret)
        {
            ret = initIoDevConnected();
        }
    }

    return ret;
}


void PcapLogger::close()
{
    if (isWireshark)
    {
        if (server.isListening())
        {
            qDebug() << "Local server close";
            server.close();
            disconnect(&server, SIGNAL(newConnection()), this, SLOT(wiresharkConnected()));
        }

        server.removeServer(serverName);
    }

    disconnectIODev();

    qDebug() << "Pcap logger closed";
}


void PcapLogger::setPath(QString path)
{
    this->path = path;
}

void PcapLogger::setIsWireshark(bool isWireshark)
{
    this->isWireshark = isWireshark;
}

void PcapLogger::setNeedFcs(bool needFcs)
{
    this->needFcs = needFcs;
}

void PcapLogger::setNeedDiagnosticInfo(bool needDiagnosticInfo)
{
    this->needDiagnosticInfo = needDiagnosticInfo;
    this->needFcs = needDiagnosticInfo;
}

bool PcapLogger::getIsOpen()
{
    return isOpen;
}


bool PcapLogger::write(QByteArray packet, quint32 sec, quint32 usec, quint8 channel)
{
    const char ZBOSSHeader[] = { 0x5a, 0x42, 0x4f, 0x53, 0x53, 0x00, (char)channel, 0, 0, 0, 0 };
    const quint32 ZBOSSHeaderLength = this->needDiagnosticInfo ? 11 : 0;

    quint32 sniffedPacketLength = packet.length();
    bool ret;

    qDebug() << "Pcap logger: pkt recv - write";

    if (!isOpen)
    {
        qDebug() << "Logger is closed, can not write packet!";
        return false;
    }

    ret = writePacketHeader(sniffedPacketLength + ZBOSSHeaderLength, sec, usec, needFcs);

    if (ret)
    {
        quint64 written;

        if (!needFcs)
        {
            sniffedPacketLength -= PCAP_FCS_LEN;
        }

        /* adding info about channel */
        written = iodev->write(ZBOSSHeader, ZBOSSHeaderLength);

        written += iodev->write(packet.data(), sniffedPacketLength);

        ret = (written == sniffedPacketLength);

        if (isWireshark)
        {
            ((QLocalSocket *)iodev)->flush();
        }
        else
        {
            ((QFile *)iodev)->flush();
        }
    }

    qDebug() << QString("Pcap logger: write, ret %1").arg(QString::number(ret));
    return ret;
}


bool PcapLogger::writeGlobalHeader()
{
    quint64 written = 0;
    quint32 magicNumber = 0xa1b2c3d4;
    quint16 majorVer = 2;
    quint16 minorVer = 4;
    qint32 zone = 0;
    quint32 sigfigs = 0;
    quint32 snaplen = 65535;
    quint32 macProtocol = 195; /* MAC 802.15.4 proto */

    written += iodev->write((char *)&magicNumber, sizeof(magicNumber));
    written += iodev->write((char *)&majorVer, sizeof(majorVer));
    written += iodev->write((char *)&minorVer, sizeof(minorVer));
    written += iodev->write((char *)&zone, sizeof(zone));
    written += iodev->write((char *)&sigfigs, sizeof(sigfigs));
    written += iodev->write((char *)&snaplen, sizeof(snaplen));
    written += iodev->write((char *)&macProtocol, sizeof(macProtocol));

    return (written == sizeof(magicNumber) + sizeof(majorVer) + sizeof(minorVer) + sizeof(zone) +
            sizeof(sigfigs) + sizeof(snaplen) + sizeof(macProtocol));
}


bool PcapLogger::writePacketHeader(quint16 len, quint32 sec, quint32 usec, bool needFcs)
{
    quint64 written = 0;
    quint32 fileLen = len;
    quint32 packetLen = len;

    if (!needFcs)
    {
        fileLen -= PCAP_FCS_LEN;
    }

    written += iodev->write((char *)&sec, sizeof(sec));
    written += iodev->write((char *)&usec, sizeof(usec));
    written += iodev->write((char *)&fileLen, sizeof(fileLen));
    written += iodev->write((char *)&packetLen, sizeof(packetLen));

    return (written == sizeof(sec) + sizeof(usec) + sizeof(fileLen) + sizeof(packetLen));
}


bool PcapLogger::connectWireshark()
{
    bool ret = false;
    QStringList arg;

    arg << "-i" << server.fullServerName() << "-k" << "-l";

    if (QProcess::startDetached(path, arg))
    {
        ret = waitWiresharkConnection(WIRESHARK_CONNECTION_TIMEOUT);
    }

    return ret;
}


bool PcapLogger::initIoDevConnected()
{
    bool ret;

    ret = writeGlobalHeader();

    if (ret)
    {
        qDebug() << "Global header is written";

        isOpen = true;

        if (isWireshark)
        {
            iodev->setParent(this);
            connect(iodev, SIGNAL(disconnected()), this, SLOT(wiresharkDisconnected()));
        }
    }
    else
    {
        qDebug() << "Can not write global header";

        iodev->close();
        iodev->deleteLater();
        iodev = NULL;
    }

    return ret;
}


bool PcapLogger::waitWiresharkConnection(qint64 timeout)
{
    qint64 connectWaitTime = QDateTime::currentMSecsSinceEpoch() + timeout;

    while (!isOpen && connectWaitTime > QDateTime::currentMSecsSinceEpoch())
    {
        QApplication::processEvents(QEventLoop::AllEvents, 100);
    }

    return isOpen;
}


void PcapLogger::disconnectIODev()
{
    if (!iodev)
    {
        qDebug() << "Connection is already closed";
        return;
    }

    if (isWireshark)
    {
        disconnect(iodev, SIGNAL(disconnected()), this, SLOT(wiresharkDisconnected()));
    }

    if (iodev->isOpen())
    {
        iodev->close();
    }

    iodev->deleteLater();
    iodev = NULL;
    isOpen = false;

    qDebug() << "Local connection closed";
}


void PcapLogger::wiresharkConnected()
{
    qDebug() << "Wireshark connected";

    iodev = server.nextPendingConnection();
    initIoDevConnected();
}


void PcapLogger::wiresharkDisconnected()
{
    qDebug() << "Wireshark disconnected";
    disconnectIODev();

    if (!waitWiresharkConnection(WIRESHARK_RESTART_TIMEOUT))
    {
        close();
        emit connectionLost();
    }
}
