#ifndef FUNCTION_H
#define FUNCTION_H




class StrategyFunction
{
    public:
        virtual double execute(double x) = 0;
};

class Fx: public StrategyFunction
{
    public:
        virtual double execute(double x);
};

class Gx: public StrategyFunction
{
    public:
        virtual double execute(double x);
};

class Function
{
    private:
        StrategyFunction *_strategy;

    public:
        Function(StrategyFunction *strategy);

        void set_strategy(StrategyFunction *strategy);

        double execute(double x);
};


#endif