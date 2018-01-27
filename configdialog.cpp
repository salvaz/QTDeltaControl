#include "configdialog.h"

#include <QIntValidator>
#include <QLineEdit>
#include <QSerialPortInfo>

static const char blankString[] = QT_TRANSLATE_NOOP("SettingsDialog", "N/A");

void ConfigDialog::CrearDialogo()
{
    setGeometry(0,0,281,262);
    setWindowTitle("Configurar Puerto");
    gridLayout_3=new QGridLayout(this);
    gridLayout_3->addWidget(selectBox=new QGroupBox(tr("Elige puerto serie"),this),0,0);
    gridLayout=new QGridLayout(selectBox);
    gridLayout->addWidget(serialPortInfoListBox=new QComboBox(this),0,0);
    gridLayout->addWidget(descriptionLabel=new QLabel(tr("Descripcion:"),this),1,0);
    gridLayout->addWidget(manufacturerLabel=new QLabel(tr("Creador:"),this),2,0);
    gridLayout->addWidget(serialNumberLabel=new QLabel(tr("Numero de serie:"),this),3,0);
    gridLayout->addWidget(locationLabel=new QLabel(tr("Localizacion:"),this),4,0);
    gridLayout->addWidget(vidLabel=new QLabel(tr("Vendedor ID:"),this),5,0);
    gridLayout->addWidget(pidLabel=new QLabel(tr("Producto ID:"),this),6,0);

    gridLayout_3->addWidget(parametersBox=new QGroupBox(tr("Elige parametros"),this),0,1);
    gridLayout_2=new QGridLayout(parametersBox);
    gridLayout_2->addWidget(baudRateLabel=new QLabel(tr("BaudRate:"),this),0,0);
    gridLayout_2->addWidget(baudRateBox=new QComboBox(this),0,1);
    gridLayout_2->addWidget(dataBitsLabel=new QLabel(tr("Data bits:"),this),1,0);
    gridLayout_2->addWidget(dataBitsBox=new QComboBox(this),1,1);
    gridLayout_2->addWidget(parityLabel=new QLabel(tr("Parity:"),this),2,0);
    gridLayout_2->addWidget(parityBox=new QComboBox(this),2,1);
    gridLayout_2->addWidget(stopBitsLabel=new QLabel(tr("Stop bits:"),this),3,0);
    gridLayout_2->addWidget(stopBitsBox=new QComboBox(this),3,1);
    gridLayout_2->addWidget(flowControlLabel=new QLabel(tr("Flow control:"),this),4,0);
    gridLayout_2->addWidget(flowControlBox=new QComboBox(this),4,1);

    gridLayout_3->addWidget(additionalOptionsGroupBox=new QGroupBox(tr("Parametros adicionales"),this),1,0,1,0);
    verticalLayout=new QVBoxLayout(additionalOptionsGroupBox);
    verticalLayout->addWidget(localEchoCheckBox=new QCheckBox(tr("Local echo:"),this));
        localEchoCheckBox->setChecked(true);


    gridLayout_3->addLayout(horizontalLayout=new QHBoxLayout(),2,0,2,0);
    horizontalLayout->addStretch();
//    horizontalLayout->addSpacerItem((horizontalSpacer= new QSpacerItem(96,20)));

    horizontalLayout->addWidget(applyButton=new QPushButton(tr("Aplicar"),this));
}

ConfigDialog::ConfigDialog(QWidget *parent) :
    QDialog(parent)
//    ,m_intValidator(new QIntValidator(0, 4000000, this))
{
    QPoint parentpos;
    CrearDialogo();
    baudRateBox->setInsertPolicy(QComboBox::NoInsert);
    connect(applyButton, &QPushButton::clicked,
            this, &ConfigDialog::apply);
    connect(serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ConfigDialog::showPortInfo);

    connect(baudRateBox,  QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ConfigDialog::checkCustomBaudRatePolicy);
    connect(serialPortInfoListBox, QOverload<int>::of(&QComboBox::currentIndexChanged),
            this, &ConfigDialog::checkCustomDevicePathPolicy);

    fillPortsParameters();
    fillPortsInfo();

    updateSettings();

    parentpos=parent->pos();
    parentpos.setX(parentpos.x()+(parent->width()-width())/2);
    parentpos.setY(parentpos.y()+(parent->height()-height())/2);
    move(parentpos);
    setModal(true);
    setVisible(false);
}

void ConfigDialog::apply()
{
    updateSettings();
    hide();
}

void ConfigDialog::checkCustomBaudRatePolicy(int idx)
{
    const bool isCustomBaudRate = !baudRateBox->itemData(idx).isValid();
    baudRateBox->setEditable(isCustomBaudRate);
    if (isCustomBaudRate) {
        baudRateBox->clearEditText();
        QLineEdit *edit = baudRateBox->lineEdit();
        edit->setValidator(m_intValidator);
    }
}

void ConfigDialog::checkCustomDevicePathPolicy(int idx)
{
    const bool isCustomPath = !serialPortInfoListBox->itemData(idx).isValid();
    serialPortInfoListBox->setEditable(isCustomPath);
    if (isCustomPath)
        serialPortInfoListBox->clearEditText();
}

ConfigDialog::Settings ConfigDialog::settings() const
{
    return m_currentSettings;
}

