/***************************************************************************
*                      ZBOSS ZigBee Pro 2007 stack                         *
*                                                                          *
*          Copyright (c) 2013 DSR Corporation Denver CO, USA.              *
*                       http://www.dsr-wireless.com                        *
*                                                                          *
*          Copyright (c) 2012 DSR Corporation Denver CO, USA.              *
*                       http://www.dsr-wireless.com                        *
*                                                                          *
*          Copyright (c) 2011 DSR Corporation Denver CO, USA.              *
*                       http://www.dsr-wireless.com                        *
*                                                                          *
*                            All rights reserved.                          *
*                                                                          *
*                                                                          *
* ZigBee Pro 2007 stack, also known as ZBOSS (R) ZB stack is available     *
* under either the terms of the Commercial License or the GNU General      *
* Public License version 2.0.  As a recipient of ZigBee Pro 2007 stack,    *
* you may choose which license to receive this code under (except as noted *
* in per-module LICENSE files).                                            *
*                                                                          *
* ZBOSS is a registered trademark of DSR Corporation AKA Data Storage      *
* Research LLC.                                                            *
*                                                                          *
* GNU General Public License Usage                                         *
* This file may be used under the terms of the GNU General Public License  *
* version 2.0 as published by the Free Software Foundation and appearing   *
* in the file LICENSE.GPL included in the packaging of this file.  Please  *
* review the following information to ensure the GNU General Public        *
* License version 2.0 requirements will be met:                            *
* http://www.gnu.org/licenses/old-licenses/gpl-2.0.html.                   *
*                                                                          *
* Commercial Usage                                                         *
* Licensees holding valid DSR Commercial licenses may use this file        *
* in accordance with the DSR Commercial License Agreement provided with    *
* the Software or, alternatively, in accordance with the terms contained   *
* in a written agreement between you and DSR.                              *
****************************************************************************
PURPOSE:
*/
#include "sniffercontroller.h"
#include <QDateTime>
#include <QProcess>
#include <QFile>


const qint32 SnifferController::WIRESHARK_WAIT_FOR_CONNECT_TIME = 30000;
const qint32 SnifferController::WIRESHARK_WAIT_FOR_RECONNECT_TIME = 3000;
const QString SnifferController::DEFAULT_DUMP_DESTINATION = "DUMP.PCAP";

SnifferController::SnifferController(QObject *parent) :
    QObject(parent)
{
}

SnifferController::SnifferController(QString portName, bool needWireshark, QString path,
                                     quint8 radioConfig, quint8 channel, bool needFcs,
                                     QObject *parent):
    QObject(parent)
{
    this->portName = portName;
    this->needWireshark = needWireshark;
    this->path = path;
    this->radioConfig = radioConfig;
    this->channel = channel;
    this->needFcs = needFcs;

    bridge = new WiresharkBridge();
    device = new SnifferSerialDevice(portName);
    decrypt = new SnifferPacketDecryptor();
    logger = new SnifferLogger();

    logger->initLogger();

    connect(this, SIGNAL(errorOccured(QString)), this, SIGNAL(logMessage(QString)));
    /*
    connect(bridge, SIGNAL(wiresharkConnected(QLocalSocket*)), this, SLOT(wiresharkConnected(QLocalSocket*)));
    connect(bridge, SIGNAL(wiresharkDisconnected()), this, SLOT(wiresharkDisconnected()));
    */

    this->isSniffing = false;
    this->dumpDestination = NULL;

    logger->writeLog("Sniffer controller created");
}

SnifferController::~SnifferController()
{
    logger->writeLog("Sniffer controller destroying");

    bridge->deleteLater();
    device->deleteLater();
    decrypt->deleteLater();
    logger->deleteLater();
}

void SnifferController::setPortName(QString portName)
{
    if (device->isOpen())
    {
        device->stopDevice();
    }

    device->setPortName(portName);
    this->portName = portName;

    logger->writeLog("Sniffer device set port name to " + portName);
}

void SnifferController::setNeedWireshark(bool needWireshark)
{
    this->needWireshark = needWireshark;

    logger->writeLog(QString("Wireshark need: %1").arg(QString::number(needWireshark, 2)));
}

