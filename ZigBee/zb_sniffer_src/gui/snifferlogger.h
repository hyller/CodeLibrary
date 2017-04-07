#ifndef SNIFFERLOGGER_H
#define SNIFFERLOGGER_H

#include <QObject>
#include <QFile>
#include <QTextStream>

class SnifferLogger : public QObject
{
    Q_OBJECT
public:
    static const QString SNIFFER_DEFAULT_LOG_NAME;
    explicit SnifferLogger(QObject *parent = 0);
    bool initLogger();
    void writeLog(QString str);
    ~SnifferLogger();

signals:

public slots:

private:
    QFile *log;
};

#endif // SNIFFERLOGGER_H
