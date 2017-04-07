#ifndef SNIFFERWINDOW_H
#define SNIFFERWINDOW_H

#include <QMainWindow>
#include <QSignalMapper>

#include "snifferserialdevice.h"
#include "pcaplogger.h"
#include "devicefield.h"

namespace Ui {
class SnifferWindow;
}

class SnifferWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SnifferWindow(QWidget *parent = 0);
    ~SnifferWindow();

signals:

private slots:

    void destinationChanged();
    void pathChanged();

    void deviceChanged(int deviceNumber);
    void channelChanged(int deviceNumber);
    void diagnosticInfoChanged();
    void addDevice();
    void removeLastDevice();
    void removeDevice(int deviceNumber);

    void initUiDefaults();
    void initUiDestination();
    void initUiPath();
    void initUiRadioConfig();


    void initUiDevice(int deviceNumber);
    void initUiChannel(int radioConfig, int deviceNumber);
    void initUiChannel(int radioConfig);
    void initUiDiagnosticInfo();

    void on_bttnStart_clicked();
    void on_bttnStop_clicked();
    void on_bttnBrowsePath_clicked();
    void on_bttnUp_clicked();
    void on_bttnCancel_clicked();
    void on_bttnAddDevice_clicked();


    void printLogMessage(QString msg);

    void deviceErrorHandle(QString msg);
    void loggerErrorHandle();

private:

    enum SnifferUIStateE
    {
        SNIFFER_UI_INITIAL,
        SNIFFER_UI_STARTING,
        SNIFFER_UI_SNIFFING,
        SNIFFER_UI_PAUSED,

    };

    enum SnifferPreferencesE
    {
        SNIFFER_PREF_WIRESHARK,
        SNIFFER_PREF_WIRESHARK_PATH,
        SNIFFER_PREF_PCAP_FILE_PATH,
        SNIFFER_PREF_DEVICE,
        SNIFFER_PREF_RADIO_CONFIG,
        SNIFFER_PREF_CHANNEL,
        SNIFFER_PREF_DIAGNOSTIC_INFO,
        SNIFFER_PREF_NUM,
    };

    static const QString PREFERENCES_NAME;
    static const qint32 MAX_LOGS_VISIBLE;

    Ui::SnifferWindow *ui;
    SnifferUIStateE uiState;
    QString defaultWiresharkPath;
    QString defaultPcapFilePath;



    QSignalMapper devicesCmbChannelMapper;
    QSignalMapper devicesCmbComMapper;
    QSignalMapper devicesBttnRemoveMapper;
    QVector<SnifferSerialDevice*> devices;
    QVector<DeviceField*> deviceFields;


    PcapLogger          logger;

    void loadPreferences();
    void savePreferences();

    void setUIState(SnifferUIStateE state);
    void setInitialUIState();
    void setStartingUIState();
    void setSniffingUIState();
    void setPausedUIState();

    void startSniffer();
    void pauseSniffer();
    void resumeSniffer();
    void stopSniffer();

public slots:
    void logPacket(QByteArray packet, quint32 sec, quint32 usec, quint32 deviceNumber);
};

#endif // SNIFFERWINDOW_H
