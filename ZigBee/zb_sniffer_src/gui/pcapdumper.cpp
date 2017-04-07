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
#include "pcapdumper.h"
#include <QDateTime>
#include <QDebug>
#include <QLocalSocket>
#include <QFile>

const int PcapDumper::PCAP_FCS_LEN = 2;

bool PcapDumper::initDump(QIODevice *dev)
{
    bool ret = true;

    if (!dev->isOpen())
    {
        if (dev->open(QIODevice::WriteOnly))
        {
            ret = true;
        }
    }

    /* Check for QLocalSocket. H8 reflection(( */
    if (QString(dev->metaObject()->className()).contains("QLocalSocket"))
    {
        ret = true;
    }

    if (ret)
    {
        ret = writeGlobalHeader(dev);
    }

    return ret;
}

bool PcapDumper::writePacket(QIODevice *dev, char *buf, quint32 len, bool needFcs, quint32 sec, quint32 usec)
{
    bool ret;

    ret = writePacketHeader(dev, len, needFcs, sec, usec);
    if (ret)
    {
        quint64 written;

        if (!needFcs)
        {
            len -= PCAP_FCS_LEN;
        }

        written = dev->write((char *)buf, len);
        ret = (written == len);
        if (!QString(dev->metaObject()->className()).contains("QLocalSocket"))
        {
            ((QFile *)dev)->flush();
        }
        else
        {
            ((QLocalSocket *)dev)->flush();
        }
    }

    return ret;
}

bool PcapDumper::writeGlobalHeader(QIODevice *dev)
{
    quint64 written = 0;
    quint32 magicNumber = 0xa1b2c3d4;
    quint16 majorVer = 2;
    quint16 minorVer = 4;
    qint32 zone = 0;
    quint32 sigfigs = 0;
    quint32 snaplen = 65535;
    quint32 macProtocol = 195; /* MAC 802.15.4 proto */

    written += dev->write((char *)&magicNumber, sizeof(magicNumber));
    written += dev->write((char *)&majorVer, sizeof(majorVer));
    written += dev->write((char *)&minorVer, sizeof(minorVer));
    written += dev->write((char *)&zone, sizeof(zone));
    written += dev->write((char *)&sigfigs, sizeof(sigfigs));
    written += dev->write((char *)&snaplen, sizeof(snaplen));
    written += dev->write((char *)&macProtocol, sizeof(macProtocol));

    return (written == sizeof(magicNumber) + sizeof(majorVer) + sizeof(minorVer) + sizeof(zone) +
            sizeof(sigfigs) + sizeof(snaplen) + sizeof(macProtocol));
}

bool PcapDumper::writePacketHeader(QIODevice *dev, int len, bool needFcs, quint32 sec, quint32 usec)
{
    quint64 written = 0;
    quint32 fileLen = len;
    quint32 packetLen = len;

    if (!needFcs)
    {
        fileLen -= PCAP_FCS_LEN;
    }

    written += dev->write((char *)&sec, sizeof(sec));
    written += dev->write((char *)&usec, sizeof(usec));
    written += dev->write((char *)&fileLen, sizeof(fileLen));
    written += dev->write((char *)&packetLen, sizeof(packetLen));

    return (written == sizeof(sec) + sizeof(usec) + sizeof(fileLen) + sizeof(packetLen));
}
