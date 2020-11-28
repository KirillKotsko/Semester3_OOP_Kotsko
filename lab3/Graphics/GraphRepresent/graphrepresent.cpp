#include "graphrepresent.h"
#include "ui_graphrepresent.h"

GraphRepresent::GraphRepresent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GraphRepresent)
{
    ui->setupUi(this);
}

GraphRepresent::~GraphRepresent()
{
    delete ui;
}
