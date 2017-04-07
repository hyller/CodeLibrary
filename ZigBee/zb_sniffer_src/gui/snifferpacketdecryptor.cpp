#include <QDebug>
#include <QDateTime>
#include "snifferpacketdecryptor.h"

const quint16 SnifferPacketDecryptor::SNIFFER_MAGIC_WORD = 0x13AD;
const qint32  SnifferPacketDecryptor::SNIFFER_RSSI_OFFSET = 73;
const quint32 SnifferPacketDecryptor::SNIFFER_TIMESTAMP_SIZE = sizeof(SnifferTimestampT);
const quint32 SnifferPacketDecryptor::SNIFFER_HEADER_SIZE = sizeof(SnifferHeaderT);

SnifferPacketDecryptor::SnifferPacketDecryptor(QObject *parent):
    QObject(parent)
{
    isPayload = false;
    bytesLeft = SNIFFER_HEADER_SIZE;
    refreshBaseTimestamp();
    memset(&hdr, 0, sizeof(hdr));
    cnt = 0;
}

void SnifferPacketDecryptor::refreshBaseTimestamp()
{
    quint64 currTime = (QDateTime::currentDateTime()).toMSecsSinceEpoch();

    baseTimestamp.sec = currTime / 1000;
    baseTimestamp.usec = (currTime % 1000) * 1000;
}

void SnifferPacketDecryptor::clear()
{
    isPayload = false;
    bytesLeft = SNIFFER_HEADER_SIZE;
    currData.clear();
}

void SnifferPacketDecryptor::feed(QByteArray data)
{
    quint32 lenFeed = data.length();

    qDebug() << QString("Feed %1 bytes").arg(lenFeed);
    qDebug() << printPacketHex(data);

    while (lenFeed > 0)
    {
        if (lenFeed >= bytesLeft)
        {
            currData.append(data.left(bytesLeft));
            data = data.right(lenFeed - bytesLeft);
            lenFeed -= bytesLeft;

            if (isPayload)
            {
                qDebug() << "Payload complete";
                addTimestamp(&hdr.timestamp);

                qDebug() << QString("Packet: %1 bytes").arg(hdr.length);
                qDebug() << printPacketHex(currData);
                currData[hdr.length - 2] = (qint8)currData[hdr.length - 2] - SNIFFER_RSSI_OFFSET;

                if (filter(currData))
                {
                    emit packetRecv(currData, hdr.length, hdr.timestamp.sec, hdr.timestamp.usec);
                }

                isPayload = false;
                bytesLeft = SNIFFER_HEADER_SIZE;
                currData.clear();
            }
            else
            {
                hdr = *(SnifferHeaderT *)currData.data();

                if(hdr.magicWord != SNIFFER_MAGIC_WORD)
                {
                    qDebug() << QString("Invalid magic word! %1").arg(hdr.magicWord);
                    currData = currData.right(currData.size() - 1);
                    bytesLeft = 1;
                }
                /* TODO: define 128 */
                else if (hdr.length == 0 || hdr.length > 128)
                {
                    qDebug() << QString("Invalid packet length in header! %1").arg(hdr.length);
                    bytesLeft = SNIFFER_HEADER_SIZE;
                    currData.clear();
                }
                else
                {
                    qDebug() << QString("Header complete, len %1").arg(hdr.length);
                    qDebug() << sizeof(SnifferHeaderT);

                    bytesLeft = hdr.length;
                    isPayload = true;
                    currData.clear();
                }
            }
        }
        else
        {
            currData.append(data);
            bytesLeft -= lenFeed;
            lenFeed = 0;

            qDebug() << QString("%1 left").arg(QString::number(bytesLeft, 10));
        }
    }
}

bool checkCmdTypeReserved(quint16 fcf)
{
    return (fcf & 0x04) && (fcf & 0x02);
}

bool checkDstModeReserved(quint16 fcf)
{
    return ((fcf & (1 << 10)) && !(fcf & (1 << 11))) || ((fcf & (1 << 14) && !(fcf & (1 << 15))));
}

bool checkFrmVersionReserved(quint16 fcf)
{
    return (fcf & (1 << 12) && fcf & (1 << 13));
}

bool checkFcfReservedBit7(quint16 fcf)
{
    return fcf & (1 << 7);
}

bool SnifferPacketDecryptor::filter(QByteArray data)
{   
    bool ret = true;
    quint8 len = data.length();

    ret = (len >= 5);

    if (ret)
    {
        quint16 fcf = data[1];

        fcf <<= 8;
        fcf |= data[0];

        ret = !(checkCmdTypeReserved(fcf) || checkDstModeReserved(fcf) ||
                    checkFrmVersionReserved(fcf) || checkFcfReservedBit7(fcf));
    }

    return ret;
}

QString SnifferPacketDecryptor::printPacketHex(QByteArray packet)
{
    QString res = "";
    qint8 len = packet.length();

    for (qint16 i = 0; i < len; i++)
    {
        QString sym = QString::number((quint8)packet.data()[i], 16);

        sym = ((quint8)packet.data()[i] < 16 ? QString("0x0%1").arg(sym) : QString("0x%1").arg(sym));

        res.append(sym);
        res.append(" ");
    }

    /* remove last space */
    res = res.remove(res.size() - 1, 1);

    return res;
}

void SnifferPacketDecryptor::addTimestamp(SnifferTimestampT *t)
{
    t->sec = baseTimestamp.sec + t->sec;
    t->usec = baseTimestamp.usec + t->usec;
    t->sec += t->usec / 1000000;
    t->usec %= 1000000;
}
