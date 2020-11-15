#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Links/Links.h"
#include "AddLink/addlinkwindow.h"

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>

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
    void on_btnAddLink_clicked();

private:
    AddLinkWindow addlinkwindow;
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
