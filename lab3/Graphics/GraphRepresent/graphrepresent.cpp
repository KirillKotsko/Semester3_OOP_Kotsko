#include "graphrepresent.h"
#include "ui_graphrepresent.h"

GraphRepresent::GraphRepresent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphRepresent)
{
    ui->setupUi(this);
    QVector<double> x(2001), y(2001);
    for (int i=0; i<2001; ++i)
    {
      x[i] = i/50.0 - 20;
      y[i] = log(x[i]);
    }
    // create graph and assign data to it:
    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->customPlot->xAxis->setRange(-20, 20);
    ui->customPlot->yAxis->setRange(-20, 20);
    ui->customPlot->replot();
}

GraphRepresent::~GraphRepresent()
{
    delete ui;
}
