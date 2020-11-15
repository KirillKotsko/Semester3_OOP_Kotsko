#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Links/Links.h"
#include "AddLink/addlinkwindow.h"

#include <QWidget>
#include <QTextStream>
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

    void on_inpType_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

private:
    AddLinkWindow addlinkwindow;
    Ui::MainWindow *ui;

    void load_from_file();
    void update_table();
    void add_link_to_table(const Links& link);
};
#endif // MAINWINDOW_H
