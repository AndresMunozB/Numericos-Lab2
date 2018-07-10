#include <iostream>
#include "interpolation.h"

using namespace std;


void execute(int function){

    vector<long double> vectorXi_0_5  = createVectorXi(-200.0,200.0,0.5);
    vector<long double> vectorXi_1    = createVectorXi(-200.0,200.0,1);
    vector<long double> vectorXi_5    = createVectorXi(-200.0,200.0,5);
    vector<long double> vectorXi_10   = createVectorXi(-200.0,200.0,10);

    vector<long double> vectorYi_0_5 = createVectorYi(vectorXi_0_5,function);
	vector<long double> vectorYi_1  = createVectorYi(vectorXi_1,function);
	vector<long double> vectorYi_5  = createVectorYi(vectorXi_5,function);
	vector<long double> vectorYi_10 = createVectorYi(vectorXi_10,function);

    vector<long double> vectorXiRial = createVectorXi(-200.0,200.0,0.05);
    vector<long double> vectorYiRial = createVectorYi(vectorXiRial,function);

    vector<long double> result_0_5;
    vector<long double> result_1;
    vector<long double> result_5;
    vector<long double> result_10;
    save("../../Matlab/Real_f" + to_string(function)+".dat",vectorXiRial,vectorYiRial);

    Interpolation interpolation = Interpolation();

    //DIFERENCIAS FINITAS
    cout << "DIFERENCIAS FINITAS..." << endl;
    result_0_5 = interpolation.differenceFinite(vectorXi_0_5,vectorYi_0_5,vectorXiRial);
    result_1 = interpolation.differenceFinite(vectorXi_1,vectorYi_1,vectorXiRial);
    result_5 = interpolation.differenceFinite(vectorXi_5,vectorYi_5,vectorXiRial);
    result_10 = interpolation.differenceFinite(vectorXi_10,vectorYi_10,vectorXiRial);
    save("../../Matlab/DF_f" + to_string(function) + "_0_5.dat",vectorXiRial,result_0_5);
    save("../../Matlab/DF_f" + to_string(function) + "_1.dat",vectorXiRial,result_1);
    save("../../Matlab/DF_f" + to_string(function) + "_5.dat",vectorXiRial,result_5);
    save("../../Matlab/DF_f" + to_string(function) + "_10.dat",vectorXiRial,result_10);
    cout << "END DIFERENCIAS FINITAS" << endl;
    //END DIFERENCIAS FINITAS

    //DIFERENCIAS DIVIDIDAS
    cout  << "DIFERENCIAS DIVIDIDAS..." << endl;
    result_0_5 = interpolation.differenceDivided(vectorXi_0_5,vectorYi_0_5,vectorXiRial);
    result_1 = interpolation.differenceDivided(vectorXi_1,vectorYi_1,vectorXiRial);
    result_5 = interpolation.differenceDivided(vectorXi_5,vectorYi_5,vectorXiRial);
    result_10 = interpolation.differenceDivided(vectorXi_10,vectorYi_10,vectorXiRial);
    save("../../Matlab/DD_f" + to_string(function) + "_0_5.dat",vectorXiRial,result_0_5);
    save("../../Matlab/DD_f" + to_string(function) + "_1.dat",vectorXiRial,result_1);
    save("../../Matlab/DD_f" + to_string(function) + "_5.dat",vectorXiRial,result_5);
    save("../../Matlab/DD_f" + to_string(function) + "_10.dat",vectorXiRial,result_10);
    //END DIFERENCIAS DIVIDIDAS
    cout  << "END DIFERENCIAS DIVIDIDAS..." << endl;

    
    //MINIMOS CUADRADOS
    cout  << "MINIMOS CUADRADOS..." << endl;
    int degree = 0;
    if(function == 1){
        degree = 40;
    }
    else if(function == 2){
        degree  = 8;
    }
    result_0_5 = interpolation.minimumSquare(vectorXi_0_5,vectorYi_0_5,vectorXiRial,degree);
    result_1 = interpolation.minimumSquare(vectorXi_1,vectorYi_1,vectorXiRial,degree);
    result_5 = interpolation.minimumSquare(vectorXi_5,vectorYi_5,vectorXiRial,degree);
    result_10 = interpolation.minimumSquare(vectorXi_10,vectorYi_10,vectorXiRial,degree);
    save("../../Matlab/MS_f" + to_string(function) + "_0_5.dat",vectorXiRial,result_0_5);
    save("../../Matlab/MS_f" + to_string(function) + "_1.dat",vectorXiRial,result_1);
    save("../../Matlab/MS_f" + to_string(function) + "_5.dat",vectorXiRial,result_5);
    save("../../Matlab/MS_f" + to_string(function) + "_10.dat",vectorXiRial,result_10);
    cout  << "END MINIMOS CUADRADOS" << endl;
    //END MINIMOS CUADRADOS

    //SPLINE CUBICO
    //codigo spline cubico
    //END SPLINE CUBICO

}

int main(int argc, char *argv[])
{
    
    execute(2);
    return 0;
}

