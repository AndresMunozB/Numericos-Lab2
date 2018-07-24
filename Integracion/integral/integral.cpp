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

long double Integral::simpson(vector<long double> vi, long double a, long double b){
	int n = vi.size();
	long double result = vi[0] + vi[n-1];
	for (int i = 1; i < (n/2); i++)
	{	
		result += 2.0*vi[i*2];
		result += 4.0*vi[(i*2)-1];
	}
	if(n%2 != 0){
		result += 4.0*vi[n-2];
	}
	result *= ((b-a)/(3.0*n));
	return result;
}

long double Integral::errorRelativo(long double valorMedido, long double valorReal){
	long double error;
	long double absoluto;
	absoluto = valorReal-valorMedido;
	error = abs(absoluto)/valorReal;
	return error;
}