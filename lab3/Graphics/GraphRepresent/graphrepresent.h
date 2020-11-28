#ifndef GRAPHREPRESENT_H
#define GRAPHREPRESENT_H

#include <QWidget>
#include "./qcustomplot.h"
#include "FunctionGraph/functiongraph.h"

namespace Ui {
class GraphRepresent;
}

class GraphRepresent : public QWidget
{
    Q_OBJECT

public:
    explicit GraphRepresent(QWidget *parent = nullptr);
    ~GraphRepresent();

    void setFunc(FunctionGraph f);

    void setMode(int arg);

    int getMode();

    void BuildV1();
    void BuildV2();

private:
    Ui::GraphRepresent *ui;
    FunctionGraph func;
    QCPCurve *verticalLine;
    QCPItemTracer *tracer;
    int mode;
private slots:
    void slotMousePress(QMouseEvent * event);
    void slotMouseMove(QMouseEvent * event);
    void on_btnExit_clicked();
};

#endif // GRAPHREPRESENT_H
