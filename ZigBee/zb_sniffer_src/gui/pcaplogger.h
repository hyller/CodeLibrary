#ifndef PCAPLOGGER_H
#define PCAPLOGGER_H

#include <QObject>
#include <QLocalServer>
#include <QByteArray>

class PcapLogger : public QObject
{
    Q_OBJECT
public:

    explicit PcapLogger(QObject *parent = 0);
    ~PcapLogger();

    bool open();
    void close();

    void setPath(QString path);
    void setIsWireshark(bool isWireshark);
    void setNeedFcs(bool needFcs);

    /* 03/07/17 CR DD start */
    void setNeedDiagnosticInfo(bool needDiagnosticInfo);
    /* 03/07/17 CR DD start */

    bool getIsOpen();

signals:

    void connectionLost();

public slots:
    /* 03/07/17 CR DD start */
    bool write(QByteArray packet, quint32 sec, quint32 usec, quint8 channel);
    /* 03/07/17 CR DD end */

private:

    static const QString WIRESHARK_SOCKET_NAME;
    static const quint32 WIRESHARK_CONNECTION_TIMEOUT;
    static const quint32 WIRESHARK_RESTART_TIMEOUT;
    static const quint8  PCAP_FCS_LEN;

    bool          isWireshark;
    bool          needFcs;
    bool          needDiagnosticInfo;
    QString       path;
    QString       serverName;

    QLocalServer  server;
    QIODevice    *iodev;
    bool isOpen;

    bool writeGlobalHeader();
    bool writePacketHeader(quint16 len, quint32 sec, quint32 usec, bool needFcs);

    bool initIoDevConnected();
    bool connectWireshark();
    bool waitWiresharkConnection(qint64 timeout);
    void disconnectIODev();

private slots:

    void wiresharkConnected();
    void wiresharkDisconnected();
};

#endif // PCAPLOGGER_H
