#include "graphrepresent.h"
#include "ui_graphrepresent.h"

GraphRepresent::GraphRepresent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphRepresent)
{
    ui->setupUi(this);
}

void GraphRepresent::setFunc(FunctionGraph f){
    func = f;
}

void GraphRepresent::setMode(int arg){
    mode = arg;
}

int GraphRepresent::getMode(){
    return mode;
}

void GraphRepresent::BuildV1(){
    ui->customPlot->show();
    QVector<double> x(2001), y(2001);
    for (int i=0; i<2001; ++i)
    {
      x[i] = i/50.0 - 20;
      y[i] = func.EvaluateFunc(x[i]);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(-20, 20);
    ui->customPlot->yAxis->setRange(-20, 20);

    verticalLine = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);

    connect(ui->customPlot, &QCustomPlot::mousePress, this, &GraphRepresent::slotMousePress);
    connect(ui->customPlot, &QCustomPlot::mouseMove, this, &GraphRepresent::slotMouseMove);

    QVector<double> x1(2) , y1(2);
    x1[0] = 0;
    y1[0] = -20;
    x1[1] = 0;
    y1[1] = 20;

    verticalLine->setName("Vertical");
    verticalLine->setData(x1, y1);

    tracer = new QCPItemTracer(ui->customPlot);
    tracer->setGraph(ui->customPlot->graph(0));

    ui->customPlot->replot();
}

void GraphRepresent::BuildV2(){
    ui->customPlot->show();
    QVector<double> x(4001), y(4001);
    for (int i=0; i<2001; ++i)
    {
      x[i] = i/50.0 - 20;
      y[i] = func.EvaluateFunc(x[i]);
      x[i+2000] = i/50.0 - 20;
      y[i+2000] = -func.EvaluateFunc(x[i+2000]);
    }

    ui->customPlot->addGraph();
    ui->customPlot->graph(0)->setData(x, y);

    ui->customPlot->xAxis->setLabel("x");
    ui->customPlot->yAxis->setLabel("y");

    ui->customPlot->xAxis->setRange(-20, 20);
    ui->customPlot->yAxis->setRange(-20, 20);
    verticalLine = new QCPCurve(ui->customPlot->xAxis, ui->customPlot->yAxis);

    connect(ui->customPlot, &QCustomPlot::mousePress, this, &GraphRepresent::slotMousePress);
    connect(ui->customPlot, &QCustomPlot::mouseMove, this, &GraphRepresent::slotMouseMove);

    QVector<double> x1(2) , y1(2);
    x1[0] = 0;
    y1[0] = -20;
    x1[1] = 0;
    y1[1] = 20;

    verticalLine->setName("Vertical");
    verticalLine->setData(x1, y1);

    tracer = new QCPItemTracer(ui->customPlot);
    tracer->setGraph(ui->customPlot->graph(0));

    ui->customPlot->replot();
}

void GraphRepresent::slotMousePress(QMouseEvent *event)
{
    double coordX = ui->customPlot->xAxis->pixelToCoord(event->pos().x());

    QVector<double> x(2), y(2);
    x[0] = coordX;
    y[0] = -20;
    x[1] = coordX;
    y[1] = 20;

    verticalLine->setData(x, y);

    tracer->setGraphKey(coordX);

    ui->lineEdit->setText("x: " + QString::number(tracer->position->key()) +
                          " y: " + QString::number(tracer->position->value()));
    ui->customPlot->replot();
}

void GraphRepresent::slotMouseMove(QMouseEvent *event)
{
    if(QApplication::mouseButtons()) slotMousePress(event);
}

GraphRepresent::~GraphRepresent()
{
    delete ui;
}

void GraphRepresent::on_btnExit_clicked()
{
    verticalLine->~QCPCurve();
    close();
}
