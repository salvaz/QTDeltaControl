#ifndef TABCALIBRACION_H
#define TABCALIBRACION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QGroupBox>
#include <QLineEdit>
#include <QSettings>
#include <QPushButton>
#include <QSerialPort>
#include "console.h"

class tabCalibracion : public QWidget
{
    Q_OBJECT
private:
    QGroupBox *Box666;
    QLineEdit *EndstopX;
    QLineEdit *EndstopY;
    QLineEdit *EndstopZ;
    QLineEdit *DiagRodA;
    QLineEdit *DiagRodB;
    QLineEdit *DiagRodC;
    QLineEdit *AngleA;
    QLineEdit *AngleB;
    QLineEdit *AngleC;
    QLineEdit *RadioA;
    QLineEdit *RadioB;
    QLineEdit *RadioC;

    QLineEdit *DiagonalRod;
    QLineEdit *DeltaRadio;
    QLineEdit *SegmentosSegundo;
    QLineEdit *PrintableRadio;
    QLineEdit *RadioPrueba;
    QLineEdit *AlturaZ;
    QPushButton *BSetCalibracion;
    QPushButton *BGetCalibracion;

    QSerialPort *m_serial = nullptr;

public:
    explicit tabCalibracion(QWidget *parent = nullptr);
    void SetSerial (QSerialPort *miSerial);
    void Importar (QSettings &settings);
    void Exportar (QSettings &settings);
    void Habilitar (bool habil);
    void PonerDiagonalRod(QString diaRod);
    void PonerDeltaRadio (QString esX);
    void PonerSegmentosSegundo (QString esX);
    void PonerPrintRadio (QString esX);
    void PonerRadioPrueba (QString esX);
    void PonerAlturaZ (QString esX);
    void PonerRadioA (QString esX);
    void PonerRadioB (QString esX);
    void PonerRadioC (QString esX);

    void PonerEndstopX (QString esX);
    void PonerEndstopY (QString esX);
    void PonerEndstopZ (QString esX);
    void PonerDiagRodA (QString esX);
    void PonerDiagRodB (QString esX);
    void PonerDiagRodC (QString esX);
    void PonerAnguloA (QString esX);
    void PonerAnguloB (QString esX);
    void PonerAnguloC (QString esX);

signals:

private slots:
    void writeData(const QByteArray &data);
    void SetM666 (void);
    void GetM666 (void);

};

#endif // TABCALIBRACION_H
