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

#include <QProcess>
#include "wiresharkbridge.h"

const QString WiresharkBridge::WS_SOCKET_NAME = "ZBOSS to Wireshark";

WiresharkBridge::WiresharkBridge(QObject *parent) :
    QObject(parent)
{
    serv = new QLocalServer();
    wiresharkSock = NULL;
    connect(serv, SIGNAL(newConnection()), this, SLOT(wiresharkConnectedHandler()));
}

WiresharkBridge::~WiresharkBridge()
{
    serv->deleteLater();

    if (wiresharkSock != NULL)
    {
        wiresharkSock->deleteLater();
    }
}

bool WiresharkBridge::isListening()
{
    return serv->isListening();
}

bool WiresharkBridge::startBridge()
{
    bool ret;

    serv->removeServer(WS_SOCKET_NAME);
    ret = serv->listen(WS_SOCKET_NAME);

    return ret;
}

bool WiresharkBridge::startWireshark(QString path)
{
    QStringList arg;

    arg << "-i" << serv->fullServerName() << "-k" << "-l";

    return QProcess::startDetached(path, arg);
}

void WiresharkBridge::stopBridge()
{
    if (wiresharkSock != NULL)
    {
        if (wiresharkSock->isOpen())
        {
            wiresharkSock->close();
            wiresharkSock->deleteLater();
        }
    }
    serv->close();
}

QString WiresharkBridge::fullServerName()
{
    return serv->fullServerName();
}

void WiresharkBridge::wiresharkConnectedHandler()
{
    wiresharkSock = serv->nextPendingConnection();
    wiresharkSock->setParent(0);

    connect(wiresharkSock, SIGNAL(disconnected()), this, SIGNAL(wiresharkDisconnected()));
    emit wiresharkConnected(wiresharkSock);
}
