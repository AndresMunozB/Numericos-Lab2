#include "interpolation.h"
#include <armadillo>

using namespace arma;
using namespace std;

vector<double> createVectorXi(double start, double end, double distance){
    vector<double> result;
    
	for(double i = start; i <= end; i = i + distance){
		result.push_back(i);
	}
	return result;
}

vector<double> createVectorYi(vector<double> vectorXi, StrategyFunction *strategy){
    Function function(strategy);
    vector<double> result;
    int i,buffer;
    int length = vectorXi.size();
    for(i=0;i<length;i++){
        buffer = function.execute(vectorXi[i]);
        result.push_back(buffer);
    }
    return result;
}

int factorial(int n){
    int result = 1;
    int i;
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    else{
        for(i=1;i<=n;i++){
            result *= i;
        }
    }
    return result;
}

vector<double> DifferenceFinite::interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    return result;
}

vector<double> DifferenceDivided::interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    int n = vectorXi.size();
    mat b = mat(n,n);
    mat c = mat(n,n);
    double xt;
    double yi;
    for(int i=0;i<n;i++){
        b(i,0) = vectorYi[i];
    }

    for(int j=1;j<n;j++){
		for(int i=0;i<n-j;i++){
			b(i,j) = b(i+1,j-1) - b(i,j-1);
		}
	}

    int contador = vectorXi_005.size();
	for(int i = 0; i<contador; i++){
		xt=1;
		yi = b(0,0);
		for(int j = 0;j<n-1;j++){
			xt = xt*(vectorXi_005[i]-vectorXi[j]);
			yi = yi + b(0,j+1)*xt;
		}
        result.push_back(yi);
    }
		
    

    return result;
}

vector<double> MinimumSquare::interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    vector<double> sumatorias;
    int grado=4;
    int maximoGrado = 2*grado ;
    double sum;
    for(int i=0 ; i<=maximoGrado ; i++){
        sum = 0;
        for(int j=0;j<vectorXi.size();j++){
            sum +=  pow(vectorXi[j],i);
        }
        sumatorias.push_back(sum);
    }
    int n = grado+1;
    mat a = mat(n,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            a(i,j)= sumatorias[i+j];
        }
    }

    mat b = mat(n,1);
    for(int i=0;i<n;i++){
          sum = 0;
          for(int j=0;j<vectorXi.size();j++){
              sum += vectorYi[j]*(pow(vectorXi[j],i));
          }
          b(i,0)=sum;
    }

    mat x = solve(a,b);
    mat c = inv(a)*b;
    mat L, U;
    lu(L, U, a);
    mat Y = inv(L)*b;
    mat C = inv(U)*Y;

    cout << "solve " << endl;
    for(int i = 0;i< n; i++){
        cout << x(i,0) << endl;
    }
    cout << "inv " << endl;
    for(int i = 0;i< n; i++){
        cout << c(i,0) << endl;
    }
    cout << "LU " << endl;
    for(int i = 0;i< n; i++){
        cout << C(i,0) << endl;
    }
    //for(int i = 0; i<n;i++){
     //   cout << c(i,0) << endl;
    //}

    
    return sumatorias;
    //hasta aqui andres
  /*int    n = vectorXi.size();
    double x1 = 0, x2 = 0, x3 = 0, x4 = 0, x5 = 0, x6 = 0, x7 = 0, x8 = 0;
    double yx0 = 0, yx1 = 0, yx2 = 0, yx3 = 0, yx4 = 0;

    //Calculamos todos los elementos que contiene la matriz
    for (int i = 0; i < n; ++i)
    {
        x1 = x1 + pow(vectorXi[i],1.0);
        x2 = x2 + pow(vectorXi[i],2.0);
        x3 = x3 + pow(vectorXi[i],3.0);
        x4 = x4 + pow(vectorXi[i],4.0);
        x5 = x5 + pow(vectorXi[i],5.0);
        x6 = x6 + pow(vectorXi[i],6.0);
        x7 = x7 + pow(vectorXi[i],7.0);
        x8 = x8 + pow(vectorXi[i],8.0);


        yx0 = yx0 + vectorYi[i] * pow(vectorXi[i],0.0);
        yx1 = yx1 + vectorYi[i] * pow(vectorXi[i],1.0);
        yx2 = yx2 + vectorYi[i] * pow(vectorXi[i],2.0);
        yx3 = yx3 + vectorYi[i] * pow(vectorXi[i],3.0);
        yx4 = yx4 + vectorYi[i] * pow(vectorXi[i],4.0);
    }
    mat A = mat(5,5);

    //relleno fila 1
    A(0,0)=n;
    A(0,1)=x1;
    A(0,2)=x2;
    A(0,3)=x3;
    A(0,4)=x4;
    //relleno fila 2
    A(1,0)=x1;
    A(1,1)=x2;
    A(1,2)=x3;
    A(1,3)=x4;
    A(1,4)=x5;  
    //relleno fila 3
    A(2,0)=x2;
    A(2,1)=x3;
    A(2,2)=x4;
    A(2,3)=x5;
    A(2,4)=x6;
    //relleno fila 4
    A(3,0)=x3;
    A(3,1)=x4;
    A(3,2)=x5;
    A(3,3)=x6;
    A(3,4)=x7;
    //relleno fila 5
    A(4,0)=x4;
    A(4,1)=x5;
    A(4,2)=x6;
    A(4,3)=x7;
    A(4,4)=x8;

    
    mat b = mat(1,5);
    b(0,0)=yx0;
    b(0,1)=yx1;
    b(0,2)=yx2;
    b(0,3)=yx3;
    b(0,4)=yx4;

    mat B = b.t();

    vec C = solve(A,B);
    for(int i = 0;i< 5; i++){
        
        cout << C(i,0) << endl;
        
        
    }
    int count = vectorXi_005.size();
    vector<double> FXresultante; 

    for (int i = 0; i < count; ++i)
    {
        double yResultante = C(0) + C(1)*vectorXi_005[i] + C(2)* pow(vectorXi_005[i],2.0) + C(3) * pow(vectorXi_005[i],3.0);
        FXresultante.push_back(yResultante);
    }
    
    return FXresultante;*/
}

vector<double> CubicSpline::interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    return result;
}

Interpolation::Interpolation(StrategyInterpolation *strategy):_strategy(strategy){}

void           Interpolation::set_strategy(StrategyInterpolation *strategy){_strategy = strategy;}

vector<double> Interpolation::interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    return _strategy->interpolate(vectorXi,vectorYi,vectorXi_005);
}



