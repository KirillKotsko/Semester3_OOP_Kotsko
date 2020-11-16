#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
    addlinkwindow.show();
}

void MainWindow::update_table()
{
    ui->tbwLinks->clear();
    ui->tbwLinks->setHorizontalHeaderLabels({  "Name",
                                               "Link",
                                               "Web",
                                               "Details"});
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
    detailswindow.show();
}
