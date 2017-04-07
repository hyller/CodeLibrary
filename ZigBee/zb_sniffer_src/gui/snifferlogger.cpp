#include "snifferlogger.h"

const QString SnifferLogger::SNIFFER_DEFAULT_LOG_NAME = "log.txt";


bool SnifferLogger::initLogger()
{
    return log->open(QFile::WriteOnly | QFile::Text);
}

SnifferLogger::SnifferLogger(QObject *parent) :
    QObject(parent)
{
    log = new QFile();
    log->setFileName(SNIFFER_DEFAULT_LOG_NAME);
}

SnifferLogger::~SnifferLogger()
{
    log->flush();
    log->close();
}

void SnifferLogger::writeLog(QString str)
{
    if (log->isOpen())
    {
        QTextStream out(log);
        out << str << "\n";
        out.flush();
    }
}
