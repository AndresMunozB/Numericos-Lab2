#include "interpolation.h"

vector<double> createVectorXi(double start, double end, double distance){
    vector<double> result;
    double i;
	for(i = start; i <= end; i = i + distance){
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
    return result;
}
vector<double> MinimumSquare::interpolate(vector<double> vectorXi, vector<double> vectorYi, vector<double> vectorXi_005){
    vector<double> result;
    return result;
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



