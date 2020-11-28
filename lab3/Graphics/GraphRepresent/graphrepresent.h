/**
*   @file graphrepresent.h
*	@author Kirill Kotsko
*	@version 1.1
*/
#ifndef GRAPHREPRESENT_H
#define GRAPHREPRESENT_H

#include <QWidget>
#include "./qcustomplot.h"
#include "FunctionGraph/functiongraph.h"

namespace Ui {
class GraphRepresent;
}

/**
 * @brief The GraphRepresent class
 *
 * Form which represent graphic of function
 */
class GraphRepresent : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief constructor
     *
     * @param QWidget parent
     */
    explicit GraphRepresent(QWidget *parent = nullptr);

    /**
     * @brief destructor
     */
    ~GraphRepresent();

    /**
     * @brief set the function
     * @param function
     */
    void setFunc(FunctionGraph f);

    /**
     * @brief set mode of representing function, which depends from this function
     *
     * @param argument
     */
    void setMode(int arg);

    /**
     * @brief draws a graph according to the 1 mode
     */
    void BuildV1();

    /**
     * @brief draws a graph according to the 2 mode
     */
    void BuildV2();

    /**
     * @brief get mode
     * @return mode
     */
    int getMode();

private:

    /**
     * @brief user interface of the form
     */
    Ui::GraphRepresent *ui;

    /**
     * @brief function to work with
     */
    FunctionGraph func;

    /**
     * @brief object for vertical line
     */
    QCPCurve *verticalLine;

    /**
     * @brief Plot Point Tracer
     */
    QCPItemTracer *tracer;

    /**
     * @brief mode of representing function, which depends from this function (mode 1 and 2)
     */
    int mode;

private slots:

    /**
     * @brief mouse event signals from the chart canvas to slots for their processing
     * @param event
     */
    void slotMousePress(QMouseEvent * event);

    /**
     * @brief mouse event signals from the chart canvas to slots for their processing
     * @param event
     */
    void slotMouseMove(QMouseEvent * event);

    /**
     * @brief exit from the form
     */
    void on_btnExit_clicked();
};

#endif // GRAPHREPRESENT_H
