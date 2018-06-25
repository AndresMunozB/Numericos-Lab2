#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include <string>

using namespace std;

vector<double> createVectorXi   (double start, double end, double distance);
vector<double> createVectorYi   (vector<double> vectorXi, int type);
int            factorial        (int n);
double         fx               (double x,int type);
void           save             (string nameFile,vector<double> vectorXi, vector<double> vectorYi);
void           minErrorMinimumSquare();


class Interpolation
{
    public:
        virtual vector<double> differenceFinite     (vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
        virtual vector<double> differenceDivided    (vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
        virtual vector<double> minimumSquare        (vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005,int degree);
        virtual vector<double> cubicSpline          (vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005);
        virtual double         RMSE                 (vector<double> vectorYiIntepolate, vector<double> vectorYiRial);    
};

#endif