void SnifferController::setPath(QString path)
{
    this->path = path;

    logger->writeLog("Output path set to " + path);
}

void SnifferController::setRadioConfig(quint8 radioConfig)
{
    if (isSniffing)
    {
        stopSniffer();
    }

    this->radioConfig = radioConfig;

    logger->writeLog(QString("Radio configuration set to %1").arg(QString::number(radioConfig)));
}

void SnifferController::setChannel(quint8 channel)
{
    bool wasSniffing = isSniffing;

    if (wasSniffing)
    {
        pauseSniffer(true);
    }

    this->channel = channel;
    logger->writeLog(QString("Channel set to %1").arg(QString::number(channel, 10)));

    if (wasSniffing)
    {
        resumeSniffer();
    }
}


void SnifferController::startSniffer()
{
    bool ret;

    emit syncProcessStart();

    ret = device->startDevice();
    if (!ret)
    {
        emit errorOccured("Failed to connect to the device");
        logger->writeLog("Failed to start device");
    }

    if (ret)
    {
        connect(device, SIGNAL(readyRead()), this, SLOT(deviceReadAvailable()));
        connect(device, SIGNAL(snifferDeviceError(QString)),
                this, SLOT(deviceError(QString)));
        connect(decrypt, SIGNAL(packetRecv(QByteArray,quint8,quint32,quint32)),
                this, SLOT(packetRecv(QByteArray,quint8,quint32,quint32)));

        logger->writeLog("Device start successfull");
        ret = device->sendCommand(SnifferSerialDevice::SNIFFER_STOP_CHAR);

        if (!ret)
        {
            emit errorOccured("Failed to send command to the device");
            logger->writeLog("Failed to send command to the device");
        }
    }

    if (ret)
    {
        logger->writeLog("Send start command to device succesfull");

        if (needWireshark)
        {
            emit logMessage("Start Wireshark connection server");

            ret = bridge->startBridge();
            if (!ret)
            {
                logger->writeLog("Start Wireshark connection server failed");
                emit errorOccured("Failed to start Wireshark connection server");
            }
            else
            {
                logger->writeLog("Wireshark connection server started successfully");
                emit logMessage(QString("Starting Wireshark..."));

                connect(bridge, SIGNAL(wiresharkConnected(QLocalSocket*)), this, SLOT(wiresharkConnected(QLocalSocket*)));
                connect(bridge, SIGNAL(wiresharkDisconnected()), this, SLOT(wiresharkDisconnected()));

                ret = bridge->startWireshark(path);
                if (!ret)
                {
                    emit waitingWireshark();
                    emit errorOccured("Failed to start Wireshark.");
                    logger->writeLog("Failed to start Wireshark");
                }
            }
        }
        else
        {
            emit logMessage(QString("Sniffing to file %1").arg(path));
            logger->writeLog("Sniffing to file");

            dumpDestination = new QFile(path);
            ret = PcapDumper::initDump(dumpDestination);
            if (ret)
            {
                doSniff();
            }
            else
            {
                emit errorOccured("Failed to initialize dump file");
                logger->writeLog("Failed to initialize dump file");
            }
        }
    }

    if (!ret)
    {
        emit syncProcessFinished();
        stopSniffer();
    }
}

bool SnifferController::restartWireshark()
{
    logger->writeLog("Restarting Wireshark");
    decrypt->refreshBaseTimestamp();
    return bridge->startWireshark(path);
}

void SnifferController::pauseSniffer(bool wiresharkConnected)
{
    char signal = (wiresharkConnected ? SnifferSerialDevice::SNIFFER_PAUSE_CHAR : SnifferSerialDevice::SNIFFER_STOP_CHAR);

    if (device->sendCommand(signal))
    {
        emit logMessage("Pause...");
        logger->writeLog("Pause");

        isSniffing = false;
    }
    else
    {
        emit errorOccured("Failed to pause the Sniffer device. Stop capture.");
        logger->writeLog("Failed to pause sniffer");
        stopSniffer();
    }
}

