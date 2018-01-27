#include "tabcomunicacion.h"

TabComunicacion::TabComunicacion(QWidget *parent) : QWidget(parent)
{
    m_console=new Console(this);

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
    g1->addWidget(m_console);
    layout->addWidget(w1);
    layout->addWidget(w2);
    layout->addWidget(w4);
    layout->addWidget(w3);
    setLayout(layout);
}

void TabComunicacion::Habilitar(bool habil)
{
    m_console->setEnabled(habil);
}

void TabComunicacion::HabilitarEcho (bool habilecho)
{
    m_console->setLocalEchoEnabled(habilecho);
}

void TabComunicacion::PresentarDatos (QByteArray data)
{
    m_console->putData(data);

}


