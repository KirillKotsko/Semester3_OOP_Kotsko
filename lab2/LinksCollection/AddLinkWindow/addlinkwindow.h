#pragma once
#ifndef ADDLINKWINDOW_H
#define ADDLINKWINDOW_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDesktopServices>
#include "Links/Links.h"

namespace Ui {
class AddLinkWindow;
}

class AddLinkWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddLinkWindow(QWidget *parent = nullptr);
    ~AddLinkWindow();
    bool checkUrl(const QUrl &url);

private slots:

    void on_btnBrowseFile_clicked();

    void on_btnWebCheck_stateChanged(int arg1);

    void on_btnBack_clicked();

    void on_btnSave_clicked();

    void on_inpType_activated(const QString &arg1);

private:
    Ui::AddLinkWindow *ui;
};

#endif // ADDLINKWINDOW_H
