#include "mainwindow.h"
#include <QtWidgets>

void MainWindow::CrearVentana()
{
    MiTab=new QTabWidget(this);
    setCentralWidget(MiTab);

    MiTabComunicacion=new TabComunicacion(this);
    MiTab->addTab(MiTabComunicacion,tr("Comunicacion"));
    MiTabCalibracion=new tabCalibracion(this);
    MiTab->addTab(MiTabCalibracion,tr("Calibracion"));
//    QWidget *widget = new QWidget;
//    setCentralWidget(widget);

//    QWidget *topFiller = new QWidget;
//    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    infoLabel = new QLabel(tr("Choose a menu option, or right-click to invoke a context menu"));
//    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
//    infoLabel->setAlignment(Qt::AlignCenter);

//    QWidget *bottomFiller = new QWidget;
//    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

//    QVBoxLayout *layout = new QVBoxLayout;
//    layout->setMargin(5);
//    layout->addWidget(topFiller);
//    layout->addWidget(m_console);
//    layout->addWidget(bottomFiller);
//    widget->setLayout(layout);

    CrearAcciones();
    CrearMenus();

    setWindowTitle(tr("3D Printer Control"));
    setMinimumSize(160, 160);
    resize(480, 320);

}

void MainWindow::CrearAcciones()
{
    QPixmap ConfigPix("://iconos//barra//settings");
    SMConfiguracion=new QAction(QIcon(ConfigPix),tr("&Configurar puerto"),this);
    SMConfiguracion->setShortcuts(QKeySequence::Preferences);
    SMConfiguracion->setStatusTip(tr("Configurar puerto USB"));
    QPixmap exitPix("://iconos//barra//exit");
    SMSalir= new QAction(QIcon(exitPix),tr("&Salir"), this);
    SMSalir->setShortcuts(QKeySequence::Close);
    SMSalir->setStatusTip(tr("Salir del programa."));
    QPixmap conectarPix("://iconos//barra//conectar");
    actionConnect= new QAction(QIcon(conectarPix),tr("&Conectar impresora"), this);
    actionConnect->setShortcuts(QKeySequence::Open);
    actionConnect->setStatusTip(tr("Conectar impresora."));
    QPixmap desconectarPix("://iconos//barra//desconectar");
    actionDisconnect= new QAction(QIcon(desconectarPix),tr("&Desconectar impresora"), this);
    actionDisconnect->setShortcuts(QKeySequence::Cancel);
    actionDisconnect->setStatusTip(tr("Desconectar impresora."));
    QPixmap homePix("://iconos//barra//home");
    actionHome= new QAction(QIcon(homePix),tr("&LLevar los ejes al origen"), this);
    actionHome->setShortcuts(QKeySequence::MoveToStartOfDocument);
    actionHome->setStatusTip(tr("Mover los ejes al origen."));
    QPixmap emergenciaPix("://iconos//barra//emergencia");
    actionEmergencia= new QAction(QIcon(emergenciaPix),tr("&Emergencia STOP"), this);
    actionEmergencia->setShortcuts(QKeySequence::Backspace);
    actionEmergencia->setStatusTip(tr("Emergencia STOP."));

    MiTabComunicacion->Habilitar(false);
    MiTabCalibracion->Habilitar(false);
//    m_console->setEnabled(false);
    actionConnect->setEnabled(true);
    actionDisconnect->setEnabled(false);
    actionHome->setEnabled(false);
    actionEmergencia->setEnabled(false);
    SMConfiguracion->setEnabled(true);
  }

