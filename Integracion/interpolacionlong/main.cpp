#include <iostream>
#include "interpolation.h"

using namespace std;

int main(int argc, char *argv[])
{
    
    //Interpolation
    Interpolation interpolation = Interpolation();


    vector<long double> vectorXi_0_5  = createVectorXi(-200.0,200.0,0.5);
    vector<long double> vectorXi_1    = createVectorXi(-200.0,200.0,0.5);
    vector<long double> vectorXi_5    = createVectorXi(-200.0,200.0,0.5);
    vector<long double> vectorXi_10   = createVectorXi(-200.0,200.0,0.5);


    //Xi para la funcion 1
	vector<long double> vectorY_f1_05 = createVectorYi(vectorXi_0_5,1);
	vector<long double> vectorY_f1_1  = createVectorYi(vectorXi_1,1);
	vector<long double> vectorY_f1_5  = createVectorYi(vectorXi_5,1);
	vector<long double> vectorY_f1_10 = createVectorYi(vectorXi_10,1);

    //Xi para la funcion 2
	vector<long double> vectorY_f2_05 = createVectorYi(vectorXi_0_5,2);
	vector<long double> vectorY_f2_1  = createVectorYi(vectorXi_1,2);
	vector<long double> vectorY_f2_5  = createVectorYi(vectorXi_5,2);
	vector<long double> vectorY_f2_10 = createVectorYi(vectorXi_10,2);


    vector<long double> vectorXiRial = createVectorXi(-200.0,200.0,0.05);
    /*for(int i = 0; i < vectorXi.size(); i++){
        cout << vectorXi[i]<< endl;
    }*/
    vector<long double> vectorYi     = createVectorYi(vectorXi_0_5,1);
    vector<long double> vectorYiRial = createVectorYi(vectorXiRial,1);
    vector<long double> result = interpolation.minimumSquare(vectorXi_0_5,vectorYi,vectorXiRial,65);
    //cout << "hola" << endl;

    /*vector<long double> result;
    for(int i = 0; i < vectorXiRial.size(); i++){
        result.push_back(fx(vectorXiRial[i],1));
    }*/
    save("../../Matlab/archivo2.txt",vectorXiRial,result);
    save("../../Matlab/archivo1.txt",vectorXiRial,vectorYiRial);
    save("../../Matlab/vectorxi.txt",vectorXi_0_5,vectorYi);
    //minErrorMinimumSquare();
    //for(int i=0;i<result.size();i++){
      //  cout << result[i] << endl;
    //}
    // 2.71474e+3472
    // 2.71474e+3472 finita
    


    return 0;
}