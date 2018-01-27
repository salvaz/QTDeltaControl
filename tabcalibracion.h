#ifndef TABCALIBRACION_H
#define TABCALIBRACION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include "console.h"

class tabCalibracion : public QWidget
{
    Q_OBJECT
private:
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



public:
    explicit tabCalibracion(QWidget *parent = nullptr);
    void Habilitar (bool habil);
    void PonerDiagonalRod(QString diaRod);
    void PonerEndstopX (QString esX);
    void PonerEndstopY (QString esX);
    void PonerEndstopZ (QString esX);
    void PonerDiagRodA (QString esX);
    void PonerDiagRodB (QString esX);
    void PonerDiagRodC (QString esX);

signals:

public slots:
};

#endif // TABCALIBRACION_H
