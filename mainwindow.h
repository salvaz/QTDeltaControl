#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <configdialog.h>
#include <QSerialPort>
#include <console.h>
#include "tabcomunicacion.h"
#include "tabcalibracion.h"


class QAction;
class QActionGroup;
class QLabel;
class QMenu;
class QVBoxLayout;

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();
protected:
#ifndef QT_NO_CONTEXTMENU
//    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU
private slots:
    void NuevoArchivo ();

    void ConfigurarPuerto();
    void SalirPrograma ();
    void G28Home ();
    void M112Emergencia ();

private slots:
    void openSerialPort();
    void closeSerialPort();
    void about();
    void writeData(const QByteArray &data);
    void readData();

    void handleError(QSerialPort::SerialPortError error);

private:
    void initActionsConnections();
private:
    void CrearVentana (void);
    void CrearAcciones();
    void CrearMenus();
    void fillPortsParameters();
    void fillPortsInfo();
    QByteArray Mensajes;
    void InterpretarDatos (QByteArray data);
    void InterpretarLinea (QString Linea);
    void InterpretarM666 (QString Linea);
    QString BuscarValor (QString Linea,QString valor);
    QTabWidget *MiTab;
    TabComunicacion *MiTabComunicacion;
    tabCalibracion *MiTabCalibracion;
    QLabel *infoLabel;
    QVBoxLayout *layout;
    QMenu *MArchivo;
    QMenu *MComandos;
    QToolBar *MiToolBar;
    QActionGroup *AlinearGrupo;
    QAction *SMNuevoArchivo;
    QAction *SMConfiguracion;
    QAction *SMSalir;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionHome;
    QAction *actionEmergencia;

    ConfigDialog *DialogoConfigurar;
    void showStatusMessage(const QString &message);

    QLabel *m_status = nullptr;
//    Console *m_console = nullptr;
    QSerialPort *m_serial = nullptr;

};

#endif // MAINWINDOW_H
