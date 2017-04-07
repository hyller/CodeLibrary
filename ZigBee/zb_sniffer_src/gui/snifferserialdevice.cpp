#include "snifferserialdevice.h"

#include <QDebug>
#include <QDateTime>
#include <QApplication>


const quint16 SnifferSerialDevice::START_OF_FRAME      = 0x13AD;
const quint8  SnifferSerialDevice::START_OF_FRAME_SIZE = sizeof(SnifferSerialDevice::START_OF_FRAME);
const quint16 SnifferSerialDevice::HEADER_SIZE         = sizeof(SnifferSerialDevice::SnifferHeaderT);
const quint32 SnifferSerialDevice::OVERFLOW_TIME       = 2048; /* in usecs */
const quint32 SnifferSerialDevice::TICKS_PER_USEC      = 32;   /* 32 MHZ */

const quint8 SnifferSerialDevice::PAUSE_CMD            = 0xAA;
const quint8 SnifferSerialDevice::STOP_CMD             = 0xBB;

const SnifferSerialDevice::SnifferRadioConfigT SnifferSerialDevice::SNIFFER_RADIO_CONFIGS[SNIFFER_RADIO_NUM_CONFIGS] =
{
    {QString("ZigBee Pro"), 11, 26},
    {QString("SubGHz EU1"),  0, 34},
    {QString("SubGHz EU2"),  0, 17},
    {QString("SubGHz US"),   0, 10},
    {QString("SubGHz JP"),   0, 10},
    {QString("SubGHz CN"),   0, 10}
};

const quint8 SnifferSerialDevice::MIN_PACKET_LEN = 5;
const quint8 SnifferSerialDevice::MAX_PACKET_LEN = 127;
const quint8 SnifferSerialDevice::RSSI_OFFSET    = 73;

const qint32 SnifferSerialDevice::WAIT_DEVICE_CLEAR_TIME = 2000; /* in msecs */


QString SnifferSerialDevice::printDataHex(QByteArray data)
{

    QString res = "";
    qint8 len = data.length();

    for (qint16 i = 0; i < len; i++)
    {
        QString sym = QString::number((quint8)data.data()[i], 16);

        sym = ((quint8)data.data()[i] < 16 ? QString("0x0%1").arg(sym) : QString("0x%1").arg(sym));

        res.append(sym);
        res.append(" ");
    }

    /* remove last space */
    res = res.remove(res.size() - 1, 1);

    return res;
}


SnifferSerialDevice::SnifferSerialDevice(QObject *parent) :
    QSerialPort(parent)
{
    state = SNIFFER_DEVICE_STOPPED;
    channel = SNIFFER_RADIO_CONFIGS[0].minChannel;
    usecOnStart = 0;
    logger.initLogger();
    initReadingCtx();
}


SnifferSerialDevice::~SnifferSerialDevice()
{
    qDebug() << "Sniffer serial device destroy";
    close();
}


bool SnifferSerialDevice::open()
{
    bool ret = QSerialPort::open(ReadWrite);

    if (!ret)
    {
        qDebug() << "Can not open serial port";
    }

    if (ret)
    {
        ret = (setBaudRate(QSerialPort::Baud115200)
               && setDataBits(QSerialPort::Data8)
               && setParity(QSerialPort::NoParity)
               && setFlowControl(QSerialPort::NoFlowControl)
               && setStopBits(QSerialPort::OneStop));

        if (!ret)
        {
            qDebug() << "Can not configure serial port";
        }
    }

    if (ret)
    {
        ret = sendCommand(STOP_CMD);

        if (!ret)
        {
            qDebug() << "Can not start sniffer (send command)";
        }
    }

    if (ret)
    {
        qint64 clearWaitTime = QDateTime::currentMSecsSinceEpoch() + WAIT_DEVICE_CLEAR_TIME;

        /* sync wait until device is clear */
        clear();
        while(clearWaitTime > QDateTime::currentMSecsSinceEpoch())
        {
            QApplication::processEvents(QEventLoop::AllEvents, 100);
        }
    }

    if (ret)
    {
        qDebug() << "Sniffer serial device opened successfully";

        connect(this, SIGNAL(readyRead()), this, SLOT(readAvailable()));
        connect(this, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(deviceError(QSerialPort::SerialPortError)));
    }

    return ret;
}