void SnifferController::resumeSniffer()
{
    emit logMessage("Resume");
    logger->writeLog("Resume");
    doSniff();
}

void SnifferController::stopSniffer()
{
    emit logMessage("Stop capture...");
    logger->writeLog("Stopping sniffer");

    isSniffing = false;

    if (device->isOpen())
    {
        emit logMessage("Stop the Sniffer device");

        device->sendCommand(SnifferSerialDevice::SNIFFER_STOP_CHAR);
        device->stopDevice();

        disconnect(device, SIGNAL(readyRead()), this, SLOT(deviceReadAvailable()));
        disconnect(device, SIGNAL(error(QSerialPort::SerialPortError)),
                   this, SLOT(deviceError(QSerialPort::SerialPortError)));
        disconnect(decrypt, SIGNAL(packetRecv(QByteArray,quint8,quint32,quint32)),
                   this, SLOT(packetRecv(QByteArray,quint8,quint32,quint32)));

        logger->writeLog("Sniffer device is stopped");
    }

    if (!needWireshark)
    {
        if (dumpDestination != NULL && QString(dumpDestination->metaObject()->className()).contains("QFile"))
        {
            emit logMessage("Close dump file");

            dumpDestination->close();
            dumpDestination->deleteLater();

            logger->writeLog("Dump file is closed");
        }
    }

    if (bridge->isListening())
    {
        emit logMessage("Stop the Wireshark connection server");

        bridge->stopBridge();

        disconnect(bridge, SIGNAL(wiresharkConnected(QLocalSocket*)), this, SLOT(wiresharkConnected(QLocalSocket*)));
        disconnect(bridge, SIGNAL(wiresharkDisconnected()), this, SLOT(wiresharkDisconnected()));

        logger->writeLog("Wireshark connection server is stopped");
    }

     decrypt->clear();
     logger->writeLog("Decryptor is cleared");
}

void SnifferController::doSniff()
{
    if (device->sendCommand(channel))
    {
        emit logMessage("The Sniffer device started.");
        emit nowSniffing();

        logger->writeLog("Sniffer is started");

        isSniffing = true;
        decrypt->refreshBaseTimestamp();
    }
    else
    {
        emit errorOccured("Failed to start the Sniffer device. Stop capture.");
        logger->writeLog("Failed to start sniffer device");
        stopSniffer();
    }
}

void SnifferController::deviceReadAvailable()
{
    QByteArray data = device->readAll();

    logger->writeLog(QString("Device read %1 bytes").arg(data.count()));
    if (isSniffing)
    {
        decrypt->feed(data);
    }
}

void SnifferController::wiresharkConnected(QLocalSocket *sock)
{
    emit syncProcessFinished();
    emit logMessage("Wireshark connected.");

    logger->writeLog("Wireshark is connected");

    dumpDestination = sock;

    if (PcapDumper::initDump(dumpDestination))
    {
        doSniff();
    }
    else
    {
        emit logMessage(QString("Can't open Wireshark socket"));
        logger->writeLog("Failed to open Wireshark socket");
    }
}

void SnifferController::wiresharkDisconnected()
{
    emit logMessage(QString("Wireshark was disconnected"));
    logger->writeLog("Wireshark was disconnected");

    /* Can not resume until Wireshark connects */
    emit waitingWireshark();

    if (isSniffing)
    {
        pauseSniffer(false);
    }
}

void SnifferController::deviceError(QString err)
{
    emit errorOccured(err);
    emit deviceDisconnected();
    stopSniffer();
}

void SnifferController::packetRecv(QByteArray packet, quint8 len, quint32 sec, quint32 usec)
{
    /*TODO check ret code */
    QString dump = decrypt->printPacketHex(packet);

    emit logMessage(QString("Packet received: length %1\n%2").arg(QString::number(len, 10), dump));
    logger->writeLog(QString("Packet received: length %1\n%2").arg(QString::number(len, 10), dump));

    PcapDumper::writePacket(dumpDestination, packet.data(), len, needFcs, sec, usec);
}

void SnifferController::setNeedFcs(bool needFcs)
{
    this->needFcs = needFcs;
}
