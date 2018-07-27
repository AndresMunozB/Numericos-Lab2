#ifndef INTERPOLATION_H
#define INTERPOLATION_H

#include <vector>
#include <string>

using namespace std;
class Interpolation
{
    public:
        virtual vector<long double> differenceFinite     (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005);
        virtual vector<long double> differenceDivided    (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005);
        virtual vector<long double> minimumSquare        (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005,int degree);
        virtual vector<long double> cubicSpline          (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005);
        virtual long double         RMSE                 (vector<long double> vectorYiIntepolate, vector<long double> vectorYiRial);   
         
};

class Data
{
    public:
        vector<long double> vectorXi_0_5;
        vector<long double> vectorXi_1  ;
        vector<long double> vectorXi_5  ;
        vector<long double> vectorXi_10 ;

        vector<long double> vectorYi_0_5_f1;
        vector<long double> vectorYi_1_f1  ;
        vector<long double> vectorYi_5_f1  ;
        vector<long double> vectorYi_10_f1 ;

        vector<long double> vectorYi_0_5_f2;
        vector<long double> vectorYi_1_f2  ;
        vector<long double> vectorYi_5_f2  ;
        vector<long double> vectorYi_10_f2 ;

        vector<long double> vectorXiRial;
        vector<long double> vectorYiRial_f1;
        vector<long double> vectorYiRial_f2;
};

vector<long double> createVectorXi   (long double start, long double end, long double distance);
vector<long double> createVectorYi   (vector<long double> vectorXi, int type);
long double         factorial        (long double n);
long double         fx               (long double x,int type);
void                saveInterpolationResult             (string nameFile,vector<long double> vectorXi, vector<long double> vectorYi);
void saveInterpolationError(string path,int function,vector<long double> error_df, vector<long double> error_dd, vector<long double> error_ms, vector<long double> error_sc);
void                minErrorMinimumSquare(Data data);

void                minErrorMinimumSquare2(Data data);
void saveResultsCI(string nameFile, int function, long double integral, long double trapecio, long double simpson, long double eTrapecio, long double eSimpson);





#endif