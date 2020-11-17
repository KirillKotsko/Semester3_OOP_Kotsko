/**
*   @file main.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/
#include "mainwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setMaximumHeight(434);
    w.setMaximumWidth(749);
    w.setMinimumHeight(434);
    w.setMinimumWidth(749);
    w.show();
    return a.exec();
}
