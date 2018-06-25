#include <iostream>
#include <vector>
#include "interpolation.h"

using namespace std;

class Case
{
    private:
        int _start;
        int _end;
        int _function;
        double _distance;
        double _distanceRial;
        double _error;
        vector<double> _vectorXi;
        vector<double> _vectorYi;
        vector<double> _vectorXiRial;
        vector<double> _vectorYiRial;
        vector<double> _vectorDF; // Resultado de diferencias finitas;
        vector<double> _vectorDD; // Resultado de diferencias divididas;
        vector<double> _vectorMS; // Resultado de minimos cuadrados;
        vector<double> _vectorCS; // Resultado de cubic spline;
        Interpolation _interpolation;
        
    public:
        Case(int start,int end, double distance, double distanceRial,int function);
        void run();
};