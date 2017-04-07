#include <QtSerialPort/QSerialPortInfo>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include "snifferwindow.h"
#include "ui_snifferwindow.h"

const QString SnifferWindow::PREFERENCES_NAME = "preferences";
const qint32 SnifferWindow::MAX_LOGS_VISIBLE  = 100;


SnifferWindow::SnifferWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SnifferWindow)
{
    ui->setupUi(this);


    initUiDefaults();
    initUiDestination();
    initUiPath();
    initUiRadioConfig();
    initUiDiagnosticInfo();
    addDevice();
    setUIState(SNIFFER_UI_INITIAL);


    connect(&this->devicesCmbComMapper, SIGNAL(mapped(int)),
            this, SLOT(deviceChanged(int)));
    connect(&this->devicesCmbChannelMapper, SIGNAL(mapped(int)), this, SLOT(channelChanged(int)));
    connect(&this->devicesBttnRemoveMapper, SIGNAL(mapped(int)), this, SLOT(removeDevice(int)));
    loadPreferences();
}


SnifferWindow::~SnifferWindow()
{
    disconnect(&this->devicesCmbComMapper, SIGNAL(mapped(int)),
            this, SLOT(deviceChanged(int)));
    disconnect(&this->devicesCmbChannelMapper, SIGNAL(mapped(int)), this, SLOT(channelChanged(int)));
    disconnect(&this->devicesBttnRemoveMapper, SIGNAL(mapped(int)), this, SLOT(removeDevice(int)));
    delete ui;
}


void SnifferWindow::destinationChanged()
{
    bool isWireshark = ui->rbWireshark->isChecked();

    logger.setIsWireshark(isWireshark);
    ui->lPath->setText(QString("<b>Specify path to %1</b>").arg(
                             isWireshark ? "Wireshark" : "Pcap file"));
    ui->lePath->setText(isWireshark ? defaultWiresharkPath : defaultPcapFilePath);
}


void SnifferWindow::pathChanged()
{
    logger.setPath(ui->lePath->text());
}

void SnifferWindow::deviceChanged(int deviceNumber)
{
    if (devices.size() <= deviceNumber || deviceNumber < 0)
        return;
    devices[deviceNumber]
            ->setPortName(deviceFields[deviceNumber]->cmbCom->currentData().toString());
}


void SnifferWindow::channelChanged(int deviceNumber)
{
    quint8 radioConfig = ui->cmbRadioConfig->currentIndex();
    quint8 offset = deviceFields[deviceNumber]->cmbChannel->currentIndex();

    if (devices.size() <= deviceNumber || deviceNumber < 0)
        return;

    devices[deviceNumber]
         ->setChannel(SnifferSerialDevice::SNIFFER_RADIO_CONFIGS[radioConfig].minChannel + offset);
}


void SnifferWindow::diagnosticInfoChanged()
{
    logger.setNeedDiagnosticInfo(ui->cbDiagnosticInfo->isChecked());
}


void SnifferWindow::initUiDefaults()
{
    defaultWiresharkPath = "";
    defaultPcapFilePath = "";
}


void SnifferWindow::initUiDestination()
{
    connect(ui->rbPcap, SIGNAL(toggled(bool)), this, SLOT(destinationChanged()));
    connect(ui->rbWireshark, SIGNAL(toggled(bool)), this, SLOT(destinationChanged()));
}


void SnifferWindow::initUiPath()
{
    connect(ui->lePath, SIGNAL(editingFinished()), this, SLOT(pathChanged()));
}

void SnifferWindow::initUiDevice(int deviceNumber)
{
    DeviceField* deviceField;

    if (deviceFields.size() <= deviceNumber)
        return;

    deviceField = deviceFields[deviceNumber];
    deviceField->cmbCom->clear();

    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        deviceField->cmbCom->addItem(QString("%1 (%2)").arg(info.description(), info.portName()),
                            QVariant(info.portName()));
    }

    if (deviceField->cmbCom->count())
    {
        deviceChanged(deviceNumber);
    }
}


