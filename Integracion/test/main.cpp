#include <iostream>
#include "../interpolacion/interpolation.h"
#include "../integral/integral.h"

using namespace std;


void execute(int function){

    vector<long double> vectorXi_0_5  = createVectorXi(-200.0,200.0,0.5);
    vector<long double> vectorXi_1    = createVectorXi(-200.0,200.0,1);
    vector<long double> vectorXi_5    = createVectorXi(-200.0,200.0,5);
    vector<long double> vectorXi_10   = createVectorXi(-200.0,200.0,10);

    vector<long double> vectorYi_0_5  = createVectorYi(vectorXi_0_5,function);
	vector<long double> vectorYi_1    = createVectorYi(vectorXi_1  ,function);
	vector<long double> vectorYi_5    = createVectorYi(vectorXi_5  ,function);
	vector<long double> vectorYi_10   = createVectorYi(vectorXi_10 ,function);

    vector<long double> vectorXiRial  = createVectorXi(-200.0,200.0,0.05);
    vector<long double> vectorYiRial  = createVectorYi(vectorXiRial,function);
    saveInterpolationResult("../../Matlab/Real_f" + to_string(function)+".dat",vectorXiRial,vectorYiRial);

    vector<long double> result_0_5;
    vector<long double> result_1;
    vector<long double> result_5;
    vector<long double> result_10;

    vector<long double> error_df; //RMSE Diferencias Finitas.
    vector<long double> error_dd; //RMSE Diferencias Divididas.
    vector<long double> error_ms; //RMSE Minimos Cuadrados.
    vector<long double> error_cs; //RMSE Spline Cubico.

    

    Interpolation interpolation = Interpolation();

    //DIFERENCIAS FINITAS
    cout << "DIFERENCIAS FINITAS..." << endl;
    result_0_5 = interpolation.differenceFinite(vectorXi_0_5,vectorYi_0_5,vectorXiRial);
    result_1   = interpolation.differenceFinite(vectorXi_1  ,vectorYi_1  ,vectorXiRial);
    result_5   = interpolation.differenceFinite(vectorXi_5  ,vectorYi_5  ,vectorXiRial);
    result_10  = interpolation.differenceFinite(vectorXi_10 ,vectorYi_10 ,vectorXiRial);
    error_df.push_back(interpolation.RMSE(result_0_5,vectorYiRial));
    error_df.push_back(interpolation.RMSE(result_1  ,vectorYiRial));
    error_df.push_back(interpolation.RMSE(result_5  ,vectorYiRial));
    error_df.push_back(interpolation.RMSE(result_10 ,vectorYiRial));
    saveInterpolationResult("../../Matlab/DF_f" + to_string(function) + "_0_5.dat",vectorXiRial,result_0_5);
    saveInterpolationResult("../../Matlab/DF_f" + to_string(function) + "_1.dat"  ,vectorXiRial,result_1);
    saveInterpolationResult("../../Matlab/DF_f" + to_string(function) + "_5.dat"  ,vectorXiRial,result_5);
    saveInterpolationResult("../../Matlab/DF_f" + to_string(function) + "_10.dat" ,vectorXiRial,result_10);
    cout << "END DIFERENCIAS FINITAS" << endl;
    //END DIFERENCIAS FINITAS

    //DIFERENCIAS DIVIDIDAS
    cout  << "DIFERENCIAS DIVIDIDAS..." << endl;
    result_0_5 = interpolation.differenceDivided(vectorXi_0_5,vectorYi_0_5,vectorXiRial);
    result_1   = interpolation.differenceDivided(vectorXi_1  ,vectorYi_1  ,vectorXiRial);
    result_5   = interpolation.differenceDivided(vectorXi_5  ,vectorYi_5  ,vectorXiRial);
    result_10  = interpolation.differenceDivided(vectorXi_10 ,vectorYi_10 ,vectorXiRial);
    error_dd.push_back(interpolation.RMSE(result_0_5,vectorYiRial));
    error_dd.push_back(interpolation.RMSE(result_1  ,vectorYiRial));
    error_dd.push_back(interpolation.RMSE(result_5  ,vectorYiRial));
    error_dd.push_back(interpolation.RMSE(result_10 ,vectorYiRial));
    saveInterpolationResult("../../Matlab/DD_f" + to_string(function) + "_0_5.dat",vectorXiRial,result_0_5);
    saveInterpolationResult("../../Matlab/DD_f" + to_string(function) + "_1.dat"  ,vectorXiRial,result_1);
    saveInterpolationResult("../../Matlab/DD_f" + to_string(function) + "_5.dat"  ,vectorXiRial,result_5);
    saveInterpolationResult("../../Matlab/DD_f" + to_string(function) + "_10.dat" ,vectorXiRial,result_10);
    //END DIFERENCIAS DIVIDIDAS
    cout  << "END DIFERENCIAS DIVIDIDAS..." << endl;

    
    //MINIMOS CUADRADOS
    cout  << "MINIMOS CUADRADOS..." << endl;
    int degree = 0;
    if(function == 1){
        degree = 40;
    }
    else if(function == 2){
        degree  = 15;
    }
    result_0_5 = interpolation.minimumSquare(vectorXi_0_5,vectorYi_0_5,vectorXiRial,degree);
    result_1   = interpolation.minimumSquare(vectorXi_1  ,vectorYi_1  ,vectorXiRial,degree);
    result_5   = interpolation.minimumSquare(vectorXi_5  ,vectorYi_5  ,vectorXiRial,degree);
    result_10  = interpolation.minimumSquare(vectorXi_10 ,vectorYi_10 ,vectorXiRial,degree);
    error_ms.push_back(interpolation.RMSE(result_0_5,vectorYiRial));
    error_ms.push_back(interpolation.RMSE(result_1  ,vectorYiRial));
    error_ms.push_back(interpolation.RMSE(result_5  ,vectorYiRial));
    error_ms.push_back(interpolation.RMSE(result_10 ,vectorYiRial));
    saveInterpolationResult("../../Matlab/MS_f" + to_string(function) + "_0_5.dat",vectorXiRial,result_0_5);
    saveInterpolationResult("../../Matlab/MS_f" + to_string(function) + "_1.dat"  ,vectorXiRial,result_1);
    saveInterpolationResult("../../Matlab/MS_f" + to_string(function) + "_5.dat"  ,vectorXiRial,result_5);
    saveInterpolationResult("../../Matlab/MS_f" + to_string(function) + "_10.dat" ,vectorXiRial,result_10);
    cout  << "END MINIMOS CUADRADOS" << endl;
    //END MINIMOS CUADRADOSerror_sc

    //SPLINE CUBICO
     cout  << "SPLINE CUBICO..." << endl;
    result_0_5 = interpolation.cubicSpline(vectorXi_0_5,vectorYi_0_5,vectorXiRial);
    result_1   = interpolation.cubicSpline(vectorXi_1  ,vectorYi_1  ,vectorXiRial);
    result_5   = interpolation.cubicSpline(vectorXi_5  ,vectorYi_5  ,vectorXiRial);
    result_10  = interpolation.cubicSpline(vectorXi_10 ,vectorYi_10 ,vectorXiRial);
    error_cs.push_back(interpolation.RMSE(result_0_5,vectorYiRial));
    error_cs.push_back(interpolation.RMSE(result_1  ,vectorYiRial));
    error_cs.push_back(interpolation.RMSE(result_5  ,vectorYiRial));
    error_cs.push_back(interpolation.RMSE(result_10 ,vectorYiRial));
    saveInterpolationResult("../../Matlab/CS_f" + to_string(function) + "_0_5.dat",vectorXiRial,result_0_5);
    saveInterpolationResult("../../Matlab/CS_f" + to_string(function) + "_1.dat"  ,vectorXiRial,result_1);
    saveInterpolationResult("../../Matlab/CS_f" + to_string(function) + "_5.dat"  ,vectorXiRial,result_5);
    saveInterpolationResult("../../Matlab/CS_f" + to_string(function) + "_10.dat" ,vectorXiRial,result_10);
    cout  << "END SPLINE CUBICO" << endl;
    //END SPLINE CUBICO

    //Guardando los RMSE
    saveInterpolationError(function,error_df,error_dd,error_ms,error_cs);
    Integral integral = Integral();
    cout << "trapecio: " <<  integral.trapecio(result_0_5,-200,200) << endl;
    cout << "simpson: " <<  integral.simpson(result_0_5,-200,200) << endl;

}

int main(int argc, char *argv[])
{
    execute(1);
    execute(2);
    return 0;
}

