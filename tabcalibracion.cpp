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

    QLabel *LDiagonalRod=new QLabel(tr("Diagonal Rod (mm) :"));
    g1->addWidget(LDiagonalRod,0,0);
    DiagonalRod=new QLineEdit("0",this);
    g1->addWidget(DiagonalRod,0,1);
    QLabel *LDeltaRadio=new QLabel(tr("Delta Radio (mm) :"));
    g1->addWidget(LDeltaRadio);
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
    DiagonalRod->setEnabled(habil);
}

void tabCalibracion::PonerDiagonalRod(QString diaRod)
{
    DiagonalRod->setText(diaRod);
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
