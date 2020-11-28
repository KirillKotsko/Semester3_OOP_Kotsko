#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>
#include <QMessageBox>
#include "FunctionGraph/functiongraph.h"
#include "GraphRepresent/graphrepresent.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnFunc0_clicked();

    void on_btnFunc1_clicked();

    void on_btnFunc2_clicked();

    void on_btnFunc3_clicked();

    void on_btnFunc4_clicked();

    void on_btnFunc5_clicked();

    void on_btnFunc6_clicked();

    void on_btnFunc7_clicked();

    void on_btnShow_clicked();

private:
    Ui::MainWindow *ui;
    FunctionGraph func;
    GraphRepresent window_graph;
};
#endif // MAINWINDOW_H
