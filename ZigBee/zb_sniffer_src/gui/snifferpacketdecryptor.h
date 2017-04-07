#ifndef SNIFFERPACKETDECRYPTOR_H
#define SNIFFERPACKETDECRYPTOR_H

#include <QObject>

class SnifferPacketDecryptor : public QObject
{
    Q_OBJECT

public:
    explicit SnifferPacketDecryptor(QObject *parent = 0);
    void refreshBaseTimestamp();
    void feed(QByteArray data);
    bool filter(QByteArray data);
    QString printPacketHex(QByteArray packet);
    void clear();

signals:
    void packetRecv(QByteArray packet, quint8 len, quint32 sec, quint32 usec);

private:

    static const quint16 SNIFFER_MAGIC_WORD;
    static const qint32  SNIFFER_RSSI_OFFSET;
    static const quint32 SNIFFER_TIMESTAMP_SIZE;
    static const quint32 SNIFFER_HEADER_SIZE;

#pragma pack(push, 1)
    typedef struct SnifferTimestampS
    {
        quint32 sec;
        quint32 usec;
    } SnifferTimestampT;

    typedef struct SnifferHeaderS
    {
        quint16 magicWord;
        quint8 length;
        SnifferTimestampT timestamp;
    } SnifferHeaderT;
#pragma pack(pop)

    QByteArray currData;
    bool isPayload;
    quint8 bytesLeft;

    SnifferTimestampT baseTimestamp;
    SnifferHeaderT hdr;
    quint32 cnt;

    void addTimestamp(SnifferTimestampT *t);
};

#endif // SNIFFERPACKETDECRYPTOR_H
