#include "interpolation.h"
#include <armadillo>
#include <math.h>


using namespace arma;
using namespace std;

double fx(double x,int type){
    if(type == 1){
        return exp(x)+x - 2;
    }
    else if(type == 2){
        return pow(x,3)+4*pow(x,2)-5*x+2;
    }
    else{
        cout << "Error en tipo de función" << endl;
        return 0;
    }
}

int factorial(int n){
    int result = 1;
    if(n<0){
        return 0;
    }
    else if(n==0){
        return 1;
    }
    else{
        for(int i=1;i<=n;i++){
            result *= i;
        }
    }
    return result;
}

void save(string nameFile,vector<double> vectorXi, vector<double> vectorYi){
	ofstream output;
	output.open(nameFile,ios::out);
	for(int i = 0; i<vectorXi.size(); i++){
		output<<vectorXi[i]<<" "<<vectorYi[i]<<endl;
	}
	output.close();
}

vector<double> createVectorXi(double start, double end, double distance){
    vector<double> result;
	for(double i = start; i <= end; i = i + distance){
		result.push_back(i);
	}
	return result;
}

vector<double> createVectorYi(vector<double> vectorXi, int type){
    vector<double> result;
    int i;
    double buffer;
    int length = vectorXi.size();
    for(i=0;i<length;i++){
        buffer = fx(vectorXi[i],type);
        result.push_back(buffer);
    }
    return result;
}

vector<double> Interpolation::differenceFinite(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_0_05){
    vector<double> result;
    int n = vectorXi.size();
    mat b = mat(n,n);
    mat c = mat(n,n);
    double xt;
    double yi;
    //
    for(int i=0;i<n;i++){
        b(i,0) = vectorYi[i];
        c(i,0) = vectorYi[i];
    }
    //

    for(int j=1;j<n;j++){
		for(int i=0;i<n-j;i++){
			b(i,j) = b(i+1,j-1) - b(i,j-1);
		}
	}

    //
    int h = vectorXi[1]-vectorXi[0];
	for(int j = 1; j<n;j++){
		for(int i=0; i<n-j;i++){
			c(i,j) = (b(i,j))/((pow(h,j))*factorial(j));
            cout << "factorial(j): " << factorial(j) << endl; 
		}
	}

    //Calculando los Yi despues de interpolar la funcion
    int contador = vectorXi_0_05.size();
	for(int i = 0; i<contador; i++){
		xt=1;
		yi = c(0,0);
		for(int j = 0;j<n-1;j++){
			xt = xt*(vectorXi_0_05[i]-vectorXi[j]);
			yi = yi + c(0,j+1)*xt;
		}
        result.push_back(yi);
    }

    return result;
}

vector<double> Interpolation::differenceDivided(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_0_05){
    vector<double> result;
    int n = vectorXi.size();
    mat b = mat(n,n);
    double xt;
    double yi;
    //
    for(int i=0;i<n;i++){
        b(i,0) = vectorYi[i];
    }
    //
    for(int j=1;j<n;j++){
		for(int i=0;i<n-j;i++){
			b(i,j) = (b(i+1,j-1) - b(i,j-1))/(vectorXi[i+j]-vectorXi[i]);
		}
	}
    int contador = vectorXi_0_05.size();
	for(int i = 0; i<contador; i++){
		xt=1;
		yi = b(0,0);
		for(int j = 0;j<n-1;j++){
			xt = xt*(vectorXi_0_05[i]-vectorXi[j]);
			yi = yi + b(0,j+1)*xt;
		}
        result.push_back(yi);
    }
		
    return result;
}

vector<double> Interpolation::minimumSquare(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_0_05, int degree){
    vector<double> result; //Vector que retorna la funcion
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
            cout <<"i,j:" << i <<","<< j <<" ;vectorXi[j]: " << vectorXi[j] << " ;pow: "<< pow(vectorXi[j],i)<< endl;
        }
        cout << endl;
        summations.push_back(sum);
    }
    //Se llena la matriz A con los valores calculados (sumatorias).
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A(i,j)= summations[i+j];
            cout << summations[i+j] << ", ";
        }
        cout << endl ;
    }
    //Se llena la matriz B (sumatorias) -> E(Yi*Xi^n)
    for(int i=0;i<n;i++){
          sum = 0;
          for(int j=0;j<vectorXi.size();j++){
              sum += vectorYi[j]*(pow(vectorXi[j],i));  
              //cout << vectorYi[j] << ", " << vectorXi[j] << endl;  
          }
          //cout <<"i:"<< i <<"sum: " << sum << endl;
          //cout << endl;
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
    int size = vectorXi_0_05.size();
    double resultYi;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < n ; j++){
            resultYi += C(j,0) * pow(vectorXi_0_05[i],j);
            //cout << j << ", ";
        }
        //cout <<"i: " << i  << "val:" << resultYi<< endl;
        result.push_back(resultYi);
    }   
    return result;
   
}

vector<double> Interpolation::cubicSpline(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_0_05){
    vector<double> result;
    return result;
}

double Interpolation::RMSE(vector<double> vectorYiIntepolate, vector<double> vectorYiRial){
	double size = vectorYiRial.size();
	double result = 0;
	for(int i = 0; i<size;i++){
		result += pow(vectorYiRial[i]-vectorYiIntepolate[i],2.0);
	}
	result = sqrt(result/size);
	return result;
}

void minErrorMinimumSquare(){
    vector<double> vectorXi     = createVectorXi(-200.0,200.0,5);
    vector<double> vectorXiRial = createVectorXi(-200.0,200.0,0.05);

    vector<double> vectorYi     = createVectorYi(vectorXi,1);
    vector<double> vectorYiRial = createVectorYi(vectorXiRial,1);
    
    Interpolation interpolation = Interpolation();
    vector<double> result = interpolation.minimumSquare(vectorXi,vectorYi,vectorXiRial,1);
    double minError = interpolation.RMSE(result,vectorYiRial) ;
    double aux = minError;
    cout << aux << ", " << 1 << endl;

    int iteration = 1;
    for (int i=2;i<67;i++){
            result = interpolation.minimumSquare(vectorXi,vectorYi,vectorXiRial,i);
            aux = interpolation.RMSE(result,vectorYiRial);
            if(minError > aux){
                minError = aux;
                iteration = i;
            }
            cout << aux << ", " << i << endl;
    }
    cout << "minError : " << minError << endl;
    cout << "Iteration: " << iteration << endl;
}

