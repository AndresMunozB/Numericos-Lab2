#include "case.h"

Case::Case(int start,int end, double distance, double distanceRial,int function){
    _start = start;
    _end = end;
    _function = function;
    _distance = distance;
    _distanceRial = distanceRial;
    _vectorXi = createVectorXi(start,end,distance);
    _vectorXiRial = createVectorXi(start,end,distanceRial);
    _vectorYi = createVectorYi(_vectorXi,function);
    _vectorYi = createVectorYi(_vectorXiRial,function);
    _interpolation = Interpolation();
}
void run(){
    //Hacer todo lo necesario para ejecutar los diferentes metodos entregando el resultado;
}