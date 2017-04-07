#ifndef DEVICEFIELD_H
#define DEVICEFIELD_H


#include <QHBoxLayout>
#include <QComboBox>
#include <QPushButton>
namespace Ui {
  class DeviceField;
}

class DeviceField : public QHBoxLayout
{
public:
    DeviceField(QWidget* parent = 0):
        QHBoxLayout(parent)
    {
        cmbCom = new QComboBox();
        cmbChannel = new QComboBox();
        bttnRemoveDevice = new QPushButton();
        this->addWidget(cmbCom);
        this->addWidget(cmbChannel);
        this->addWidget(bttnRemoveDevice);
        bttnRemoveDevice->setText("Remove");
    }

    ~DeviceField()
    {
        delete cmbCom;
        delete cmbChannel;
        delete bttnRemoveDevice;
    }

    QComboBox* cmbCom;
    QComboBox* cmbChannel;
    QPushButton* bttnRemoveDevice;
};


#endif // DEVICEFIELD_H
