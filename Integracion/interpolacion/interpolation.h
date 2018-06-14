#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include "function.h"

using namespace std;

//Clase abstracta
class StrategyInterpolation
{
    public:
        virtual vector<double> interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005) = 0;
};

class DifferenceFinite : public StrategyInterpolation
{
    public:
        virtual vector<double> interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
};

class DifferenceDivided: public StrategyInterpolation
{
    public:
        virtual vector<double> interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
};

class MinimumSquare: public StrategyInterpolation
{
    public:
        virtual vector<double> interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
};

class CubicSpline: public StrategyInterpolation
{
    public:
        virtual vector<double> interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
};

class Interpolation
{
    private:
        StrategyInterpolation *_strategy;

    public:
        Interpolation(StrategyInterpolation *strategy);
        void set_strategy(StrategyInterpolation *strategy);
        vector<double> interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
};

vector<double> createVectorXi(double start, double end, double distance);
vector<double> createVectorYi(vector<double> vectorXi, StrategyFunction *strategy);
int factorial(int n);

#endif