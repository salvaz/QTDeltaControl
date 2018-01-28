#include "tabcalibracion.h"
#include <QLabel>

tabCalibracion::tabCalibracion(QWidget *parent) : QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    //test=new QPushButton("test",this);
    QGridLayout *g1=new QGridLayout(this);
    QGridLayout *g2=new QGridLayout(this);
    QGridLayout *g3=new QGridLayout(this);
    QGridLayout *g4=new QGridLayout(this);
    QWidget *w1=new QWidget(this);
    QWidget *w2=new QWidget(this);
    QWidget *w3=new QWidget(this);
    QWidget *w4=new QWidget(this);
    w1->setLayout(g1);
    w2->setLayout(g2);
    w3->setLayout(g3);
    w4->setLayout(g4);

    QLabel *LEndstopX=new QLabel(tr("Endstop X (mm) :"));
    g1->addWidget(LEndstopX,0,2);
    EndstopX=new QLineEdit("0",this);
    g1->addWidget(EndstopX,0,3);
    QLabel *LEndstopY=new QLabel(tr("Endstop Y (mm) :"));
    g1->addWidget(LEndstopY,1,2);
    EndstopY=new QLineEdit("0",this);
    g1->addWidget(EndstopY,1,3);
    QLabel *LEndstopZ=new QLabel(tr("Endstop Z (mm) :"));
    g1->addWidget(LEndstopZ,2,2);
    EndstopZ=new QLineEdit("0",this);
    g1->addWidget(EndstopZ,2,3);
    QLabel *LDiagRodA=new QLabel(tr("Diagonal Rod A (mm) :"));
    g1->addWidget(LDiagRodA,3,2);
    DiagRodA=new QLineEdit("0",this);
    g1->addWidget(DiagRodA,3,3);
    QLabel *LDiagRodB=new QLabel(tr("Diagonal Rod B (mm) :"));
    g1->addWidget(LDiagRodB,4,2);
    DiagRodB=new QLineEdit("0",this);
    g1->addWidget(DiagRodB,4,3);
    QLabel *LDiagRodC=new QLabel(tr("Diagonal Rod C (mm) :"));
    g1->addWidget(LDiagRodC,5,2);
    DiagRodC=new QLineEdit("0",this);
    g1->addWidget(DiagRodC,5,3);
    QLabel *LAngleA=new QLabel(tr("Angulo torre A (º) :"));
    g1->addWidget(LAngleA,6,2);
    AngleA=new QLineEdit("0",this);
    g1->addWidget(AngleA,6,3);
    QLabel *LAngleB=new QLabel(tr("Angulo torre B (º) :"));
    g1->addWidget(LAngleB,7,2);
    AngleB=new QLineEdit("0",this);
    g1->addWidget(AngleB,7,3);
    QLabel *LAngleC=new QLabel(tr("Angulo torre C (º) :"));
    g1->addWidget(LAngleC,8,2);
    AngleC=new QLineEdit("0",this);
    g1->addWidget(AngleC,8,3);

    QLabel *LDiagonalRod=new QLabel(tr("Diagonal Rod (mm) :"));
    g1->addWidget(LDiagonalRod,0,0);
    DiagonalRod=new QLineEdit("0",this);
    g1->addWidget(DiagonalRod,0,1);
    QLabel *LDeltaRadio=new QLabel(tr("Delta Radio (mm) :"));
    g1->addWidget(LDeltaRadio,1,0);
    DeltaRadio=new QLineEdit("0",this);
    g1->addWidget(DeltaRadio,1,1);
    QLabel *LSegSeg=new QLabel(tr("Segmentos por segundo :"));
    g1->addWidget(LSegSeg,2,0);
    SegmentosSegundo=new QLineEdit("0",this);
    g1->addWidget(SegmentosSegundo,2,1);
    QLabel *LPrintRadio=new QLabel(tr("Printable Radio (mm) :"));
    g1->addWidget(LPrintRadio,3,0);
    PrintableRadio=new QLineEdit("0",this);
    g1->addWidget(PrintableRadio,3,1);
    QLabel *LRadioPrueba=new QLabel(tr("Radio max calibrar (mm) :"));
    g1->addWidget(LRadioPrueba,4,0);
    RadioPrueba=new QLineEdit("0",this);
    g1->addWidget(RadioPrueba,4,1);
    QLabel *LAlturaZ=new QLabel(tr("Altura Z (mm) :"));
    g1->addWidget(LAlturaZ,5,0);
    AlturaZ=new QLineEdit("0",this);
    g1->addWidget(AlturaZ,5,1);
    QLabel *LRadioA=new QLabel(tr("Radio torre A (mm) :"));
    g1->addWidget(LRadioA,6,0);
    RadioA=new QLineEdit("0",this);
    g1->addWidget(RadioA,6,1);
    QLabel *LRadioB=new QLabel(tr("Radio torre B (mm) :"));
    g1->addWidget(LRadioB,7,0);
    RadioB=new QLineEdit("0",this);
    g1->addWidget(RadioB,7,1);
    QLabel *LRadioC=new QLabel(tr("Radio torre C (mm) :"));
    g1->addWidget(LRadioC,8,0);
    RadioC=new QLineEdit("0",this);
    g1->addWidget(RadioC,8,1);

    layout->addWidget(w1);
    layout->addWidget(w2);
    layout->addWidget(w4);
    layout->addWidget(w3);
    setLayout(layout);

}