void ConfigDialog::showPortInfo(int idx)
{
    if (idx == -1)
        return;

    const QStringList list = serialPortInfoListBox->itemData(idx).toStringList();
    descriptionLabel->setText(tr("Description: %1").arg(list.count() > 1 ? list.at(1) : tr(blankString)));
    manufacturerLabel->setText(tr("Manufacturer: %1").arg(list.count() > 2 ? list.at(2) : tr(blankString)));
    serialNumberLabel->setText(tr("Serial number: %1").arg(list.count() > 3 ? list.at(3) : tr(blankString)));
    locationLabel->setText(tr("Location: %1").arg(list.count() > 4 ? list.at(4) : tr(blankString)));
    vidLabel->setText(tr("Vendor Identifier: %1").arg(list.count() > 5 ? list.at(5) : tr(blankString)));
    pidLabel->setText(tr("Product Identifier: %1").arg(list.count() > 6 ? list.at(6) : tr(blankString)));
}

void ConfigDialog::fillPortsParameters()
{
    baudRateBox->addItem(QStringLiteral("9600"), QSerialPort::Baud9600);
    baudRateBox->addItem(QStringLiteral("19200"), QSerialPort::Baud19200);
    baudRateBox->addItem(QStringLiteral("38400"), QSerialPort::Baud38400);
    baudRateBox->addItem(QStringLiteral("115200"), QSerialPort::Baud115200);
    baudRateBox->addItem(tr("Custom"));

    dataBitsBox->addItem(QStringLiteral("5"), QSerialPort::Data5);
    dataBitsBox->addItem(QStringLiteral("6"), QSerialPort::Data6);
    dataBitsBox->addItem(QStringLiteral("7"), QSerialPort::Data7);
    dataBitsBox->addItem(QStringLiteral("8"), QSerialPort::Data8);
    dataBitsBox->setCurrentIndex(3);

    parityBox->addItem(tr("None"), QSerialPort::NoParity);
    parityBox->addItem(tr("Even"), QSerialPort::EvenParity);
    parityBox->addItem(tr("Odd"), QSerialPort::OddParity);
    parityBox->addItem(tr("Mark"), QSerialPort::MarkParity);
    parityBox->addItem(tr("Space"), QSerialPort::SpaceParity);

    stopBitsBox->addItem(QStringLiteral("1"), QSerialPort::OneStop);
#ifdef Q_OS_WIN
    stopBitsBox->addItem(tr("1.5"), QSerialPort::OneAndHalfStop);
#endif
    stopBitsBox->addItem(QStringLiteral("2"), QSerialPort::TwoStop);

    flowControlBox->addItem(tr("None"), QSerialPort::NoFlowControl);
    flowControlBox->addItem(tr("RTS/CTS"), QSerialPort::HardwareControl);
    flowControlBox->addItem(tr("XON/XOFF"), QSerialPort::SoftwareControl);
}

void ConfigDialog::fillPortsInfo()
{
    serialPortInfoListBox->clear();
    QString description;
    QString manufacturer;
    QString serialNumber;
    const auto infos = QSerialPortInfo::availablePorts();
    for (const QSerialPortInfo &info : infos) {
        QStringList list;
        description = info.description();
        manufacturer = info.manufacturer();
        serialNumber = info.serialNumber();
        list << info.portName()
             << (!description.isEmpty() ? description : blankString)
             << (!manufacturer.isEmpty() ? manufacturer : blankString)
             << (!serialNumber.isEmpty() ? serialNumber : blankString)
             << info.systemLocation()
             << (info.vendorIdentifier() ? QString::number(info.vendorIdentifier(), 16) : blankString)
             << (info.productIdentifier() ? QString::number(info.productIdentifier(), 16) : blankString);

        serialPortInfoListBox->addItem(list.first(), list);
    }

    serialPortInfoListBox->addItem(tr("Custom"));
}

void ConfigDialog::updateSettings()
{
    m_currentSettings.name = serialPortInfoListBox->currentText();

    if (baudRateBox->currentIndex() == 4) {
        m_currentSettings.baudRate = baudRateBox->currentText().toInt();
    } else {
        m_currentSettings.baudRate = static_cast<QSerialPort::BaudRate>(
                    baudRateBox->itemData(baudRateBox->currentIndex()).toInt());
    }
    m_currentSettings.stringBaudRate = QString::number(m_currentSettings.baudRate);

    m_currentSettings.dataBits = static_cast<QSerialPort::DataBits>(
                dataBitsBox->itemData(dataBitsBox->currentIndex()).toInt());
    m_currentSettings.stringDataBits = dataBitsBox->currentText();

    m_currentSettings.parity = static_cast<QSerialPort::Parity>(
                parityBox->itemData(parityBox->currentIndex()).toInt());
    m_currentSettings.stringParity = parityBox->currentText();

    m_currentSettings.stopBits = static_cast<QSerialPort::StopBits>(
                stopBitsBox->itemData(stopBitsBox->currentIndex()).toInt());
    m_currentSettings.stringStopBits = stopBitsBox->currentText();

    m_currentSettings.flowControl = static_cast<QSerialPort::FlowControl>(
                flowControlBox->itemData(flowControlBox->currentIndex()).toInt());
    m_currentSettings.stringFlowControl = flowControlBox->currentText();

    m_currentSettings.localEchoEnabled = localEchoCheckBox->isChecked();
}
