#ifndef CALIBRACION_H
#define CALIBRACION_H

struct PuntosPrueba {
    float probeX[20];
    float probeY[20];
};

class Calibracion
{
private:
    int numPoints=10;
    float bedRadius=70;
    PuntosPrueba pprueba;
public:
    Calibracion();
    void calcProbePoints();
    void calc ();
};

#endif // CALIBRACION_H
