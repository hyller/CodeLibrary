#ifndef SNIFFERSERIALDEVICE_H
#define SNIFFERSERIALDEVICE_H

#include <QSerialPort>
#include "snifferlogger.h"

class SnifferSerialDevice : public QSerialPort
{
    Q_OBJECT

public:

    enum SnifferDeviceStateE
    {
        SNIFFER_DEVICE_STOPPED   = 0,
        SNIFFER_DEVICE_SNIFFING,
        SNIFFER_DEVICE_PAUSED,
    };

    enum SnifferRadioConfigE
    {
        SNIFFER_RADIO_START_CONFIGS = 0,
        SNIFFER_RADIO_PRO           = SNIFFER_RADIO_START_CONFIGS,
        SNIFFER_RADIO_SUB_GHZ_EU1   = 1,
        SNIFFER_RADIO_SUB_GHZ_EU2   = 2,
        SNIFFER_RADIO_SUB_GHZ_US    = 3,
        SNIFFER_RADIO_SUB_GHZ_JP    = 4,
        SNIFFER_RADIO_SUB_GHZ_CN    = 5,
        SNIFFER_RADIO_NUM_CONFIGS   = 6,
    };

    typedef struct SnifferRadioConfigS
    {
        QString title;
        uchar   minChannel;
        uchar   maxChannel;
    }
    SnifferRadioConfigT;

    static const SnifferRadioConfigT SNIFFER_RADIO_CONFIGS[SNIFFER_RADIO_NUM_CONFIGS];

    static QString printDataHex(QByteArray data);

    explicit SnifferSerialDevice(QObject *parent = 0);
    ~SnifferSerialDevice();

    bool open();
    void close();

    bool start();
    bool pause();
    void stop();

    bool setChannel(quint8 channel);

    quint8  getChannel();
    quint64 getUsecOnStart();

    QString errorMsg();

signals:
    /* 03/07/17 CR DD start */
    void snifferDevicePacket(QByteArray packet, quint32 sec, quint32 usec, quint8 channel);
    /* 03/07/17 CR DD end*/
    void snifferDeviceError(QString err);

private:

    enum SnifferReadingStateE
    {
        SNIFFER_DEVICE_HEADER,
        SNIFFER_DEVICE_PACKET,
    };

#pragma pack(push, 1)
    typedef struct SnifferTimestampS
    {
        quint32 overflows;
        quint8 low;
        quint8 high;
    } SnifferTimestampT;

    typedef struct SnifferHeaderS
    {
        quint16 magicWord;
        quint8 length;
        SnifferTimestampT timestamp;
    } SnifferHeaderT;
#pragma pack(pop)

    static const quint16 START_OF_FRAME;         /* Magic start of frame sequence */
    static const quint8  START_OF_FRAME_SIZE;
    static const quint16 HEADER_SIZE;

    static const quint32 OVERFLOW_TIME;          /* CC25xx Timer 2 capacity */
    static const quint32 TICKS_PER_USEC;         /* CC25xx Timer 2 frequency */

    static const qint32  WAIT_DEVICE_CLEAR_TIME; /* Time to wait for serial port to flush */

    static const quint8  STOP_CMD;
    static const quint8  PAUSE_CMD;

    static const quint8  MIN_PACKET_LEN; /* Size of ack - 5 bytes */
    static const quint8  MAX_PACKET_LEN; /* Not ZB's 127 bytes but the size of CC25xx FIFO (128) */
    static const quint8  RSSI_OFFSET;    /* Offset to calculate actual RSSI on CC25xx */

    SnifferReadingStateE readingState;
    QByteArray packet;
    quint8 leftLen;
    quint8 len;
    quint64 sec;
    quint64 usec;
    quint64 usecOnStart;

    quint8 channel;
    SnifferDeviceStateE state;

    SnifferLogger logger;

    bool sendCommand(quint8 command);
    QString strSerialError(QSerialPort::SerialPortError err);

    void initReadingCtx();
    void calculateTimestamp(SnifferTimestampT *timestamp);
    void saveHdrInfo(SnifferHeaderT *hdr);
    void parseSnifferPacket();

private slots:
    void readAvailable();
    void deviceError(QSerialPort::SerialPortError err);
};

#endif // SNIFFERSERIALDEVICE_H
