#include "function.h"
#include <math.h>


double Fx::execute(double x){
    double result = exp(x)+x - 2;
    return result;
}
double Gx::execute(double x){
    double result = pow(x,3)+4*pow(x,2)-10*x+2;
    return result;   
}

Function::Function(StrategyFunction *strategy):_strategy(strategy){}
void   Function::set_strategy(StrategyFunction *strategy){_strategy = strategy;}
double Function::execute(double x){return _strategy->execute(x);}