void SnifferWindow::initUiRadioConfig()
{   
    ui->cmbRadioConfig->clear();

    for (int i = 0; i < SnifferSerialDevice::SNIFFER_RADIO_NUM_CONFIGS; i++)
    {
        ui->cmbRadioConfig->addItem(SnifferSerialDevice::SNIFFER_RADIO_CONFIGS[i].title);
    }
    ui->cmbRadioConfig->setCurrentIndex(0);

    connect(ui->cmbRadioConfig, SIGNAL(currentIndexChanged(int)),
            this, SLOT(initUiChannel(int)));
}

void SnifferWindow::initUiChannel(int radioConfig)
{
    for (int i = 0; i < deviceFields.size(); i++)
        initUiChannel(radioConfig, i);
}


void SnifferWindow::initUiChannel(int radioConfig, int deviceNumber)
{
    DeviceField* deviceField = deviceFields[deviceNumber];

    if (deviceFields.size() <= deviceNumber)
        return;

    deviceField->cmbChannel->clear();

    for (int i = SnifferSerialDevice::SNIFFER_RADIO_CONFIGS[radioConfig].minChannel;
         i <= SnifferSerialDevice::SNIFFER_RADIO_CONFIGS[radioConfig].maxChannel; i++)
    {
        QString ch = QString::number(i, 16);
        ch = ch.toUpper();

        /* Add zero to the one-number hexademical (0xA -> 0x0A) */
        if (i < 16)
        {
            ch = QString("0%1").arg(ch);
        }
        deviceField->cmbChannel->addItem(QString("0x%1 (%2)").arg(ch, QString::number(i, 10)));
    }
    deviceField->cmbChannel->setCurrentIndex(0);
    channelChanged(deviceNumber);
}


void SnifferWindow::initUiDiagnosticInfo()
{
    connect(ui->cbDiagnosticInfo, SIGNAL(clicked()), this, SLOT(diagnosticInfoChanged()));
}


void SnifferWindow::addDevice()
{
    int newDeviceNumber = deviceFields.size();
    DeviceField* deviceField = new DeviceField();

    devices.append(new SnifferSerialDevice());
    deviceFields.append(deviceField);
    initUiDevice(newDeviceNumber);
    initUiChannel(ui->cmbRadioConfig->currentIndex(), newDeviceNumber);
    ui->vlDevice->addLayout(deviceFields[deviceFields.size() - 1]);

    this->devicesCmbComMapper.setMapping(deviceField->cmbCom, newDeviceNumber);
    this->devicesCmbChannelMapper.setMapping(deviceField->cmbChannel, newDeviceNumber);
    this->devicesBttnRemoveMapper.setMapping(deviceField->bttnRemoveDevice, newDeviceNumber);

    connect(deviceField->cmbCom, SIGNAL(currentIndexChanged(int)),
            &this->devicesCmbComMapper, SLOT(map()));

    connect(deviceField->cmbChannel, SIGNAL(currentIndexChanged(int)),
            &this->devicesCmbChannelMapper, SLOT(map()));

    connect(deviceField->bttnRemoveDevice, SIGNAL(clicked(bool)),
            &this->devicesBttnRemoveMapper, SLOT(map()));
}

void SnifferWindow::removeLastDevice()
{
    DeviceField* lastDeviceField;

    if (devices.size() == 0)
        return;

    lastDeviceField = deviceFields[deviceFields.size() - 1];

    ui->vlDevice->removeItem(deviceFields[deviceFields.size() - 1]);

    disconnect(lastDeviceField->cmbCom, SIGNAL(currentIndexChanged(int)), &this->devicesCmbComMapper, SLOT(map()));
    disconnect(lastDeviceField->cmbChannel, SIGNAL(currentIndexChanged(int)), &this->devicesCmbChannelMapper, SLOT(map()));
    disconnect(lastDeviceField->bttnRemoveDevice, SIGNAL(currentIndexChanged(int)), &this->devicesBttnRemoveMapper, SLOT(map()));

    delete devices[devices.size() - 1];
    delete deviceFields[deviceFields.size() - 1];
    deviceFields.removeLast();
    devices.removeLast();
}

