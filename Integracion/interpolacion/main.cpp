#include <iostream>
#include "interpolation.h"
using namespace std;

int main(int argc, char *argv[])
{
    Fx fx;
    Gx gx;

    Function function(&fx);

    double resulta = function.execute(5.0);
    function.set_strategy(&gx);
    double resultb = function.execute(6.0);
    
    cout << resulta << endl;
    cout << resultb << endl;
    /*vector<double> vectorXi = createVectorXi(-200.0,200.0,0.5);
    int i;
    for(i=0;i<vectorXi.size();i++){
        cout << vectorXi[i] << endl;
    }
    vector<double> vectorYi = createVectorYi(vectorXi,&gx);
    cout << vectorXi.size() <<endl;
    for(i=0;i<vectorYi.size();i++){
        cout << vectorYi[i] << endl;
    }*/

    int fac = factorial(7);
    cout << "factorial:" << fac  << endl;

    return 0;
}