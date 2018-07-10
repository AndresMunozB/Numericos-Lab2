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
		double formulaTrapecio(vector<double> vectorInterpolado, double a, double b);
		double formulaSimpson(int n, vector<double> vectorInterpolado, double a, double b);
		double errorRelativo(double valorMedido, double valorReal);
};

#endif