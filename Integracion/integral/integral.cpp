#include "integral.h"

CalculoIntegral::CalculoIntegral(){
}

double CalculoIntegral::formulaTrapecio(vector<double> vectorInterpolado, double a, double b){
	int largo = vectorInterpolado.size();
	double integral;
	double inicio = vectorInterpolado[0];
	double final = vectorInterpolado[largo-1];
	double valor = 0.0;

	for(int i = 1; i<(largo-1); i++){
		valor = valor + (2.0*vectorInterpolado[i]);
	}

	integral = ((b-a)/(2*(largo-1)))*(inicio+valor+final);
	return integral;
}

double CalculoIntegral::formulaSimpson(int n, vector<double> vectorInterpolado, double a, double b){

	double valoresImpares = 0.0;
	double valoresPares = 0.0;
	int largo = vectorInterpolado.size();
	double inicial = vectorInterpolado[0];
	double final = vectorInterpolado[n];
	double integral = 0.0;

	for (int i = 1; i <= (n/2) -1; i++)
	{	
		valoresPares += 2.0*vectorInterpolado[i*2];

	}
	for (int i = 1; i <= (n/2) ; i++)
	{	
			valoresImpares += 4.0*vectorInterpolado[(i*2)-1];	
	}

	//FORMULA DE SIMPSON 1/3 APLICACIÓN MULTIPLE

	integral = ((b-a)/(3.0*n))*(inicial + valoresImpares + valoresPares + final);
	return integral;

}

double CalculoIntegral::errorRelativo(double valorMedido, double valorReal){
	double error;
	double absoluto;
	absoluto = valorReal-valorMedido;
	error = abs(absoluto)/valorReal;
	return error;
}