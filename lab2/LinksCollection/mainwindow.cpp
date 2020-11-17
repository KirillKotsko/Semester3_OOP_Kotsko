/**
*   @file mainwindow.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/
#include "mainwindow.h"
#include "./ui_mainwindow.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    update_table();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnAddLink_clicked()
{
    addlinkwindow.setMaximumWidth(addlinkwindow.width());
    addlinkwindow.setMaximumHeight(addlinkwindow.height());
    addlinkwindow.setMinimumWidth(addlinkwindow.width());
    addlinkwindow.setMinimumHeight(addlinkwindow.height());
    addlinkwindow.show();
}

void MainWindow::update_table()
{
    ui->tbwLinks->clear();
    ui->tbwLinks->setHorizontalHeaderLabels({  "Name",
                                               "Link",
                                               "Web",
                                               "Details",
                                               "List"});
    load_from_file();
}

void MainWindow::load_from_file()
{
    QString type_to_show = ui->inpType->currentText();
    QFile file{ type_to_show + ".txt" };
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    ui->tbwLinks->clearContents();
    ui->tbwLinks->setRowCount(0);
    QTextStream in(&file);
    int current_field = 0;
    Links current_link;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        switch (current_field) {
        case 0:
            current_link.setName(line);
            break;
        case 1:
            current_link.setLink(line);
            break;
        case 2:
            current_link.setType(line);
            break;
        case 3:
            current_link.setIsWeb(line.toInt());
            break;
        case 4:
            current_link.setComment(line);
            break;
        case 5:
            current_field = -1;
            add_link_to_table(current_link);
            break;
        }
        current_field++;
    }
    file.close();
}

void MainWindow::add_link_to_table(const Links& current_link)
{
    int rows = ui->tbwLinks->rowCount();
    ui->tbwLinks->setRowCount(rows + 1);

    QTableWidgetItem* item = new QTableWidgetItem(current_link.name());
    ui->tbwLinks->setItem(rows, 0, item);

    item = new QTableWidgetItem(current_link.link());
    ui->tbwLinks->setItem(rows, 1, item);

    if (current_link.is_web()) item = new QTableWidgetItem("Yes");
    else item = new QTableWidgetItem("No");
    ui->tbwLinks->setItem(rows, 2, item);

    QTableLinkButton* button = new QTableLinkButton(this, current_link.type(), rows);
    button->setProperty("row", rows);
    button->setText("Show");
    connect(button, SIGNAL(clicked()), this, SLOT(slotShowLink()));
    ui->tbwLinks->setCellWidget(rows, 3, button);

    QTableLinkButton* button1 = new QTableLinkButton(this, current_link.type(), rows);
    button1->setProperty("row", rows);
    button1->setText("Add");
    button1->setLinkInRow(current_link);
    connect(button1, SIGNAL(clicked()), this, SLOT(slotAddLinkToList()));
    ui->tbwLinks->setCellWidget(rows, 4, button1);
}

void MainWindow::on_inpType_currentTextChanged(const QString &arg1)
{
    update_table();
}

void MainWindow::on_btnRefresh_clicked()
{
    update_table();
}

void MainWindow::slotShowLink()
{
    QTableLinkButton *button = (QTableLinkButton*) sender();
    detailswindow.setRowInTable(button->getRowInTable());
    detailswindow.setTypeOfObjects(button->getTypeOfObject());
    detailswindow.setLink();
    detailswindow.setMaximumWidth(detailswindow.width());
    detailswindow.setMaximumHeight(detailswindow.height());
    detailswindow.setMinimumWidth(detailswindow.width());
    detailswindow.setMinimumHeight(detailswindow.height());
    detailswindow.show();
}

void MainWindow::slotAddLinkToList()
{
    QTableLinkButton *button = (QTableLinkButton*) sender();
    Links tmp = button->getLinkInRow();
    list_of_links.push_back(tmp);
    QMessageBox msg;
    msg.setText("Link has been added to list.");
    msg.exec();
}

void MainWindow::on_btnClearList_clicked()
{
    list_of_links.clear();
    QMessageBox msg;
    msg.setText("List is empty.");
    msg.exec();
}

void MainWindow::on_btnSaveList_clicked()
{
    QString fileName = QFileDialog::getSaveFileName( 0,"Save list: ","C:\\", "(*.txt);;(*.docx)" );
    QFile file{ fileName };
    if (!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;
    int i = 1;
    QTextStream stream(&file);
    for (auto x : list_of_links)
    {
        stream << i << ". " << x.name() << " ("
            << x.type() << ") - "
            << x.link() << ". " << "\n\n";
        i++;
    }
    file.close();
}