void MainWindow::CrearMenus()
{
     MArchivo = menuBar()->addMenu(tr("&Archivo"));
     MiToolBar=addToolBar(tr("Archivo"));
     MiToolBar->addAction(actionConnect);
     MiToolBar->addAction(actionDisconnect);
     MiToolBar->addAction(SMConfiguracion);
     MArchivo->addAction(actionConnect);
     MArchivo->addAction(actionDisconnect);
     MArchivo->addSeparator();
     MArchivo->addAction(SMConfiguracion);
     MArchivo->addSeparator();
     MArchivo->addAction(SMSalir);
     MComandos = menuBar()->addMenu(tr("&Comandos"));
     MComandos->addAction(actionHome);
     MiToolBar->addAction(actionHome);
     MComandos->addAction(actionEmergencia);
     MiToolBar->addAction(actionEmergencia);

/*        editMenu = menuBar()->addMenu(tr("&Edit"));
        editMenu->addAction(undoAct);
        editMenu->addAction(redoAct);
        editMenu->addSeparator();
        editMenu->addAction(cutAct);
        editMenu->addAction(copyAct);
        editMenu->addAction(pasteAct);
        editMenu->addSeparator();

        helpMenu = menuBar()->addMenu(tr("&Help"));
        helpMenu->addAction(aboutAct);
        helpMenu->addAction(aboutQtAct);
*/
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//    m_console=new Console(this);
//    m_console->setEnabled(false);
    Mensajes.clear();

    CrearVentana();
    DialogoConfigurar=new ConfigDialog(this);
    m_serial=new QSerialPort(this);

    initActionsConnections();

    connect(m_serial, &QSerialPort::errorOccurred, this, &MainWindow::handleError);
    connect(m_serial, &QSerialPort::readyRead, this, &MainWindow::readData);
//connect(m_console, &Console::getData, this, &MainWindow::writeData);

}

MainWindow::~MainWindow()
{
    delete DialogoConfigurar;
}

void MainWindow::NuevoArchivo()
{

}

void MainWindow::ConfigurarPuerto()
{
    DialogoConfigurar->show();
}

void MainWindow::SalirPrograma()
{
    qApp->quit();
}

void MainWindow::openSerialPort()
{
    const ConfigDialog::Settings p = DialogoConfigurar->settings();
    m_serial->setPortName(p.name);
    m_serial->setBaudRate(p.baudRate);
    m_serial->setDataBits(p.dataBits);
    m_serial->setParity(p.parity);
    m_serial->setStopBits(p.stopBits);
    m_serial->setFlowControl(p.flowControl);
    if (m_serial->open(QIODevice::ReadWrite)) {
        MiTabComunicacion->Habilitar(true);
        MiTabComunicacion->HabilitarEcho(p.localEchoEnabled);
        MiTabCalibracion->Habilitar(true);
//        m_console->setEnabled(true);
//        m_console->setLocalEchoEnabled(p.localEchoEnabled);
        actionConnect->setEnabled(false);
        actionDisconnect->setEnabled(true);
        actionHome->setEnabled(true);
        actionEmergencia->setEnabled(true);
        SMConfiguracion->setEnabled(false);
//        showStatusMessage(tr("Connected to %1 : %2, %3, %4, %5, %6")
//                          .arg(p.name).arg(p.stringBaudRate).arg(p.stringDataBits)
 //                         .arg(p.stringParity).arg(p.stringStopBits).arg(p.stringFlowControl));
    } else {
        QMessageBox::critical(this, tr("Error"), m_serial->errorString());

        showStatusMessage(tr("Open error"));
    }
}

void MainWindow::closeSerialPort()
{
    if (m_serial->isOpen())
        m_serial->close();
    MiTabComunicacion->Habilitar(false);
    MiTabCalibracion->Habilitar(false);
//    m_console->setEnabled(false);
    actionConnect->setEnabled(true);
    actionDisconnect->setEnabled(false);
    actionHome->setEnabled(false);
    actionEmergencia->setEnabled(false);
    SMConfiguracion->setEnabled(true);
//    showStatusMessage(tr("Disconnected"));
}

void MainWindow::about()
{
    QMessageBox::about(this, tr("About Simple Terminal"),
                       tr("The <b>Simple Terminal</b> example demonstrates how to "
                          "use the Qt Serial Port module in modern GUI applications "
                          "using Qt, with a menu bar, toolbars, and a status bar."));
}

void MainWindow::writeData(const QByteArray &data)
{
    m_serial->write(data);
}

