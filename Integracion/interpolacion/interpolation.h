#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include "function.h"

using namespace std;


class Interpolation
{
    public:
        virtual vector<double> differenceFinite(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
        virtual vector<double> differenceDivided(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
        virtual vector<double> minimumSquare(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005,int degree);
        virtual vector<double> cubicSpline(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
     
};

vector<double> createVectorXi(double start, double end, double distance);
vector<double> createVectorYi(vector<double> vectorXi, StrategyFunction *strategy);
int factorial(int n);

#endif