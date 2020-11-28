/**
*   @file mainwindow.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    window_graph.setMode(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnFunc0_clicked()
{
    func.setFunctionId(0);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("1");
    window_graph.setMode(1);
}

void MainWindow::on_btnFunc1_clicked()
{
    func.setFunctionId(1);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("2");
    window_graph.setMode(1);
}

void MainWindow::on_btnFunc2_clicked()
{
    func.setFunctionId(2);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("3");
    window_graph.setMode(1);
}

void MainWindow::on_btnFunc3_clicked()
{
    func.setFunctionId(3);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("4");
    window_graph.setMode(1);
}

void MainWindow::on_btnFunc4_clicked()
{
    func.setFunctionId(4);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("5");
    window_graph.setMode(1);
}

void MainWindow::on_btnFunc5_clicked()
{
    func.setFunctionId(5);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("6");
    window_graph.setMode(2);
}

void MainWindow::on_btnFunc6_clicked()
{
    func.setFunctionId(6);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("7");
    window_graph.setMode(2);
}

void MainWindow::on_btnFunc7_clicked()
{
    func.setFunctionId(7);
    ui->lblNumFunc->clear();
    ui->lblNumFunc->setText("8");
    window_graph.setMode(2);
}

void MainWindow::on_btnShow_clicked()
{
    func.setA((ui->txtAvalue->text()).toDouble());
    func.setB((ui->txtBvalue->text()).toDouble());
    func.setC((ui->txtCvalue->text()).toDouble());
    window_graph.setFunc(func);
    if (window_graph.getMode() == 1){
        window_graph.BuildV1();
    } else if (window_graph.getMode() == 2){
        window_graph.BuildV2();
    }
    window_graph.show();
}

void MainWindow::on_btnExit_clicked()
{
    close();
}
