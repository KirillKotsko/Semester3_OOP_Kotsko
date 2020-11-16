#include "addlinkwindow.h"
#include "ui_addlinkwindow.h"

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
    Links link{ ui->inpName->text(),
                ui->inpType->currentText(),
                ui->inpLink->text(),
                ui->inpComment->toPlainText(),
                ui->btnWebCheck->isChecked() };
    if ((link.link()).isEmpty() || (link.name()).isEmpty())
    {
        msgBox.setText("There is no link or name.");
    }
    else if (!link.is_web() && QFile::exists(link.link()) == false)
    {
        msgBox.setText("Such link is invalid.");
    }
    else
    {
        QFile file{ link.type() + ".txt" };
        if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
            return;
        QTextStream stream(&file);
        stream << link.name() << "\n"
            << link.link() << "\n"
            << link.type() << "\n"
            << link.is_web() << "\n"
            << link.comment() << "\n\n";
        file.close();
        msgBox.setText("The link has added.");
        ui->inpName->clear();
        ui->inpLink->clear();
        ui->inpType->update();
        ui->inpComment->clear();
        ui->btnWebCheck->setTristate(0);
    }
    msgBox.exec();
}


void AddLinkWindow::on_inpType_activated(const QString &arg1)
{
    if (ui->inpType->currentText() == "Website" && !(ui->btnWebCheck->isChecked())) ui->btnWebCheck->click();
}