void SnifferSerialDevice::close()
{
    disconnect(this, SIGNAL(readyRead()), this, SLOT(readAvailable()));
    disconnect(this, SIGNAL(error(QSerialPort::SerialPortError)), this, SLOT(deviceError(QSerialPort::SerialPortError)));

    QSerialPort::clear();
    QSerialPort::close();

    qDebug() << "Sniffer serial device closed";
}


bool SnifferSerialDevice::start()
{
    qDebug() << QString("Starting sniffer at channel %1").arg(QString::number(this->channel));

    /*
     * Don't reset time if sniffer was paused:
     * it will break time difference between packets
     * caught before and after pause
    */
    if (state != SNIFFER_DEVICE_PAUSED)
    {
        usecOnStart = QDateTime::currentMSecsSinceEpoch() * 1000;
    }

    state = SNIFFER_DEVICE_SNIFFING;
    initReadingCtx();

    return sendCommand(channel);
}


void SnifferSerialDevice::stop()
{
    qDebug() << "Sniffer device stop";

    usecOnStart = 0;
    sendCommand(STOP_CMD);
    state = SNIFFER_DEVICE_STOPPED;
}


bool SnifferSerialDevice::pause()
{
    qDebug() << "Sniffer device pause";

    state = SNIFFER_DEVICE_PAUSED;
    return sendCommand(PAUSE_CMD);
}


bool SnifferSerialDevice::setChannel(quint8 channel)
{
    bool ret = true;

    qDebug() << QString("Set sniffer's channel to %1").arg(channel);
    this->channel = channel;

    if (state == SNIFFER_DEVICE_SNIFFING)
    {
        qDebug() << "Sniffer is working when setting channel: Pause";
        ret = sendCommand(PAUSE_CMD);

        if (ret)
        {
            qDebug() << "Start sniffer on a new channel";
            ret = sendCommand(channel);
        }
    }

    return ret;
}


quint8 SnifferSerialDevice::getChannel()
{
    return channel;
}


quint64 SnifferSerialDevice::getUsecOnStart()
{
    return usecOnStart;
}


QString SnifferSerialDevice::errorMsg()
{
    QSerialPort::SerialPortError err = QSerialPort::error();
    qDebug() << QString("Sniffer serial device: error triggered");
    return strSerialError(err);
}


bool SnifferSerialDevice::sendCommand(quint8 command)
{
    qDebug() << QString("Sniffer serial device: command %1").arg(command);
    return (writeData((const char *)&command, 1) == 1);
}


QString SnifferSerialDevice::strSerialError(QSerialPort::SerialPortError err)
{
    QString res;

    switch (err)
    {
    case QSerialPort::NoError: res = "No error"; break;
    case QSerialPort::DeviceNotFoundError: res = "Device not found"; break;
    case QSerialPort::PermissionError: res = "Permission denied"; break;
    case QSerialPort::OpenError: res = "Already open"; break;
    case QSerialPort::ParityError: res = "Device paritty error"; break;
    case QSerialPort::FramingError: res = "Device framing error"; break;
    case QSerialPort::ReadError: res = "Device read error"; break;
    case QSerialPort::WriteError: res = "Device write error"; break;
    case QSerialPort::ResourceError: res = "Device unplugged"; break;
    default: res = "Unknown device error";
    };

    qDebug() << res;
    return res;
}


void SnifferSerialDevice::initReadingCtx()
{
    readingState = SNIFFER_DEVICE_HEADER;
    leftLen = HEADER_SIZE;
    len = 0;
    sec = 0;
    usec = 0;
    packet = QByteArray();
}


