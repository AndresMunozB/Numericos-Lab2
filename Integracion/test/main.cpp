#include <iostream>
#include <string>
#include "../interpolacion/interpolation.h"
#include "../integral/integral.h"

using namespace std;
class Data
{
    public:
        vector<long double> vectorXi_0_5;
        vector<long double> vectorXi_1  ;
        vector<long double> vectorXi_5  ;
        vector<long double> vectorXi_10 ;

        vector<long double> vectorYi_0_5_f1;
        vector<long double> vectorYi_1_f1  ;
        vector<long double> vectorYi_5_f1  ;
        vector<long double> vectorYi_10_f1 ;

        vector<long double> vectorYi_0_5_f2;
        vector<long double> vectorYi_1_f2  ;
        vector<long double> vectorYi_5_f2  ;
        vector<long double> vectorYi_10_f2 ;

        vector<long double> vectorXiRial;
        vector<long double> vectorYiRial_f1;
        vector<long double> vectorYiRial_f2;
};

vector<vector<long double>> executeDF(int function, int save, Data data){

    vector<long double> result_0_5;
    vector<long double> result_1;
    vector<long double> result_5;
    vector<long double> result_10;
    vector<vector<long double>> result;

    Interpolation interpolation = Interpolation();
    if(function == 1){
        result_0_5 = interpolation.differenceFinite(data.vectorXi_0_5,data.vectorYi_0_5_f1,data.vectorXiRial);
        result_1   = interpolation.differenceFinite(data.vectorXi_1  ,data.vectorYi_1_f1  ,data.vectorXiRial);
        result_5   = interpolation.differenceFinite(data.vectorXi_5  ,data.vectorYi_5_f1  ,data.vectorXiRial);
        result_10  = interpolation.differenceFinite(data.vectorXi_10 ,data.vectorYi_10_f1 ,data.vectorXiRial);
    }
    else if(function == 2){
        result_0_5 = interpolation.differenceFinite(data.vectorXi_0_5,data.vectorYi_0_5_f2,data.vectorXiRial);
        result_1   = interpolation.differenceFinite(data.vectorXi_1  ,data.vectorYi_1_f2  ,data.vectorXiRial);
        result_5   = interpolation.differenceFinite(data.vectorXi_5  ,data.vectorYi_5_f2  ,data.vectorXiRial);
        result_10  = interpolation.differenceFinite(data.vectorXi_10 ,data.vectorYi_10_f2 ,data.vectorXiRial);
    }
    

    result.push_back(result_0_5);
    result.push_back(result_1);
    result.push_back(result_5);
    result.push_back(result_10);

    if(save){
        saveInterpolationResult("../resultados/DF/DF_f" + to_string(function) + "_0_5.dat",data.vectorXiRial,result_0_5);
        saveInterpolationResult("../resultados/DF/DF_f" + to_string(function) + "_1.dat"  ,data.vectorXiRial,result_1);
        saveInterpolationResult("../resultados/DF/DF_f" + to_string(function) + "_5.dat"  ,data.vectorXiRial,result_5);
        saveInterpolationResult("../resultados/DF/DF_f" + to_string(function) + "_10.dat" ,data.vectorXiRial,result_10);
    }
    return result;
}

vector<vector<long double>> executeDD(int function, int save, Data data){



    vector<long double> result_0_5;
    vector<long double> result_1;
    vector<long double> result_5;
    vector<long double> result_10;

    vector<vector<long double>> result;
    Interpolation interpolation = Interpolation();
    
    if(function == 1){
        result_0_5 = interpolation.differenceDivided(data.vectorXi_0_5,data.vectorYi_0_5_f1,data.vectorXiRial);
        result_1   = interpolation.differenceDivided(data.vectorXi_1  ,data.vectorYi_1_f1  ,data.vectorXiRial);
        result_5   = interpolation.differenceDivided(data.vectorXi_5  ,data.vectorYi_5_f1  ,data.vectorXiRial);
        result_10  = interpolation.differenceDivided(data.vectorXi_10 ,data.vectorYi_10_f1 ,data.vectorXiRial);
    }
    else if(function == 2){
        result_0_5 = interpolation.differenceDivided(data.vectorXi_0_5,data.vectorYi_0_5_f2,data.vectorXiRial);
        result_1   = interpolation.differenceDivided(data.vectorXi_1  ,data.vectorYi_1_f2  ,data.vectorXiRial);
        result_5   = interpolation.differenceDivided(data.vectorXi_5  ,data.vectorYi_5_f2  ,data.vectorXiRial);
        result_10  = interpolation.differenceDivided(data.vectorXi_10 ,data.vectorYi_10_f2 ,data.vectorXiRial);
    }

    result.push_back(result_0_5);
    result.push_back(result_1);
    result.push_back(result_5);
    result.push_back(result_10);

    if(save){
        saveInterpolationResult("../resultados/DD/DD_f" + to_string(function) + "_0_5.dat",data.vectorXiRial,result_0_5);
        saveInterpolationResult("../resultados/DD/DD_f" + to_string(function) + "_1.dat"  ,data.vectorXiRial,result_1);
        saveInterpolationResult("../resultados/DD/DD_f" + to_string(function) + "_5.dat"  ,data.vectorXiRial,result_5);
        saveInterpolationResult("../resultados/DD/DD_f" + to_string(function) + "_10.dat" ,data.vectorXiRial,result_10);
    }
    return result;
}

