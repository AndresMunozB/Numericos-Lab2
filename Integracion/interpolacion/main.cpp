#include <iostream>
#include "interpolation.h"

using namespace std;

int main(int argc, char *argv[])
{

    
    //Interpolation
    Interpolation interpolation = Interpolation();
    vector<double> vectorXi     = createVectorXi(-200.0,200.0,0.5);
    vector<double> vectorXiRial = createVectorXi(-200.0,200.0,0.05);

    vector<double> vectorYi     = createVectorYi(vectorXi,1);
    vector<double> vectorYiRial = createVectorYi(vectorXiRial,1);

    vector<double> result = interpolation.differenceFinite(vectorXi,vectorYi,vectorYiRial);
    save("archivo.txt",vectorXiRial,vectorYiRial);
    //minErrorMinimumSquare();
    /*for(int i=0;i<result.size();i++){
        cout << result[i] << endl;
    }*/
    cout << result.size() << endl;



    return 0;
}