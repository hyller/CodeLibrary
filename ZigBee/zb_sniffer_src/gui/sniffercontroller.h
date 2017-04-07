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
#ifndef SNIFFERCONTROLLER_H
#define SNIFFERCONTROLLER_H

#include <QObject>
#include <QByteArray>
#include <QTimer>
#include "snifferserialdevice.h"
#include "pcapdumper.h"
#include "wiresharkbridge.h"
#include "snifferpacketdecryptor.h"
#include "snifferlogger.h"

class SnifferController : public QObject
{
    Q_OBJECT
public:
    explicit SnifferController(QObject *parent = 0);
    explicit SnifferController(QString portName, bool needWireshark, QString path,
                               quint8 radioConfig, quint8 channel, bool needFcs,
                               QObject *parent = 0);
    ~SnifferController();

    void reconfigureDevice(QString portName);
    void reconfigureOutput(bool needWireshark, QString path);
    void reconfigureRadio(quint8 radioConfig, quint8 channel);

    void startSniffer();
    void pauseSniffer(bool wiresharkConnected);
    void resumeSniffer();
    void stopSniffer();

    bool restartWireshark();

    void setPortName(QString portName);
    void setNeedWireshark(bool needWireshark);
    void setPath(QString path);
    void setRadioConfig(quint8 radioConfig);
    void setChannel(quint8 channel);

public slots:
    void setNeedFcs(bool needFcs);

private:

    static const qint32 WIRESHARK_WAIT_FOR_CONNECT_TIME;
    static const qint32 WIRESHARK_WAIT_FOR_RECONNECT_TIME;
    static const QString DEFAULT_DUMP_DESTINATION;

    /* Initial context */
    QString portName;
    bool needWireshark;
    QString path;
    quint8 radioConfig;
    quint8 channel;
    bool needFcs;

    /* Sniffing services */
    WiresharkBridge         *bridge;
    SnifferSerialDevice     *device;
    SnifferPacketDecryptor  *decrypt;
    SnifferLogger *logger;

    /* Sniffing status */
    bool isSniffing;
    QIODevice *dumpDestination;
    /* -------------------- */


    bool openDevice();
    void doSniff();

signals:
    void logMessage(QString msg);
    void errorOccured(QString desc);
    void syncProcessStart();
    void syncProcessFinished();
    void nowSniffing();
    void waitingWireshark();
    void deviceDisconnected();

private slots:
    void packetRecv(QByteArray packet, quint8 len, quint32 sec, quint32 usec);
    void wiresharkConnected(QLocalSocket *sock);
    void wiresharkDisconnected();
    void deviceError(QString err);
    void deviceReadAvailable();
};

#endif // SNIFFERCONTROLLER_H