vector<vector<long double>> executeMS(int function, int save, Data data){


    vector<long double> result_0_5;
    vector<long double> result_1;
    vector<long double> result_5;
    vector<long double> result_10;

    vector<vector<long double>> result;
    Interpolation interpolation = Interpolation();
    
    int degree = 0;
    if(function == 1){
        degree = 40;
    }
    else if(function == 2){
        degree  = 15;
    }

    if(function == 1){
        result_0_5 = interpolation.minimumSquare(data.vectorXi_0_5,data.vectorYi_0_5_f1,data.vectorXiRial,degree);
        result_1   = interpolation.minimumSquare(data.vectorXi_1  ,data.vectorYi_1_f1  ,data.vectorXiRial,degree);
        result_5   = interpolation.minimumSquare(data.vectorXi_5  ,data.vectorYi_5_f1  ,data.vectorXiRial,degree);
        result_10  = interpolation.minimumSquare(data.vectorXi_10 ,data.vectorYi_10_f1 ,data.vectorXiRial,degree);
    }
    else if(function == 2){
        result_0_5 = interpolation.minimumSquare(data.vectorXi_0_5,data.vectorYi_0_5_f2,data.vectorXiRial,degree);
        result_1   = interpolation.minimumSquare(data.vectorXi_1  ,data.vectorYi_1_f2  ,data.vectorXiRial,degree);
        result_5   = interpolation.minimumSquare(data.vectorXi_5  ,data.vectorYi_5_f2  ,data.vectorXiRial,degree);
        result_10  = interpolation.minimumSquare(data.vectorXi_10 ,data.vectorYi_10_f2 ,data.vectorXiRial,degree);
    }

    result.push_back(result_0_5);
    result.push_back(result_1);
    result.push_back(result_5);
    result.push_back(result_10);

    if(save){
        saveInterpolationResult("../resultados/MS/MS_f" + to_string(function) + "_0_5.dat",data.vectorXiRial,result_0_5);
        saveInterpolationResult("../resultados/MS/MS_f" + to_string(function) + "_1.dat"  ,data.vectorXiRial,result_1);
        saveInterpolationResult("../resultados/MS/MS_f" + to_string(function) + "_5.dat"  ,data.vectorXiRial,result_5);
        saveInterpolationResult("../resultados/MS/MS_f" + to_string(function) + "_10.dat" ,data.vectorXiRial,result_10);
    }
    return result;
}

vector<vector<long double>> executeCS(int function, int save, Data data){

    vector<long double> result_0_5;
    vector<long double> result_1;
    vector<long double> result_5;
    vector<long double> result_10;

    vector<vector<long double>> result;
    Interpolation interpolation = Interpolation();
    
     if(function == 1){
        result_0_5 = interpolation.cubicSpline(data.vectorXi_0_5,data.vectorYi_0_5_f1,data.vectorXiRial);
        result_1   = interpolation.cubicSpline(data.vectorXi_1  ,data.vectorYi_1_f1  ,data.vectorXiRial);
        result_5   = interpolation.cubicSpline(data.vectorXi_5  ,data.vectorYi_5_f1  ,data.vectorXiRial);
        result_10  = interpolation.cubicSpline(data.vectorXi_10 ,data.vectorYi_10_f1 ,data.vectorXiRial);
    }
    else if(function == 2){
        result_0_5 = interpolation.cubicSpline(data.vectorXi_0_5,data.vectorYi_0_5_f2,data.vectorXiRial);
        result_1   = interpolation.cubicSpline(data.vectorXi_1  ,data.vectorYi_1_f2  ,data.vectorXiRial);
        result_5   = interpolation.cubicSpline(data.vectorXi_5  ,data.vectorYi_5_f2  ,data.vectorXiRial);
        result_10  = interpolation.cubicSpline(data.vectorXi_10 ,data.vectorYi_10_f2 ,data.vectorXiRial);
    }
    result.push_back(result_0_5);
    result.push_back(result_1);
    result.push_back(result_5);
    result.push_back(result_10);

    if(save){
        saveInterpolationResult("../resultados/CS/CS_f" + to_string(function) + "_0_5.dat",data.vectorXiRial,result_0_5);
        saveInterpolationResult("../resultados/CS/CS_f" + to_string(function) + "_1.dat"  ,data.vectorXiRial,result_1);
        saveInterpolationResult("../resultados/CS/CS_f" + to_string(function) + "_5.dat"  ,data.vectorXiRial,result_5);
        saveInterpolationResult("../resultados/CS/CS_f" + to_string(function) + "_10.dat" ,data.vectorXiRial,result_10);
    }
    return result;
}

