#include "addlinkwindow.h"
#include "ui_addlinkwindow.h"
#include <QMessageBox>

AddLinkWindow::AddLinkWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddLinkWindow)
{
    ui->setupUi(this);
}

AddLinkWindow::~AddLinkWindow()
{
    delete ui;
}

void AddLinkWindow::on_btnBrowseFile_clicked()
{
    QString chosen_link = QFileDialog::getOpenFileName(this,tr("Choose file"),"C:\\");
    ui->inpLink->setText(chosen_link);
}

void AddLinkWindow::on_btnWebCheck_stateChanged(int arg1)
{
    if (arg1 == 2){
        ui->btnBrowseFile->hide();
        ui->inpLink->clear();
    }
    else{
        ui->btnBrowseFile->show();
        ui->inpLink->clear();
    }
}

void AddLinkWindow::on_btnBack_clicked()
{
    close();
}

void AddLinkWindow::on_btnSave_clicked()
{
    QMessageBox msgBox;
    Links link{ ui->inpType->currentText(),
                ui->inpLink->text(),
                ui->inpComment->toPlainText(),
                ui->btnWebCheck->isTristate() };
    if ((link.link()).isEmpty()){
        msgBox.setText("There is no link.");
    }
    else{
        QFile file{ link.type() + ".txt" };
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;
        QTextStream stream(&file);
        stream << link.link() << "\n"
            << link.type() << "\n"
            << link.is_web() << "\n"
            << link.comment() << "\n\n";
        file.close();
        msgBox.setText("The link has added.");
        ui->inpLink->clear();
        ui->inpType->clear();
        ui->inpComment->clear();
        ui->btnWebCheck->setTristate(0);
    }
    msgBox.exec();
}
