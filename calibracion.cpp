#include "calibracion.h"
#include <QtMath>

Calibracion::Calibracion()
{

}

void Calibracion::calcProbePoints()
    {
    if (numPoints < 7) {
        for (int i = 0; i < 3; ++i) {
            pprueba.probeX[i] = (bedRadius * sin((2 * M_PI * i)/3));
            pprueba.probeY[i] = (bedRadius * cos((2 * M_PI * i)/3));
        }
        pprueba.probeX[3] = 0.0;
        pprueba.probeY[3] = 0.0;
        numPoints=4;
    }
    else {
        if (numPoints >= 7) {
            for (int i = 0; i < 6; ++i)
            {
                pprueba.probeX[i] = (bedRadius * sin((2 * M_PI * i)/6));
                pprueba.probeY[i] = (bedRadius * cos((2 * M_PI * i)/6));

            }
            numPoints=7;
        }
        if (numPoints >= 10) {
            for (int i = 6; i < 9; ++i) {
                pprueba.probeX[i] = (bedRadius/2 * sin((2 * M_PI * (i - 6))/3));
                pprueba.probeY[i] = (bedRadius/2 * cos((2 * M_PI * (i - 6))/3));
            }
            pprueba.probeX[9] = 0.0;
            pprueba.probeY[9] = 0.0;
            numPoints=10;
        }
        else {
            pprueba.probeX[6] = 0.0;
            pprueba.probeY[6] = 0.0;
            numPoints=7;
        }
    }
}

void Calibracion::calc()
    {
//	getParameters();
//	convertIncomingEndstops();
//    try {
//		var rslt = DoDeltaCalibration();
//		document.getElementById("result").innerHTML = "&nbsp;Success! " + rslt + "&nbsp;";
//		document.getElementById("result").style.backgroundColor = "LightGreen";
//		convertOutgoingEndstops();
//		setNewParameters();
//		generateCommands();
//		document.getElementById("copyButton").disabled = false;
//    }
//    catch (err) {
//		document.getElementById("result").innerHTML = "&nbsp;Error! " + err + "&nbsp;";
//		document.getElementById("result").style.backgroundColor = "LightPink";
//		document.getElementById("copyButton").disabled = true;
//    }
}