vector<long double> calculateErrors(vector<vector<long double>> results, vector<long double> vectorYiRial){
    vector<long double> errors;
    Interpolation interpolation = Interpolation();
    errors.push_back(interpolation.RMSE(results[0],vectorYiRial));
    errors.push_back(interpolation.RMSE(results[1],vectorYiRial));
    errors.push_back(interpolation.RMSE(results[2],vectorYiRial));
    errors.push_back(interpolation.RMSE(results[3],vectorYiRial));
    return errors;
}

void printMenu(){
    cout << "       MENU" << endl << endl;
    cout << "1) Método de Diferencias Finitas   (DF)." << endl;
    cout << "2) Método de Diferencias Divididas (DD)." << endl;
    cout << "3) Método de Mínimos Cuadrados     (MS)." << endl;
    cout << "4) Método de Spline Cubico         (CS)." << endl;
    cout << "5) Calcular RMSE para todos los métodos." << endl;
    cout << "6) Calculo integral Trapesio y Simpson con error relativo." << endl;
    cout << "7) Realizar todas las acciones anteriores.(TODO)" << endl;
    cout << "8) Salir." << endl;
}

void printFunction(){
    cout << "       Seleccione la función: " << endl<< endl;;
    cout << "1) exp(x)+ x - 2" << endl;
    cout << "2) pow(x,3)+4*pow(x,2)-5*x+2" << endl;
    cout << "3) Ambas" << endl;
    cout << "Nota: Al ingresar una opción invalida, el programa retorna al MENU" << endl;
}
void pause(){
    cout<<"Presione ENTER para continuar..";
    cin.ignore(1000,'\n');
    cin.get();
}


