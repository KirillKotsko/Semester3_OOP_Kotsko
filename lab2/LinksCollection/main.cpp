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
    w.show();
    return a.exec();
}
