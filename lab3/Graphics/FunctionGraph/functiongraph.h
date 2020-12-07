/**
*   @file functiongraph.h
*	@author Kirill Kotsko
*	@version 1.1
*/
#ifndef FUNCTIONGRAPH_H
#define FUNCTIONGRAPH_H

#include <cmath>

/**
 * @brief The FunctionGraph class
 *
 * Storage information about function
 */
class FunctionGraph
{
public:

    /**
     * @brief constructor
     * @param a
     * @param b
     * @param c
     * @param function id
     */
    FunctionGraph(double _a = 0, double _b = 0, double _c = 0, int _function_id = 0) :
        a(_a), b(_b), c(_c), function_id(_function_id) {}

    /**
     * @brief set a value
     * @param a
     */
    void setA(double _a);

    /**
     * @brief set b value
     * @param b
     */
    void setB(double _b);

    /**
     * @brief set c value
     * @param c
     */
    void setC(double _c);

    /**
     * @brief set function id
     * @param function id
     */
    void setFunctionId(int _function_id);

    /**
     * @brief evaluate the function according to the function id
     * @param x
     * @return result
     */
    double EvaluateFunc(double x);

    /**
     * @brief get function id
     * @return function id
     */
    int getFunctionId();

private:

    /**
     * @brief coefficient values of function
     */
    double a,b,c;

    /**
     * @brief id of the function
     */
    int function_id;
};

#endif // FUNCTIONGRAPH_H