void SnifferWindow::removeDevice(int deviceNumber)
{
    DeviceField* currentDeviceField;
    DeviceField* temp;

    if (deviceNumber >= deviceFields.size())
        return;

    temp = deviceFields[deviceFields.size() - 1];
    deviceFields[deviceFields.size() - 1] = deviceFields[deviceNumber];
    deviceFields[deviceNumber] = temp;
    currentDeviceField = deviceFields[deviceNumber];

    removeLastDevice();

    if (deviceNumber == deviceFields.size() || deviceFields.size() == 0)
        return;
    this->devicesCmbComMapper.removeMappings(currentDeviceField->cmbCom);
    this->devicesCmbChannelMapper.removeMappings(currentDeviceField->cmbChannel);
    this->devicesBttnRemoveMapper.removeMappings(currentDeviceField->bttnRemoveDevice);
    this->devicesCmbComMapper.setMapping(currentDeviceField->cmbCom, deviceNumber);
    this->devicesCmbChannelMapper.setMapping(currentDeviceField->cmbChannel, deviceNumber);
    this->devicesBttnRemoveMapper.setMapping(currentDeviceField->bttnRemoveDevice, deviceNumber);
}

void SnifferWindow::on_bttnAddDevice_clicked()
{
    addDevice();
}

void SnifferWindow::on_bttnStart_clicked()
{
    if (uiState == SNIFFER_UI_INITIAL)
    {
        /* FIXME: choose appropriate SIGNAL for path instead of this crutch */
        pathChanged();
        startSniffer();
    }
    else if (uiState == SNIFFER_UI_SNIFFING)
    {
        pauseSniffer();
    }
    else if (uiState == SNIFFER_UI_PAUSED)
    {
        resumeSniffer();
    }
}


void SnifferWindow::on_bttnStop_clicked()
{
   stopSniffer();
}


void SnifferWindow::on_bttnBrowsePath_clicked()
{
    QFileDialog dialog(this);
    QString invitation = ui->rbWireshark->isChecked() ?
                "Specify the path to Wireshark" : "Specify the path to .pcap file";

    dialog.setFileMode(QFileDialog::AnyFile);
    dialog.setWindowTitle(invitation);
    if (dialog.exec())
    {
        QStringList pathes = dialog.selectedFiles();
        ui->lePath->setText(pathes[0]);
        logger.setPath(pathes[0]);
    }
}


void SnifferWindow::on_bttnUp_clicked()
{
    for (int i = 0; i < deviceFields.size(); i++)
        initUiDevice(i);
}


void SnifferWindow::on_bttnCancel_clicked()
{
    QApplication::quit();
}


void SnifferWindow::printLogMessage(QString msg)
{
    if (ui->teLogBrowser->document()->blockCount() == MAX_LOGS_VISIBLE)
    {
        ui->teLogBrowser->clear();
    }
    ui->teLogBrowser->append(msg);
}


void SnifferWindow::deviceErrorHandle(QString msg)
{
    printLogMessage(msg);
    stopSniffer();
}


void SnifferWindow::loggerErrorHandle()
{
    printLogMessage("Wireshark is disconnected");
    stopSniffer();
}


/*
 * File format (per line):
 * isWireshark, path, devices (separated by space), radio config, channels (separated by space), diagnosticInfo
 */
