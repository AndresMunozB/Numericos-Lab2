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

vector<double> Interpolation::differenceFinite(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    int n = vectorXi.size();
    mat b = mat(n,n);
    mat c = mat(n,n);
    double xt;
    double yi;
    for(int i=0;i<n;i++){
        b(i,0) = vectorYi[i];
        c(i,0) = vectorYi[i];
    }

    for(int j=1;j<n;j++){
		for(int i=0;i<n-j;i++){
			b(i,j) = b(i+1,j-1) - b(i,j-1);
		}
	}

    int h = vectorXi[1]-vectorXi[0];
	for(int j = 1; j<n;j++){
		for(int i=0; i<n-j;i++){
			c(i,j) = (b(i,j))/((pow(h,j))*factorial(j));
		}
	}

    //Calculando los Yi despues de interpolar la funcion
    int contador = vectorXi_005.size();
	for(int i = 0; i<contador; i++){
		xt=1;
		yi = c(0,0);
		for(int j = 0;j<n-1;j++){
			xt = xt*(vectorXi_005[i]-vectorXi[j]);
			yi = yi + c(0,j+1)*xt;
		}
        result.push_back(yi);
    }
		
    

    return result;
}

vector<double> Interpolation::differenceDivided(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    int n = vectorXi.size();
    mat b = mat(n,n);
    double xt;
    double yi;
    for(int i=0;i<n;i++){
        b(i,0) = vectorYi[i];
    }

    for(int j=1;j<n;j++){
		for(int i=0;i<n-j;i++){
			b(i,j) = (b(i+1,j-1) - b(i,j-1))/(vectorXi[i+j]-vectorXi[i]);
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

vector<double> Interpolation::minimumSquare(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005,int degree){
    vector<double> result;
    vector<double> summations;

    int maxDegree = 2*degree;
    int n = degree+1;
    mat A = mat(n,n); 
    mat B = mat(n,1); 

    double sum;
    //Se calcula los valores de las diferentes sumatorias 
    for(int i=0 ; i<=maxDegree ; i++){
        sum = 0;
        for(int j=0;j<vectorXi.size();j++){
            sum +=  pow(vectorXi[j],i);
        }
        summations.push_back(sum);
    }
    //Se llena la matriz A con los valores calculados (sumatorias).
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A(i,j)= summations[i+j];
        }
    }

    //Se llena la matriz B (sumatorias) -> E(Yi*Xi^n)
    for(int i=0;i<n;i++){
          sum = 0;
          for(int j=0;j<vectorXi.size();j++){
              sum += vectorYi[j]*(pow(vectorXi[j],i));
          }
          B(i,0)=sum;
    }

    //mat x = solve(A,B); //warning
    //mat c = inv(A)*B;

    //Se resuelve el sistema de ecuaciones.
    mat L, U;
    lu(L, U, A);
    mat Y = inv(L)*B;
    mat C = inv(U)*Y;

    //Se calculan los Yi despues de interpolar la funcion.
    int size = vectorXi_005.size();
    double resultYi;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < n ; j++){
            resultYi = C(j,0) * pow(vectorXi_005[i],j);
        }
        cout << endl;
        result.push_back(resultYi);
    }
    return result;
   
}

vector<double> Interpolation::cubicSpline(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    return result;
}



