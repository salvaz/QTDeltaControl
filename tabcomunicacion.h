#ifndef TABCOMUNICACION_H
#define TABCOMUNICACION_H

#include <QWidget>
#include <QVBoxLayout>
#include <QGridLayout>
#include "console.h"

class TabComunicacion : public QWidget
{
    Q_OBJECT
private:
    Console *m_console;
public:
    explicit TabComunicacion(QWidget *parent = nullptr);
    void Habilitar (bool habil);
    void HabilitarEcho (bool habilecho);
    void PresentarDatos (QByteArray data);

signals:

public slots:

};

#endif // TABCOMUNICACION_H
