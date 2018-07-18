#ifndef CALCULOINTEGRAL_H
#define CALCULOINTEGRAL_H

#include <iostream>
#include <cmath>
#include <math.h>
#include <armadillo>

using namespace std;
using namespace arma;

class CalculoIntegral
{
	public:
		CalculoIntegral();
		long double trapecio(vector<long double> vectorInterpolado, long double a, long double b);
		long double simpson(int n, vector<long double> vectorInterpolado, long double a, long double b);
		long double errorRelativo(long double valorMedido, long double valorReal);
};

#endif