void menu(){
    Data data = Data();
    data.vectorXi_0_5  = createVectorXi(-200.0,200.0,0.5);
    data.vectorXi_1    = createVectorXi(-200.0,200.0,1);
    data.vectorXi_5    = createVectorXi(-200.0,200.0,5);
    data.vectorXi_10   = createVectorXi(-200.0,200.0,10);

    data.vectorYi_0_5_f1  = createVectorYi(data.vectorXi_0_5,1);
	data.vectorYi_1_f1    = createVectorYi(data.vectorXi_1  ,1);
	data.vectorYi_5_f1    = createVectorYi(data.vectorXi_5  ,1);
	data.vectorYi_10_f1   = createVectorYi(data.vectorXi_10 ,1);

    data.vectorYi_0_5_f2  = createVectorYi(data.vectorXi_0_5,2);
	data.vectorYi_1_f2    = createVectorYi(data.vectorXi_1  ,2);
	data.vectorYi_5_f2    = createVectorYi(data.vectorXi_5  ,2);
	data.vectorYi_10_f2   = createVectorYi(data.vectorXi_10 ,2);

    data.vectorXiRial  = createVectorXi(-200.0,200.0,0.05);
    data.vectorYiRial_f1  = createVectorYi(data.vectorXiRial,1);
    data.vectorYiRial_f2  = createVectorYi(data.vectorXiRial,2);
    saveInterpolationResult("../resultados/Real_f" + to_string(1)+".dat",data.vectorXiRial,data.vectorYiRial_f1);
    saveInterpolationResult("../resultados/Real_f" + to_string(2)+".dat",data.vectorXiRial,data.vectorYiRial_f2);

    vector<vector<long double>> resultDF;
    vector<vector<long double>> resultDD;
    vector<vector<long double>> resultMS;
    vector<vector<long double>> resultCS;

    vector<long double> error_df;// = calculateErrors(resultDF,data.vectorYiRial); //RMSE Diferencias Finitas.
    vector<long double> error_dd;// = calculateErrors(resultDD,data.vectorYiRial); //RMSE Diferencias Divididas.
    vector<long double> error_ms;// = calculateErrors(resultMS,data.vectorYiRial); //RMSE Minimos Cuadrados.
    vector<long double> error_cs;// = calculateErrors(resultCS,data.vectorYiRial); //RMSE Spline Cubico.

    string option = "";
    string optionf = "";
    string key;
    system("clear");


    while(1){
        printMenu();
        cout << endl << "Opción: ";
        cin >> option;
        

        if (option.compare("1") == 0){
            system("clear");
            cout << "       Método de Diferencias Finitas (DF)." << endl << endl;
            cout << "   Primera función:" << endl;
            cout << "> Interpolando con DF.." << endl;;
            executeDF(1,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "   Segunda función:" << endl;
            cout << "> Interpolando con DF.." << endl;
            executeDF(2,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "Los archivos resultantes estan guardados en: /resultados/DF" << endl;
            pause();
            system("clear");
            

        }
        else if(option.compare("2") == 0){
            system("clear");
            cout << "       Método de Diferencias Divididas (DD)." << endl << endl;
            cout << "   Primera función:" << endl;
            cout << "> Interpolando con DD.." << endl;;
            executeDD(1,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "   Segunda función:" << endl;
            cout << "> Interpolando con DD.." << endl;
            executeDD(2,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "Los archivos resultantes estan guardados en: /resultados/DD" << endl;
            pause();
            system("clear");
        }
        else if(option.compare("3") == 0){
            system("clear");
            cout << "       Método de Mínimos Cuadrados (MS)." << endl << endl;
            cout << "   Primera función:" << endl;
            cout << "> Interpolando con MS.." << endl;;
            executeMS(1,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "   Segunda función:" << endl;
            cout << "> Interpolando con MS.." << endl;
            executeMS(2,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "Los archivos resultantes estan guardados en: /resultados/MS" << endl;
            pause();
            system("clear");
        }
        else if(option.compare("4") == 0){
            system("clear");
            cout << "       Método de Spline Cubico (CS)." << endl << endl;
            cout << "   Primera función:" << endl;
            cout << "> Interpolando con MS.." << endl;;
            executeCS(1,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "   Segunda función:" << endl;
            cout << "> Interpolando con MS.." << endl;
            executeCS(2,1,data);
            cout << "> Interpolacion realizada con éxito." << endl << endl;
            cout << "Los archivos resultantes estan guardados en: /resultados/MS" << endl;
            pause();
            system("clear");
        }
        else if(option.compare("5") == 0){
            system("clear");
            cout << "       Calcular RMSE para todos los métodos." << endl<< endl;
            cout << "> Calculando RMSE para f1 con metodo DF..." << endl;
            resultDF = executeDF(1,0,data);
            error_df = calculateErrors(resultDF,data.vectorYiRial_f1); //RMSE Diferencias Finitas.
            cout << "> Calculando RMSE para f1 con metodo DD..." << endl;
            resultDD = executeDD(1,0,data);
            error_dd = calculateErrors(resultDD,data.vectorYiRial_f1); //RMSE Diferencias Divididas.
            cout << "> Calculando RMSE para f1 con metodo MS..." << endl;
            resultMS = executeMS(1,0,data);
            error_ms = calculateErrors(resultMS,data.vectorYiRial_f1); //RMSE Minimos Cuadrados.
            cout << "> Calculando RMSE para f1 con metodo CS..." << endl;
            resultCS = executeCS(1,0,data);
            error_cs = calculateErrors(resultCS,data.vectorYiRial_f1); //RMSE Spline Cubico.

            saveInterpolationError("../resultados/_Errores/RMSE_F" + to_string(1)+ ".dat",1,error_df,error_dd,error_ms,error_cs);

            /*error_df.clear();
            error_dd.clear();
            error_ms.clear();
            error_cs.clear();

            resultDF.clear();
            resultDD.clear();
            resultMS.clear();
            resultCS.clear();*/

            cout << "> Calculando RMSE para f2 con metodo DF..." << endl;
            resultDF = executeDF(2,0,data);
            error_df = calculateErrors(resultDF,data.vectorYiRial_f2); //RMSE Diferencias Finitas.
            cout << "> Calculando RMSE para f2 con metodo DD..." << endl;
            resultDD = executeDD(2,0,data);
            error_dd = calculateErrors(resultDD,data.vectorYiRial_f2); //RMSE Diferencias Divididas.
            cout << "> Calculando RMSE para f2 con metodo MS..." << endl;
            resultMS = executeMS(2,0,data);
            error_ms = calculateErrors(resultMS,data.vectorYiRial_f2); //RMSE Minimos Cuadrados.
            cout << "> Calculando RMSE para f2 con metodo CS..." << endl;
            resultCS = executeCS(2,0,data);
            error_cs = calculateErrors(resultCS,data.vectorYiRial_f2); //RMSE Spline Cubico.
            
            saveInterpolationError("../resultados/_Errores/RMSE_F" + to_string(2)+ ".dat",2,error_df,error_dd,error_ms,error_cs);
            cout << endl;
            cout << "Los archivos resultantes estan guardados en: /resultados/_Errores" << endl;

            pause();
            system("clear");
            
        }
        else if(option.compare("7") == 0){
            system("clear");
            cout << "       Realizar todas las acciones (TODO)." << endl<< endl;
            
            cout << "> Interpolando con DF para f1.." << endl;;
            resultDF = executeDF(1,1,data);
            cout << "> Calculando RMSE para f1 con metodo DF..." << endl;
            error_df = calculateErrors(resultDF,data.vectorYiRial_f1); //RMSE Diferencias Finitas.
            
            cout << "> Interpolando con DD para f1.." << endl;;
            resultDD = executeDD(1,1,data);
            cout << "> Calculando RMSE para f1 con metodo DD..." << endl;
            error_dd = calculateErrors(resultDD,data.vectorYiRial_f1); //RMSE Diferencias Divididas.
            
                        
            cout << "> Interpolando con MS para f1.." << endl;;
            resultMS = executeMS(1,1,data);
            cout << "> Calculando RMSE para f1 con metodo MS..." << endl;
            error_ms = calculateErrors(resultMS,data.vectorYiRial_f1); //RMSE Minimos Cuadrados.
            cout << "> Interpolando con CS para f1.." << endl;;
            resultCS = executeCS(1,1,data);
            cout << "> Calculando RMSE para f1 con metodo CS..." << endl;
            error_cs = calculateErrors(resultCS,data.vectorYiRial_f1); //RMSE Spline Cubico.

            saveInterpolationError("../resultados/_Errores/RMSE_F" + to_string(1)+ ".dat",1,error_df,error_dd,error_ms,error_cs);

            error_df.clear();
            error_dd.clear();
            error_ms.clear();
            error_cs.clear();

            resultDF.clear();
            resultDD.clear();
            resultMS.clear();
            resultCS.clear();

            cout << "> Interpolando con DF para f2.." << endl;;
            resultDF = executeDF(2,1,data);
            cout << "> Calculando RMSE para f2 con metodo DF..." << endl;
            error_df = calculateErrors(resultDF,data.vectorYiRial_f2); //RMSE Diferencias Finitas.
            cout << "> Interpolando con DD para f2.." << endl;;
            resultDD = executeDD(2,1,data);
            cout << "> Calculando RMSE para f2 con metodo DD..." << endl;
            error_dd = calculateErrors(resultDD,data.vectorYiRial_f2); //RMSE Diferencias Divididas.
            cout << "> Interpolando con MS para f2.." << endl;;
            resultMS = executeMS(2,1,data);
            cout << "> Calculando RMSE para f2 con metodo MS..." << endl;
            error_ms = calculateErrors(resultMS,data.vectorYiRial_f2); //RMSE Minimos Cuadrados.
            cout << "> Interpolando con CS para f2.." << endl;;
            resultCS = executeCS(2,1,data);
            cout << "> Calculando RMSE para f2 con metodo CS..." << endl;
            error_cs = calculateErrors(resultCS,data.vectorYiRial_f2); //RMSE Spline Cubico.
            
            saveInterpolationError("../resultados/_Errores/RMSE_F" + to_string(2)+ ".dat",2,error_df,error_dd,error_ms,error_cs);
            cout << endl;
            cout << "Los archivos resultantes estan guardados en: /resultados" << endl;

            pause();
            system("clear");

        }
        else if(option.compare("8") == 0){
            system("clear");
            break;

        }
        else{
            cout <<"Error: Opción inválida" << endl;
        }


    }


    
}
int main(int argc, char *argv[])
{
    //execute(1);
    //execute(2);
    menu();
    return 0;
}