void SnifferWindow::loadPreferences()
{
    QFile pref(PREFERENCES_NAME);
    QTextStream in;

    if (!pref.exists())
    {
        return;
    }

    if (!pref.open(QIODevice::ReadOnly))
    {
        pref.remove();
        return;
    }

    in.setDevice(&pref);
    in.setCodec("UTF-8");

    for (int i = 0; i < SNIFFER_PREF_NUM; i++)
    {
        QString line = in.readLine();

        if (line.isNull())
        {
            break;
        }

        switch (i)
        {
        case SNIFFER_PREF_WIRESHARK:
        {
            bool isWireshark = !!line.toInt();

            ui->rbWireshark->setChecked(isWireshark);
            ui->rbPcap->setChecked(!isWireshark);

            destinationChanged();
        }
            break;
        case SNIFFER_PREF_WIRESHARK_PATH:
        {
            defaultWiresharkPath = line;
            if (ui->rbWireshark->isChecked())
            {
                ui->lePath->setText(line);
                pathChanged();
            }
        }
            break;
        case SNIFFER_PREF_PCAP_FILE_PATH:
        {
            defaultPcapFilePath = line;
            if (!ui->rbWireshark->isChecked())
            {
                ui->lePath->setText(line);
                pathChanged();
            }
        }
            break;
        case SNIFFER_PREF_DEVICE:
        {
            QStringList coms = line.split(" ", QString::SkipEmptyParts);
            for (int deviceNumber = 0; deviceNumber < coms.size(); deviceNumber++)
            {
                if (deviceNumber == deviceFields.size())
                    addDevice();
                int index = deviceFields[deviceNumber]->cmbCom->findData(coms[deviceNumber]);

                if (index != -1)
                {
                    deviceFields[deviceNumber]->cmbCom->setCurrentIndex(index);
                    deviceChanged(deviceNumber);
                }
            }
        }
            break;
        case SNIFFER_PREF_RADIO_CONFIG:
        {
            int radioConfig = line.toInt();

            ui->cmbRadioConfig->setCurrentIndex(radioConfig);
            initUiChannel(radioConfig);
        }
            break;
        case SNIFFER_PREF_CHANNEL:
        {
            QStringList channels = line.split(" ", QString::SkipEmptyParts);
            for (int deviceNumber = 0; deviceNumber < channels.size(); deviceNumber++)
            {
                if (deviceNumber == deviceFields.size())
                    addDevice();

                int channelIndex = channels[deviceNumber].toInt();
                deviceFields[deviceNumber]->cmbChannel->setCurrentIndex(channelIndex);
                channelChanged(deviceNumber);
            }
        }
            break;
        case SNIFFER_PREF_DIAGNOSTIC_INFO:
        {
            ui->cbDiagnosticInfo->setChecked(!!line.toInt());
            diagnosticInfoChanged();
        }
            break;
        }
    }

    pref.close();
}


void SnifferWindow::savePreferences()
{
    QFile pref(PREFERENCES_NAME);
    bool isWireshark;
    QString path;

    isWireshark = ui->rbWireshark->isChecked();
    path = ui->lePath->text();
    if (isWireshark)
    {
        defaultWiresharkPath = path;
    }
    else
    {
        defaultPcapFilePath = path;
    }

    if (pref.open(QIODevice::WriteOnly))
    {
        QTextStream out(&pref);

        out.setCodec("UTF-8");

        out << QString::number(isWireshark) << "\n";
        out << defaultWiresharkPath << "\n";
        out << defaultPcapFilePath << "\n";
        for (int i = 0; i < deviceFields.size(); i++)
            out << deviceFields[i]->cmbCom->currentData().toString() << " ";
        out << '\n';
        out << ui->cmbRadioConfig->currentIndex() << "\n";
        for (int i = 0; i < deviceFields.size(); i++)
            out << deviceFields[i]->cmbChannel->currentIndex() << " ";
        out << '\n';
        out << QString::number(ui->cbDiagnosticInfo->isChecked()) << "\n";

        pref.close();
    }
}

