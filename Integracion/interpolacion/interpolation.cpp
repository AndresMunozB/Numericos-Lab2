#include "interpolation.h"
#include <armadillo>
#include <math.h>


using namespace arma;
using namespace std;

long double fx(long double x,int type){
    if(type == 1){
        return exp(x)+ x - 2;
    }
    else if(type == 2){
        return pow(x,3)+4*pow(x,2)-5*x+2;
    }
    else{
        cout << "Error en tipo de función" << endl;
        return 0;
    }
}

vector<vector<long double>> createMatriz(int n, int m){
    vector<vector<long double>> b;
    for(int i = 0;i<n; i++    ) {
        vector<long double> col;
        b.push_back(col);
        for(int j=0;j<m;j++){
            b[i].push_back(0);
        }
    }
    return b;
}


long double factorial(long double n){
    long double result = 1.0;
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

void saveInterpolationResult(string nameFile,vector<long double> vectorXi, vector<long double> vectorYi){
	ofstream output;
	output.open(nameFile,ios::out);
	for(int i = 0; i<vectorXi.size(); i++){
		output<<vectorXi[i]<<" "<<vectorYi[i]<<endl;
	}
	output.close();
}
void saveInterpolationError(int function,vector<long double> error_df, vector<long double> error_dd, vector<long double> error_ms, vector<long double> error_sc){
    ofstream output;
	output.open("../../Matlab/RMSE_F" + to_string(function)+ ".dat" ,ios::out);
	output<< "RMSE Función: " << function << endl << endl;
    output<<"Diferencias Finitas:" << endl;
    output<<"  Distancia = 0.5: " << error_df[0] << endl;
    output<<"  Distancia = 1  : " << error_df[1] << endl;
    output<<"  Distancia = 5  : " << error_df[2] << endl;
    output<<"  Distancia = 10 : " << error_df[3] << endl;

    output<<"Diferencias Divididas:" << endl;
    output<<"  Distancia = 0.5: " << error_dd[0] << endl;
    output<<"  Distancia = 1  : " << error_dd[1] << endl;
    output<<"  Distancia = 5  : " << error_dd[2] << endl;
    output<<"  Distancia = 10 : " << error_dd[3] << endl;

    output<<"Minimos Cuadrados    :" << endl;
    output<<"  Distancia = 0.5: " << error_ms[0] << endl;
    output<<"  Distancia = 1  : " << error_ms[1] << endl;
    output<<"  Distancia = 5  : " << error_ms[2] << endl;
    output<<"  Distancia = 10 : " << error_ms[3] << endl;

    output<<"Spline Cubico    :" << endl;
    output<<"  Distancia = 0.5: " << error_sc[0] << endl;
    output<<"  Distancia = 1  : " << error_sc[1] << endl;
    output<<"  Distancia = 5  : " << error_sc[2] << endl;
    output<<"  Distancia = 10 : " << error_sc[3] << endl;


	output.close();
}

vector<long double> createVectorXi(long double start, long double end, long double distance){
    vector<long double> result;
	for(long double i = start; i <= end; i = i + distance){
		result.push_back(i);
	}
	return result;
}

vector<long double> createVectorYi(vector<long double> vectorXi, int type){
    vector<long double> result;
    int i;
    long double buffer;
    int length = vectorXi.size();
    for(i=0;i<length;i++){
        buffer = fx(vectorXi[i],type);
        result.push_back(buffer);
    }
    return result;
}

vector<long double> Interpolation::differenceFinite(vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_0_05){
    vector<long double> result;
    int n = vectorXi.size();
    //mat b = mat(n,n);
    //mat c = mat(n,n);
    //cout << "dentro" << endl;
    vector<vector<long double>> b= createMatriz(n,n);
    vector<vector<long double>> c= createMatriz(n,n);
    //double b[n][n];
    //long double c[n][n];
    long double xt;
    long double yi;
    //
    //cout << "hola" << endl;
    
    /*for(int i=0;i<n;i++){
        b[i][0] = vectorYi[i];
        c[i][0] = vectorYi[i];
        
    }
    //

    for(int j=1;j<n;j++){
		for(int i=0;i<n-j;i++){
			b[i][j] = b[i+1][j-1] - b[i][j-1];
            cout << b[i][j] << "= " << b[i+1][j-1] << " - " <<  b[i][j-1] << endl;
		}
	}*/
     for(int i=0;i<n;i++){
        b[i][0] = vectorXi[i];
        b[i][1] = vectorYi[i];
        c[i][0] = vectorXi[i];
        c[i][1] = vectorYi[i];
        //cout << b[i][0] << ", " << b[i][1] << endl;
    }
    //
    
    
    int k = 0;
    for(int j = 2; j < n+1 ; j++){
        k++;
        int i;
        for( i = 0 ; i< n-k;i++){
            b[i][j] = (b[i+1][j-1] - b[i][j-1]);    
            //cout << "b["<< i << "][" << j << "]: " << b[i][j]   << " # "<< endl;
        }
        //cout << endl;
    }

    //
    long double h = vectorXi[1]-vectorXi[0];
	for(int j = 2; j<n;j++){
		for(int i=0; i<n-j;i++){
            //cout << "b[i][j]: " << b[i][j] << "pow(h,j): " << pow(h,j) << "factorial(j):" << factorial(j) << endl;
			c[i][j] = (b[i][j])/((pow(h,j))*factorial(j));
            //cout << "(pow(h,j): " << pow(h,j) << endl; 
            //cout << "factorial(j): " << factorial(j) << endl;
            //cout << endl;
		}
	}
    for (int i = 0 ; i < n; i++){
        //cout << c[0][i] << endl;
    }

    //Calculando los Yi despues de interpolar la funcion
    
    int contador = vectorXi_0_05.size();
    
	for(int i = 0; i<contador; i++){
		xt=1;
		yi = c[0][0];
		for(int j = 0;j<n-1;j++){
			xt = xt*(vectorXi_0_05[i]-vectorXi[j]);
			yi = yi + c[0][j+1]*xt;
		}
        //cout << yi << endl;
        result.push_back(yi);
    }

    return result;
}
vector<vector<long double>> createMatrizDividided(vector<long double> vectorXi, vector<long double> vectorYi){

    int n = vectorXi.size();
    vector<vector<long double>> b = createMatriz(n,n+1);
    for(int i=0;i<n;i++){
        b[i][0] = vectorXi[i];
        b[i][1] = vectorYi[i];
        //cout << b[i][0] << ", " << b[i][1] << endl;
    }
    
    
    int k = 0;
    for(int j = 2; j < n+1 ; j++){
        k++;
        int i;
        for( i = 0 ; i< n-k;i++){
            b[i][j] = (b[i+1][j-1] - b[i][j-1])/(b[i+1][0] -b[i][0]);    
            //b[j][i] = ( (b[j-1][i+1] - b[j-1][i]) / (b[0][i+1] - b[0][i]) );
            cout << "b["<< i << "][" << j << "]: " << b[i][j]   << " # "<< endl;
        }
        //cout << endl;
    }
    return b;
}
vector<long double> evaluateDividided(vector<vector<long double>> b,vector<long double> vectorXi_0_05){
    vector<long double> result;
    int n = b[0].size()-1;
    int contador = vectorXi_0_05.size();
    long double xi;
    long double xt;
    long double yi;
    long double x;
    long double ai;
    long double aux;

	for(int i = 0; i<contador; i++){
		
        xt=1.0;
		yi = b[0][1];
        //yi = b[2][0];
        x = vectorXi_0_05[i];
        //cout << "a0: " << yi << endl;
        
		for(int j = 0;j<n-10;j++){//evaluar el punto en el polinomio interpolado.
            xi = b[j][0];
            ai = b[0][j+1];
            //ai = b[j+2][0];
            //cout <<"x: " <<  x << " # xi: " << xi << " # xta: "<< xt << "# ai: " << ai;
			xt = xt*(x-xi);
			yi = yi + ai*xt;
            //cout << " # xtd: "<< xt<< " # yi: " <<yi << endl;
            
		}
        //cout << endl;
        result.push_back(yi);
        //cout << "i: " << i << endl;
    }
    return result;

}


vector<long double> Interpolation::differenceDivided(vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_0_05){
    vector<vector<long double>> b = createMatrizDividided(vectorXi,vectorYi);
    vector<long double> result = evaluateDividided(b,vectorXi_0_05);
    return result;
}

vector<long double> Interpolation::minimumSquare(vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_0_05, int degree){
    vector<long double> result; //Vector que retorna la funcion
    vector<long double> summations;
    int maxDegree = 2*degree;
    int n = degree+1;
    mat A = mat(n,n); 
    mat B = mat(n,1); 
    long double sum;
    //Se calcula los valores de las diferentes sumatorias 
    for(int i=0 ; i<=maxDegree ; i++){
        sum = 0;
        for(int j=0;j<vectorXi.size();j++){
            sum +=  pow(vectorXi[j],i);
            //cout <<"i,j:" << i <<","<< j <<" ;vectorXi[j]: " << vectorXi[j] << " ;pow: "<< pow(vectorXi[j],i)<< endl;
        }
        //cout << endl;
        summations.push_back(sum);
    }
    //Se llena la matriz A con los valores calculados (sumatorias).
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            A(i,j)= summations[i+j];
            //cout << summations[i+j] << ", ";
        }
        //cout << endl ;
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
          //cout << B(i,0) << endl;
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
    long double resultYi;
    for (int i = 0; i < size; ++i)
    {
        resultYi = 0;
        for (int j = 0; j < n ; j++){
            //cout <<  "C(j,0): " << C(j,0) << " # pow(vectorXi_0_05[i],j): " << pow(vectorXi_0_05[i],j); 
            resultYi += C(j,0) * pow(vectorXi_0_05[i],j);
            //cout << " # resultYi: " << resultYi << endl; 
            //cout << j << ", ";
        }
        //cout <<"i: " << i  << "val:" << resultYi<< endl;
        result.push_back(resultYi);
    }
    return result;
   
}
vector<long double> Interpolation::cubicSpline          (vector<long double> vectorXi, vector<long double> vectorYi, vector<long double> vectorXi_005){
    int n = vectorXi.size();
    vector<long double> h;
    vector<long double> result;
    long double hi;
    int i,j;

    //Se llena el vector h con las distancias entre los puntos
    for( i = 0;i < n-1; i++){
        hi = vectorXi[i+1] - vectorXi[i];
        h.push_back(hi);
    }
    //se inicializan las matrices
	vector<vector<long double>> A = createMatriz(n-2, n-2);
    vector<vector<long double>> B = createMatriz(n-2,1);

    //se llena la matriz A
	j = 0;
	A[0][0] = 2*(h[0] + h[1]);
	A[0][1] = h[1];
		
    for(i = 1; i < n-3;i++){
		A[i][j] = h[i];
		A[i][j+1] = 2*(h[i] + h[i+1]);
		A[i][j+2] = h[i+1];
		j++; 
	}
	A[n-3][n-3] = 2*(h[n-3] + h[n-2]);
	A[n-3][n-4] = h[n-3];

    //se llena la matriz B
	for(i=0;i<n-2;i++){
		B[i][0] = 6*( ( (vectorYi[i+2] - vectorYi[i+1]) / (vectorXi[i+2] - vectorXi[i+1]) ) - ( (vectorYi[i+1] - vectorYi[i])/ (vectorXi[i+1] - vectorXi[i]) ) );	
	}

    //resolver sistema ecuaciones con la funcion de armadillo "solve":
    mat T(n-2, n-2);
    mat U(n-2,1);
    for(i = 0; i < n-2;i++){
		for(j = 0; j < n-2;j++){
			T(i,j) = A[i][j]; 	
		}
        U(i,0) = B[i][0];
	}


	vec X1 = solve(T, U);


    //interpolando
    i=0;
    long double a,b,c,d,e,Rj;
	
    while(i<vectorXi_005.size()){
		for(j=0;j<n-1;j++){
			if(vectorXi_005[i]>= vectorXi[j] && vectorXi_005[i] < vectorXi[j+1]){
				break;
			}
		}
		if(j ==0){
			a = 0 * (vectorXi[j+1] - vectorXi_005[i])*(vectorXi[j+1] - vectorXi_005[i])*(vectorXi[j+1] - vectorXi_005[i]) / 6*h[j];
            b = (vectorXi_005[i] - vectorXi[j])*(vectorXi_005[i] - vectorXi[j])*(vectorXi_005[i] - vectorXi[j]) * X1[j] / 6*h[j];
            c = ( ( (vectorYi[j+1] - vectorYi[j]) / h[j]) - ((X1[j] - 0) * h[j] /6)) * vectorXi_005[i];
            d = ( (vectorYi[j]*vectorXi[j+1]) - (vectorYi[j+1]*vectorXi[j])) / h[j] ;
            e = h[j]*(( (vectorXi[j]*X1[j]) - (vectorXi[j+1]* 0 )) / 6);
		}

		if(j == n-2){
			a = X1[j-1] * (vectorXi[j+1] - vectorXi_005[i])*(vectorXi[j+1] - vectorXi_005[i])*(vectorXi[j+1] - vectorXi_005[i]) / 6*h[j];
			b = (vectorXi_005[i] - vectorXi[j])*(vectorXi_005[i] - vectorXi[j])*(vectorXi_005[i] - vectorXi[j]) * 0 / 6*h[j];
			c = ( ( (vectorYi[j+1] - vectorYi[j]) / h[j]) - ((0 - X1[j-1]) * h[j] /6)) * vectorXi_005[i];
			d = ( (vectorYi[j]*vectorXi[j+1]) - (vectorYi[j+1]*vectorXi[j])) / h[j] ;
			e = h[j]*(( (vectorXi[j]*0) - (vectorXi[j+1]*X1[j-1])) / 6);
		}
		
		if(j != n-2 && j != 0){
			a = X1[j-1] * (vectorXi[j+1] - vectorXi_005[i])*(vectorXi[j+1] - vectorXi_005[i])*(vectorXi[j+1] - vectorXi_005[i]) / 6*h[j];
			b = (vectorXi_005[i] - vectorXi[j])*(vectorXi_005[i] - vectorXi[j])*(vectorXi_005[i] - vectorXi[j]) * X1[j] / 6*h[j];
			c = ( ( (vectorYi[j+1] - vectorYi[j]) / h[j]) - ((X1[j] - X1[j-1]) * h[j] /6)) * vectorXi_005[i];
			d = ( (vectorYi[j]*vectorXi[j+1]) - (vectorYi[j+1]*vectorXi[j])) / h[j] ;
			e = h[j]*(( (vectorXi[j]*X1[j]) - (vectorXi[j+1]*X1[j-1])) / 6);
		}
		Rj = a+b+c+d+e;
		result.push_back(Rj);
		i++;
	}
    return result;


}


long double Interpolation::RMSE(vector<long double> vectorYiIntepolate, vector<long double> vectorYiRial){
	long double size = vectorYiRial.size();
	long double result = 0;
	for(int i = 0; i<size;i++){
		result += pow(vectorYiRial[i]-vectorYiIntepolate[i],2.0);
	}
	result = sqrt(result/size);
	return result;
}
