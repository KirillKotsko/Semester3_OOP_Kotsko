#ifndef FUNCTIONGRAPH_H
#define FUNCTIONGRAPH_H

#include <cmath>

class FunctionGraph
{
public:
    FunctionGraph(double _a = 0, double _b = 0, double _c = 0, int _function_id = 0) :
        a(_a), b(_b), c(_c), function_id(_function_id) {}

    void setA(double _a);
    void setB(double _b);
    void setC(double _c);
    void setFunctionId(int _function_id);

    double EvaluateFunc(double x);

private:
    double a,b,c;
    int function_id;
};

#endif // FUNCTIONGRAPH_H