void SnifferWindow::setUIState(SnifferUIStateE state)
{
    this->uiState = state;

    switch (state)
    {
    case SNIFFER_UI_INITIAL:
        setInitialUIState();
        break;
    case SNIFFER_UI_STARTING:
        setStartingUIState();
        break;
    case SNIFFER_UI_SNIFFING:
        setSniffingUIState();
        break;
    case SNIFFER_UI_PAUSED:
        setPausedUIState();
        break;
    default:
        break;
    }
}


void SnifferWindow::setInitialUIState()
{
    ui->rbWireshark->setEnabled(true);
    ui->rbPcap->setEnabled(true);
    ui->lePath->setEnabled(true);
    ui->bttnBrowsePath->setEnabled(true);
    ui->bttnAddDevice->setEnabled(true);
    for (int i = 0; i < deviceFields.size(); i++)
    {
        deviceFields[i]->bttnRemoveDevice->setEnabled(true);
        deviceFields[i]->cmbCom->setEnabled(true);
        deviceFields[i]->cmbChannel->setEnabled(true);
    }
    ui->bttnUp->setEnabled(true);
    ui->cmbRadioConfig->setEnabled(true);
    ui->cbDiagnosticInfo->setEnabled(true);
    ui->bttnStart->setEnabled(true);
    ui->bttnStop->setEnabled(false);

    ui->bttnStart->setText("Start");
}


void SnifferWindow::setStartingUIState()
{
    ui->rbWireshark->setEnabled(false);
    ui->rbPcap->setEnabled(false);
    ui->lePath->setEnabled(false);
    ui->bttnBrowsePath->setEnabled(false);
    ui->bttnAddDevice->setEnabled(false);
    for (int i = 0; i < deviceFields.size(); i++)
    {
        deviceFields[i]->bttnRemoveDevice->setEnabled(false);
        deviceFields[i]->cmbCom->setEnabled(false);
        deviceFields[i]->cmbChannel->setEnabled(false);
    }
    ui->bttnUp->setEnabled(false);
    ui->cmbRadioConfig->setEnabled(false);
    ui->cbDiagnosticInfo->setEnabled(false);
    ui->bttnStart->setEnabled(false);
    ui->bttnStop->setEnabled(false);

    ui->bttnStart->setText("Starting...");
}


void SnifferWindow::setSniffingUIState()
{
    ui->rbWireshark->setEnabled(false);
    ui->rbPcap->setEnabled(false);
    ui->lePath->setEnabled(false);
    ui->bttnBrowsePath->setEnabled(false);
    ui->bttnAddDevice->setEnabled(false);
    for (int i = 0; i < deviceFields.size(); i++)
    {
        deviceFields[i]->bttnRemoveDevice->setEnabled(false);
        deviceFields[i]->cmbCom->setEnabled(false);
        deviceFields[i]->cmbChannel->setEnabled(true);
    }
    ui->bttnUp->setEnabled(false);
    ui->cmbRadioConfig->setEnabled(false);
    ui->cbDiagnosticInfo->setEnabled(true);
    ui->bttnStart->setEnabled(true);
    ui->bttnStop->setEnabled(true);

    ui->bttnStart->setText("Pause");
}


void SnifferWindow::setPausedUIState()
{
    ui->rbWireshark->setEnabled(false);
    ui->rbPcap->setEnabled(false);
    ui->lePath->setEnabled(false);
    ui->bttnBrowsePath->setEnabled(false);
    ui->bttnAddDevice->setEnabled(false);
    for (int i = 0; i < deviceFields.size(); i++)
    {
       deviceFields[i]->bttnRemoveDevice->setEnabled(false);
       deviceFields[i]->cmbCom->setEnabled(false);
       deviceFields[i]->cmbChannel->setEnabled(true);
    }
    ui->bttnUp->setEnabled(false);
    ui->cmbRadioConfig->setEnabled(false);
    ui->cbDiagnosticInfo->setEnabled(true);
    ui->bttnStart->setEnabled(true);
    ui->bttnStop->setEnabled(true);

    ui->bttnStart->setText("Resume");
}

