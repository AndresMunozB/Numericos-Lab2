#include "integral.h"

Integral::Integral(){
}


long double Integral::trapecio(vector<long double> vi, long double a, long double b){
	int n = vi.size();
	long double result = vi[0] + vi[n-1];
	for(int i = 1; i<(n-1); i++){
		result += (2.0*vi[i]);
	}
	result *= ((b-a)/(2*(n-1)));
	return result;
}


long double Integral::simpson(vector<long double> vectorInterpolado, long double a, long double b){
	int n = vectorInterpolado.size();
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

long double Integral::errorRelativo(long double valorMedido, long double valorReal){
	long double error;
	long double absoluto;
	absoluto = valorReal-valorMedido;
	error = abs(absoluto)/valorReal;
	return error;
}