#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include <string>

using namespace std;

vector<long double> createVectorXi   (long double start, long double end, long double distance);
vector<long double> createVectorYi   (vector<long double> vectorXi, int type);
long double         factorial        (long double n);
long double         fx               (long double x,int type);
void                save             (string nameFile,vector<long double> vectorXi, vector<long double> vectorYi);
void                minErrorMinimumSquare();


class Interpolation
{
    public:
        virtual vector<long double> differenceFinite     (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005);
        virtual vector<long double> differenceDivided    (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005);
        virtual vector<long double> minimumSquare        (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005,int degree);
        //virtual vector<long double> cubicSpline          (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005);
        virtual long double         RMSE                 (vector<long double> vectorYiIntepolate, vector<long double> vectorYiRial);    
};

#endif