#include <iostream>
#include <vector>
#include "integral.h"

using namespace std;

int main(int argc, char *argv[])
{
    ofstream archivoSalida3;
    archivoSalida3.open("ErroresCI.txt");
    Interpolacion interpolation = Interpolacion();
    
	//TRAPECIO Y SIMPSON <-- cálculo del error integral
	//valores reales de las funciones 1 y 2
	double integralF1 = 7.2260*pow(10,86);
	double integralF2 = 2.1334*pow(10,7);
    CalculoIntegral ci = CalculoIntegral();
	//El método con menor error fue el método de los mínimos cuadrados.
	//Función 1 
	archivoSalida3<<"VALOR REAL: "<<endl;
	archivoSalida3<<"Funcion 1: "<<integralF1<<endl;
	archivoSalida3<<"Funcion 2: "<<integralF2<<endl;
	archivoSalida3<<endl;
	archivoSalida3<<"VALOR MEDIDO/CALCULADO: "<<endl;
	archivoSalida3<<"Funcion 1: "<<endl;
	double trapecioF1 = ci.trapecio(minCuadrados_1_05,-200,200);
	double simpsonF1 = ci.simpson(minCuadrados_1_05.size()-1,minCuadrados_1_05,-200,200);
	archivoSalida3<<"Calculo Integral Trapecio: "<<trapecioF1<<endl;
	archivoSalida3<<"Calculo Integral Simpson: "<<simpsonF1<<endl;
	archivoSalida3<<endl;

	archivoSalida3<<"Funcion 2: "<<endl;
	double trapecioF2 = ci.trapecio(minCuadrados_2_05,-200,200);
	double simpsonF2 = ci.simpson(minCuadrados_2_05.size()-1,minCuadrados_2_05,-200,200);
	archivoSalida3<<"Calculo Integral Trapecio: "<<trapecioF2<<endl;
	archivoSalida3<<"Calculo Integral Simpson: "<<simpsonF2<<endl;
	archivoSalida3<<endl;
	archivoSalida3<<"**********************************************"<<endl;
	archivoSalida3<<"ERRORES RELATIVOS: "<<endl;
	archivoSalida3<<"Funcion 1: "<<endl;
	double errTF1 = ci.errorRelativo(trapecioF1,integralF1);
	double errSF1 = ci.errorRelativo(simpsonF1,integralF1);
	archivoSalida3<<"Error F1 con Trapecio: "<<errTF1<<endl;
	archivoSalida3<<"Error F1 con Simpson: "<<errSF1<<endl;
	archivoSalida3<<endl;
	archivoSalida3<<"Funcion 2: "<<endl;
	double errTF2 = ci.errorRelativo(trapecioF2,integralF2);
	double errSF2 = ci.errorRelativo(simpsonF2,integralF2);
	archivoSalida3<<"Error F2 con Trapecio: "<<errTF2<<endl;
	archivoSalida3<<"Error F2 con Simpson: "<<errSF2<<endl;
	archivoSalida3.close();



    return 0;
}
    
    