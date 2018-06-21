#include <iostream>
#include "interpolation.h"

using namespace std;

int main(int argc, char *argv[])
{
    //Funciones
    Fx fx; //Primera funcion
    Gx gx; //Seguna funcion

    //Metodos de interpolacion:

    
    
    Function function(&fx);
    /*double resulta = function.execute(5.0);
    function.set_strategy(&gx);
    double resultb = function.execute(6.0);
    
    cout << resulta << endl;
    cout << resultb << endl;*/
    //Interpolation
    //Interpolation interpolation(&differenceFinite);
    Interpolation interpolation = Interpolation();
    vector<double> vectorXi = createVectorXi(-200.0,200.0,0.5);
    vector<double> vectorYi = createVectorYi(vectorXi,&gx);
    vector<double> vectorXi_0_05 = createVectorXi(-200.0,200.0,0.05);
    vector<double> result = interpolation.differenceFinite(vectorXi,vectorYi,vectorXi_0_05);
    
    /*for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }*/
    cout << result.size() << endl;

    
    //int fac = factorial(7);
    //cout << "factorial:" << fac  << endl;


    return 0;
}