void tabCalibracion::Habilitar(bool habil)
{
    EndstopX->setEnabled(habil);
    EndstopY->setEnabled(habil);
    EndstopZ->setEnabled(habil);
    DiagRodA->setEnabled(habil);
    DiagRodB->setEnabled(habil);
    DiagRodC->setEnabled(habil);
    AngleA->setEnabled(habil);
    AngleB->setEnabled(habil);
    AngleC->setEnabled(habil);
    DiagonalRod->setEnabled(habil);
    DeltaRadio->setEnabled(habil);
    SegmentosSegundo->setEnabled(habil);
    PrintableRadio->setEnabled(habil);
    RadioPrueba->setEnabled(habil);
    AlturaZ->setEnabled(habil);
    RadioA->setEnabled(habil);
    RadioB->setEnabled(habil);
    RadioC->setEnabled(habil);
}

void tabCalibracion::PonerDiagonalRod(QString diaRod)
{
    DiagonalRod->setText(diaRod);
}

void tabCalibracion::PonerDeltaRadio(QString esX)
{
    DeltaRadio->setText(esX);
}

void tabCalibracion::PonerSegmentosSegundo(QString esX)
{
    SegmentosSegundo->setText(esX);
}

void tabCalibracion::PonerPrintRadio(QString esX)
{
    PrintableRadio->setText(esX);
}

void tabCalibracion::PonerRadioPrueba(QString esX)
{
    RadioPrueba->setText(esX);
}

void tabCalibracion::PonerAlturaZ(QString esX)
{
    AlturaZ->setText(esX);
}

void tabCalibracion::PonerRadioA(QString esX)
{
    RadioA->setText(esX);
}

void tabCalibracion::PonerRadioB(QString esX)
{
    RadioB->setText(esX);
}
void tabCalibracion::PonerRadioC(QString esX)
{
    RadioC->setText(esX);
}

void tabCalibracion::PonerEndstopX(QString esX)
{
    EndstopX->setText(esX);
}

void tabCalibracion::PonerEndstopY(QString esY)
{
    EndstopY->setText(esY);
}

void tabCalibracion::PonerEndstopZ(QString esZ)
{
    EndstopZ->setText(esZ);
}

void tabCalibracion::PonerDiagRodA(QString esZ)
{
    DiagRodA->setText(esZ);
}

void tabCalibracion::PonerDiagRodB(QString esZ)
{
    DiagRodB->setText(esZ);
}

void tabCalibracion::PonerDiagRodC(QString esZ)
{
    DiagRodC->setText(esZ);
}

void tabCalibracion::PonerAnguloA(QString esZ)
{
    AngleA->setText(esZ);
}

void tabCalibracion::PonerAnguloB(QString esZ)
{
    AngleB->setText(esZ);
}

void tabCalibracion::PonerAnguloC(QString esZ)
{
    AngleC->setText(esZ);
}

void tabCalibracion::Importar(QSettings &settings)
{
    settings.beginGroup("Calibracion");
    settings.setValue("Diagonal_Rod",DiagonalRod->text());
    settings.setValue("Delta_Radio",DeltaRadio->text());
    settings.setValue("Segmentos_por_Segundo",SegmentosSegundo->text());
    settings.setValue("Radio_Printable",PrintableRadio->text());
    settings.setValue("Radio_de_Prueba",RadioPrueba->text());
    settings.setValue("Altura_Z",AlturaZ->text());
    settings.setValue("Endstop_X",EndstopX->text());
    settings.setValue("Endstop_Y",EndstopY->text());
    settings.setValue("Endstop_Z",EndstopZ->text());
    settings.setValue("Corr_DiaRod_A",DiagRodA->text());
    settings.setValue("Corr_DiaRod_B",DiagRodB->text());
    settings.setValue("Corr_DiaRod_C",DiagRodC->text());
    settings.setValue("Corr_Angulo_A",AngleA->text());
    settings.setValue("Corr_Angulo_B",AngleB->text());
    settings.setValue("Corr_Angulo_C",AngleC->text());
    settings.setValue("Corr_Radio_A",RadioA->text());
    settings.setValue("Corr_Radio_B",RadioB->text());
    settings.setValue("Corr_Radio_C",RadioC->text());
    settings.endGroup();
}

void tabCalibracion::Exportar(QSettings &settings)
{
    settings.beginGroup("Calibracion");
    DiagonalRod->setText(settings.value("Diagonal_Rod","").toString());
    DeltaRadio->setText(settings.value("Delta_Radio","").toString());
    SegmentosSegundo->setText(settings.value("Segmentos_por_Segundo","").toString());
    PrintableRadio->setText(settings.value("Radio_Printable","").toString());
    RadioPrueba->setText(settings.value("Radio_de_Prueba","").toString());
    AlturaZ->setText(settings.value("Altura_Z","").toString());
    EndstopX->setText(settings.value("Endstop_X","").toString());
    EndstopY->setText(settings.value("Endstop_X","").toString());
    EndstopZ->setText(settings.value("Endstop_X","").toString());
    DiagRodA->setText(settings.value("Corr_DiaRod_A","").toString());
    DiagRodB->setText(settings.value("Corr_DiaRod_B","").toString());
    DiagRodC->setText(settings.value("Corr_DiaRod_C","").toString());
    AngleA->setText(settings.value("Corr_Angulo_A","").toString());
    AngleB->setText(settings.value("Corr_Angulo_B","").toString());
    AngleC->setText(settings.value("Corr_Angulo_C","").toString());
    RadioA->setText(settings.value("Corr_Radio_A","").toString());
    RadioB->setText(settings.value("Corr_Radio_B","").toString());
    RadioC->setText(settings.value("Corr_Radio_C","").toString());
    settings.endGroup();
}