void MainWindow::readData()
{
    const QByteArray data = m_serial->readAll();
    InterpretarDatos(data);
    MiTabComunicacion->PresentarDatos(data);
}

void MainWindow::handleError(QSerialPort::SerialPortError error)
{
    if (error == QSerialPort::ResourceError) {
        QMessageBox::critical(this, tr("Critical Error"), m_serial->errorString());
        closeSerialPort();
    }
}

void MainWindow::initActionsConnections()
{
    connect(actionConnect, &QAction::triggered, this, &MainWindow::openSerialPort);
    connect(actionDisconnect, &QAction::triggered, this, &MainWindow::closeSerialPort);
    connect(actionHome, &QAction::triggered, this, &MainWindow::G28Home);
    connect(actionEmergencia, &QAction::triggered, this, &MainWindow::M112Emergencia);
    connect(SMConfiguracion,&QAction::triggered,this,&MainWindow::ConfigurarPuerto);
    connect(SMSalir, &QAction::triggered, this, &MainWindow::SalirPrograma);
//    connect(m_ui->actionQuit, &QAction::triggered, this, &MainWindow::close);
//    connect(m_ui->actionConfigure, &QAction::triggered, m_settings, &SettingsDialog::show);
//    connect(actionClear, &QAction::triggered, m_console, &Console::clear);
//    connect(m_ui->actionAbout, &QAction::triggered, this, &MainWindow::about);
//    connect(m_ui->actionAboutQt, &QAction::triggered, qApp, &QApplication::aboutQt);
}

void MainWindow::showStatusMessage(const QString &message)
{
    m_status->setText(message);
}

void MainWindow::InterpretarDatos(QByteArray data)
{
    int longi,finlinea;
    QString Linea;

    Mensajes.append(data);
    while (Mensajes.indexOf(10,0)!=-1)
    {
        finlinea=Mensajes.indexOf(10,0)+1;
        longi=Mensajes.length();
        Linea=Mensajes.left(finlinea-1);
        InterpretarLinea(Linea);
        Mensajes=Mensajes.right(longi-finlinea);
    }
}

void MainWindow::InterpretarLinea(QString Linea)
{
    int posi,fin;

    if (Linea.indexOf("M666",0,Qt::CaseInsensitive)!=-1)
    {
        if ((posi=Linea.indexOf("D",0,Qt::CaseInsensitive))!=-1)
        {
            fin=Linea.indexOf(" ",posi);
            if (fin==-1) fin=Linea.length();
            fin=fin-posi-1;
            MiTabCalibracion->PonerDiagonalRod(Linea.mid(posi+1,fin));
        }
        if ((posi=Linea.indexOf("X",0,Qt::CaseInsensitive))!=-1)
        {
            fin=Linea.indexOf(" ",posi);
            if (fin==-1) fin=Linea.length();
            fin=fin-posi-1;
            MiTabCalibracion->PonerEndstopX(Linea.mid(posi+1,fin));
        }
        if ((posi=Linea.indexOf("Y",0,Qt::CaseInsensitive))!=-1)
        {
            fin=Linea.indexOf(" ",posi);
            if (fin==-1) fin=Linea.length();
            fin=fin-posi-1;
            MiTabCalibracion->PonerEndstopY(Linea.mid(posi+1,fin));
        }
        if ((posi=Linea.indexOf("Z",0,Qt::CaseInsensitive))!=-1)
        {
            fin=Linea.indexOf(" ",posi);
            if (fin==-1) fin=Linea.length();
            fin=fin-posi-1;
            MiTabCalibracion->PonerEndstopZ(Linea.mid(posi+1,fin));
        }
    }
}

void MainWindow::G28Home()
{
    QString mensaje;
    QByteArray data;

    mensaje="G28";
    mensaje.push_back(QChar(13));
    data=mensaje.toLatin1();
    writeData(data);
}

void MainWindow::M112Emergencia()
{
    QString mensaje;
    QByteArray data;

    mensaje="M112";
    mensaje.push_back(QChar(13));
    data=mensaje.toLatin1();
    writeData(data);
}
