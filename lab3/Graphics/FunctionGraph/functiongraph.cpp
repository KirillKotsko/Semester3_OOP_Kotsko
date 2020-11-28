#include "functiongraph.h"

void FunctionGraph::setA(double _a)
{
    a = _a;
}

void FunctionGraph::setB(double _b)
{
    b = _b;
}

void FunctionGraph::setC(double _c)
{
    c = _c;
}

void FunctionGraph::setFunctionId(int _function_id)
{
    function_id = _function_id;
}

double FunctionGraph::EvaluateFunc(double x)
{
    switch (function_id)
    {
    case 0:
        return (a*x+c)/(-b);
        break;
    case 1:
        return a*pow(x,2)+b*x+c;
        break;
    case 2:
        return pow(a,x)+b;
        break;
    case 3:
        return c*(log(b*x)/log(a));
        break;
    case 4:
        return (sin(a*x)+ cos(b*x))/c;
        break;
    case 5:
        return sqrt((pow(a,2)*pow(b,2)-pow(b,2)*pow(x,2))/pow(a,2));
        break;
    case 6:
        return sqrt((pow(b,2)*pow(x,2)-pow(a,2)*pow(b,2))/pow(a,2));
        break;
    case 7:
        return sqrt((pow(x,c)+b*pow(x,2))/a);
        break;
    }

}
