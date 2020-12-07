/**
*   @file mainwindow.h
*	@author Kirill Kotsko
*	@version 1.1
*/
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

/**
 * @brief The MainWindow class
 *
 * Program is represent the work with graphics.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief constructor
     *
     * @param QWidget parent
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief destructor
     */
    ~MainWindow();

private slots:

    /**
     * @brief choose function with 0 id
     */
    void on_btnFunc0_clicked();

    /**
     * @brief choose function with 1 id
     */
    void on_btnFunc1_clicked();

    /**
     * @brief choose function with 2 id
     */
    void on_btnFunc2_clicked();

    /**
     * @brief choose function with 3 id
     */
    void on_btnFunc3_clicked();

    /**
     * @brief choose function with 4 id
     */
    void on_btnFunc4_clicked();

    /**
     * @brief choose function with 5 id
     */
    void on_btnFunc5_clicked();

    /**
     * @brief choose function with 6 id
     */
    void on_btnFunc6_clicked();

    /**
     * @brief choose function with 7 id
     */
    void on_btnFunc7_clicked();

    /**
     * @brief show the graphic of function
     */
    void on_btnShow_clicked();

    /**
     * @brief exit from program
     */
    void on_btnExit_clicked();

private:

    /**
     * @brief user interface of the main window
     */
    Ui::MainWindow *ui;

    /**
     * @brief function to work with
     */
    FunctionGraph func;

    /**
     * @brief form which represent graphic of function
     */
    GraphRepresent window_graph;
};
#endif // MAINWINDOW_H
