#pragma once
#ifndef DETAILSWINDOW_H
#define DETAILSWINDOW_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDesktopServices>
#include <QMessageBox>
#include <vector>
#include "Links/Links.h"

namespace Ui {
class DetailsWindow;
}

class DetailsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DetailsWindow(QWidget *parent = nullptr);
    ~DetailsWindow();
    void setRowInTable(int _row);
    int getRowInTable() const;
    void setTypeOfObjects(QString _type);
    void setLink();
    QString getTypeOfObjects() const;

private slots:
    void on_btnOpen_clicked();

    void on_btnBack_clicked();

    void on_btnSave_clicked();

private:
    Ui::DetailsWindow *ui;
    QString type_of_objects;
    int row_in_table;
    Links link_to_show;
};

#endif // DETAILSWINDOW_H
