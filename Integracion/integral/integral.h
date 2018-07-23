#ifndef INTEGRAL_H
#define INTEGRAL_H

#include <iostream>
#include <math.h>
#include <vector>

using namespace std;


class Integral
{
	public:
		Integral();
		long double trapecio(vector<long double> vectorInterpolado, long double a, long double b);
		long double simpson(vector<long double> vectorInterpolado, long double a, long double b);
		long double errorRelativo(long double valorMedido, long double valorReal);
};

#endif