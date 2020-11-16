#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Links/Links.h"
#include "AddLinkWindow/addlinkwindow.h"
#include "QTableLinkButton/QTableLinkButton.h"
#include "DetailsWindow/detailswindow.h"

#include <QMessageBox>
#include <QWidget>
#include <QTextStream>
#include <QMainWindow>
#include <QFile>
#include <vector>
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

    void on_btnRefresh_clicked();

    void slotShowLink();

    void slotAddLinkToList();

    void on_btnClearList_clicked();

    void on_btnSaveList_clicked();

private:
    AddLinkWindow addlinkwindow;
    DetailsWindow detailswindow;
    Ui::MainWindow *ui;
    std::vector<Links> list_of_links;

    void load_from_file();
    void update_table();
    void add_link_to_table(const Links& link);
};
#endif // MAINWINDOW_H