void SnifferWindow::startSniffer()
{
    bool ret;

    savePreferences();
    setUIState(SNIFFER_UI_STARTING);

    ret = logger.open();

    if (!ret)
    {
        printLogMessage("Can't start pcap logger");
    }

    if (ret)
    {
        for (int i = 0; i < devices.size(); i++)
        {
            ret = devices[i]->open();
            if (!ret)
            {
                printLogMessage(QString("Failed to connect to sniffer at %1").arg(deviceFields[i]->cmbCom->currentData().toString()));
                break;
            }
        }
    }

    if (ret)
    {
        for (int i = 0; i < devices.size(); i++)
        {
            ret = devices[i]->start();

            if (!ret)
            {
                printLogMessage(QString("Failed to start sniffer at %1").arg(deviceFields[i]->cmbCom->currentData().toString()));
                break;
            }
        }
    }

    if (ret)
    {
        for (int i = 0; i < devices.size(); i++)
        {
            connect(devices[i], SIGNAL(snifferDeviceError(QString)),
                    this, SLOT(deviceErrorHandle(QString)));
            connect(devices[i], SIGNAL(snifferDevicePacket(QByteArray,quint32,quint32, quint8)),
                    &logger, SLOT(write(QByteArray,quint32,quint32, quint8)));
            connect(devices[i], SIGNAL(snifferDevicePacket(QByteArray,quint32,quint32)),
                    this, SLOT(logPacket(QByteArray,quint32,quint32, i)));
            connect(&logger, SIGNAL(connectionLost()), this, SLOT(loggerErrorHandle()));

            setUIState(SNIFFER_UI_SNIFFING);
        }
        printLogMessage("Sniffing...\n");
    }
    else
    {
        if (logger.getIsOpen())
        {
            logger.close();
        }

        for (int i = 0; i < devices.size(); i++)
        {
            if (devices[i]->isOpen())
            {
                devices[i]->close();
            }
        }

        setUIState(SNIFFER_UI_INITIAL);
    }
}


void SnifferWindow::pauseSniffer()
{
    for (int i = 0; i < devices.size(); i++)
        devices[i]->pause();
    setUIState(SNIFFER_UI_PAUSED);
    printLogMessage("Pause...\n");
}


void SnifferWindow::resumeSniffer()
{
    for (int i = 0; i < devices.size(); i++)
        devices[i]->start();
    setUIState(SNIFFER_UI_SNIFFING);
    printLogMessage("Resume...\n");
}


void SnifferWindow::stopSniffer()
{
    for (int i = 0; i < devices.size(); i++)
    {
        disconnect(devices[i], SIGNAL(snifferDeviceError(QString)),
                   this, SLOT(deviceErrorHandle(QString)));
        disconnect(devices[i], SIGNAL(snifferDevicePacket(QByteArray,quint32,quint32, quint8)),
                   &logger, SLOT(write(QByteArray,quint32,quint32, quint8)));
        disconnect(&logger, SIGNAL(connectionLost()), this, SLOT(loggerErrorHandle()));

        if (logger.getIsOpen())
        {
            logger.close();
        }
        if (devices[i]->isOpen())
        {
            devices[i]->stop();
            devices[i]->close();
        }
    }
    setUIState(SNIFFER_UI_INITIAL);
    ui->teLogBrowser->clear();
    printLogMessage("Stop...\n");
}


void SnifferWindow::logPacket(QByteArray packet, quint32 sec, quint32 usec, quint32 deviceNumber)
{
    quint64 calc = (quint64)sec * 1000000 + (quint64)usec - devices[deviceNumber]->getUsecOnStart();

    QString msg = QString("[%1:%2] %3 bytes: %4\n").arg(
                QString::number(calc / 1000000), QString::number(calc % 1000000),
                QString::number(packet.length()), SnifferSerialDevice::printDataHex(packet));

    printLogMessage(msg);
}

