#include "integral.h"

CalculoIntegral::CalculoIntegral(){
}

long double CalculoIntegral::trapecio(vector<long double> vectorInterpolado, long double a, long double b){
	int largo = vectorInterpolado.size();
	long double integral;
	long double inicio = vectorInterpolado[0];
	long double final = vectorInterpolado[largo-1];
	long double valor = 0.0;

	for(int i = 1; i<(largo-1); i++){
		valor = valor + (2.0*vectorInterpolado[i]);
	}

	integral = ((b-a)/(2*(largo-1)))*(inicio+valor+final);
	return integral;
}

long double CalculoIntegral::simpson(int n, vector<long double> vectorInterpolado, long double a, long double b){

	long double valoresImpares = 0.0;
	long double valoresPares = 0.0;
	int largo = vectorInterpolado.size();
	long double inicial = vectorInterpolado[0];
	long double final = vectorInterpolado[n];
	long double integral = 0.0;

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

long double CalculoIntegral::errorRelativo(long double valorMedido, long double valorReal){
	long double error;
	long double absoluto;
	absoluto = valorReal-valorMedido;
	error = abs(absoluto)/valorReal;
	return error;
}