void SnifferSerialDevice::calculateTimestamp(SnifferTimestampT *timestamp)
{
    QString log;
    quint64 usecs = (quint64)timestamp->overflows * OVERFLOW_TIME
            + ((quint16)timestamp->high << 8 | timestamp->low) / TICKS_PER_USEC
            + usecOnStart;

    log = QString("TIMESTAMP: overflows: %1; high %2 ; low %3").arg(
                QString::number(timestamp->overflows),
                QString::number(timestamp->high),
                QString::number(timestamp->low));
    qDebug() << log;
    logger.writeLog(log);

    this->sec = usecs / 1000000;
    this->usec = usecs % 1000000;

    log = QString("TIMESTAMP: calculated: sec %1; usec %2").arg(
                QString::number(this->sec),
                QString::number(this->usec));
    qDebug() << log;
    logger.writeLog(log);
}


void SnifferSerialDevice::saveHdrInfo(SnifferHeaderT *hdr)
{
    this->len = hdr->length;
    calculateTimestamp(&hdr->timestamp);

    qDebug() << QString("Hdr: len %1, sec %2, usec %3").arg(
                    QString::number(this->len), QString::number(this->sec), QString::number(this->usec));;
}


void SnifferSerialDevice::parseSnifferPacket()
{
    quint32 recvLen = this->len;

    qDebug() << QString("Packet from sniffer: len from hdr %1").arg(QString::number(recvLen));
    qDebug() << printDataHex(packet);
    while (recvLen > 0)
    {
        quint8 currPacketLen = packet[0];

        if (currPacketLen >= MIN_PACKET_LEN
                && currPacketLen <= MAX_PACKET_LEN
                && currPacketLen <= recvLen)
        {
            /* Len is OK, check CRC bit */
            recvLen--;
            packet = packet.right(recvLen);

            if (((quint8)packet.at(currPacketLen - 1)) > 127) /* check MSb */
            {
                /* Prepare packet RSSI */
                packet[currPacketLen - 2] = packet[currPacketLen - 2] - RSSI_OFFSET;

                qDebug() << QString("Packet captured: len %1").arg(QString::number(currPacketLen));
                emit snifferDevicePacket(packet.left(currPacketLen), this->sec, this->usec, this->getChannel());
            }
            else
            {
                qDebug() << "Invalid FCS";
            }

            recvLen -= currPacketLen;
            packet = packet.right(recvLen);
        }
        else
        {
            qDebug() << QString("Invalid packet len %1. Skip this packet").arg(QString::number(currPacketLen));
            packet.clear();
            recvLen = 0;
        }
    }
}


void SnifferSerialDevice::readAvailable()
{
    QByteArray raw = this->readAll();
    quint32 rawLen = raw.length();

    qDebug() << QString("Read from sniffer serial device: %1 bytes").arg(QString::number(rawLen));
    qDebug() << printDataHex(raw);
    while (rawLen > 0)
    {
        quint32 appendLen = ( rawLen > leftLen ? leftLen : rawLen);

        leftLen -= appendLen;
        packet.append(raw.left(appendLen));

        rawLen -= appendLen;
        raw = raw.right(rawLen);

        if (leftLen == 0)
        {
            if (readingState == SNIFFER_DEVICE_HEADER)
            {
                SnifferHeaderT *hdr = (SnifferHeaderT *)packet.data();

                qDebug() << "Packet header recv";
                qDebug() << printDataHex(packet);

                if (hdr->magicWord == START_OF_FRAME
                        && hdr->length >= MIN_PACKET_LEN
                        && hdr->length <= 128) /* TODO: const */
                {
                    /* Valid packet header */
                    saveHdrInfo(hdr);
                    leftLen = hdr->length;
                    readingState = SNIFFER_DEVICE_PACKET;
                    packet.clear();
                }
                else
                {
                    /* Invalid packet header: look for the next start of frame delimeter */
                    leftLen = 1;
                    packet = packet.right(packet.length() - leftLen);

                    qDebug() << "Invalid packet hdr, skip";
                }
            }
            else if (readingState == SNIFFER_DEVICE_PACKET)
            {
                parseSnifferPacket();
                leftLen = HEADER_SIZE;
                readingState = SNIFFER_DEVICE_HEADER;
            }
            else
            {
                /* Wow! */
                qDebug() << "This can not happen!";
            }
        }
    }
}


void SnifferSerialDevice::deviceError(SerialPortError err)
{
    emit snifferDeviceError(strSerialError(err));
}
