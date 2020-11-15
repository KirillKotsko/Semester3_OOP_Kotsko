#ifndef ADDLINKWINDOW_H
#define ADDLINKWINDOW_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
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

private slots:

    void on_btnBrowseFile_clicked();

    void on_btnWebCheck_stateChanged(int arg1);

    void on_btnBack_clicked();

    void on_btnSave_clicked();

private:
    Ui::AddLinkWindow *ui;
};

#endif // ADDLINKWINDOW_H
