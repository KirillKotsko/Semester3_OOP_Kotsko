/**
*   @file detailswindow.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/
#include "detailswindow.h"
#include "ui_detailswindow.h"

using namespace std;

DetailsWindow::DetailsWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailsWindow)
{
    ui->setupUi(this);
}

DetailsWindow::~DetailsWindow()
{
    delete ui;
}

void DetailsWindow::setRowInTable(int _row)
{
    row_in_table = _row;
}

int DetailsWindow::getRowInTable() const
{
    return row_in_table;
}

void DetailsWindow::setTypeOfObjects(QString _type)
{
    type_of_objects = _type;
}

QString DetailsWindow::getTypeOfObjects() const
{
    return type_of_objects;
}

void DetailsWindow::setLink()
{
    QFile file{ type_of_objects + ".txt" };
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    for (int i=0; i < row_in_table * 6; i++)
        QString line = in.readLine();
    int current_field = 0;
    while (current_field < 5)
    {
        QString line = in.readLine();
        switch (current_field) {
        case 0:
            link_to_show.setName(line);
            break;
        case 1:
            link_to_show.setLink(line);
            break;
        case 2:
            link_to_show.setType(line);
            break;
        case 3:
            link_to_show.setIsWeb(line.toInt());
            break;
        case 4:
            link_to_show.setComment(line);
            break;
        }
        current_field++;
    }
    file.close();
    ui->inpName->setText(link_to_show.name());
    ui->brsLink->setText(link_to_show.link());
    ui->lblType->setText("Type of object: " + link_to_show.type());
    ui->inpComment->setText(link_to_show.comment());
}

void DetailsWindow::on_btnOpen_clicked()
{
    QDesktopServices::openUrl(QUrl(link_to_show.link()));
}

void DetailsWindow::on_btnBack_clicked()
{
    close();
}

void DetailsWindow::on_btnSave_clicked()
{
    link_to_show.setName(ui->inpName->text());
    link_to_show.setComment(ui->inpComment->toPlainText());
    QFile file{ link_to_show.type() + ".txt" };
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return;
    QTextStream in(&file);
    int current_field = 0;
    vector<Links> list_link;
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
            list_link.push_back(current_link);
            break;
        }
        current_field++;
    }
    file.close();
    QFile::remove(link_to_show.type() + ".txt");

    list_link[row_in_table] = link_to_show;

    QFile new_file {link_to_show.type() + ".txt"};
    if (!new_file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
        return;
    QTextStream stream(&new_file);
    for (auto x : list_link)
    {
        stream << x.name() << "\n"
            << x.link() << "\n"
            << x.type() << "\n"
            << x.is_web() << "\n"
            << x.comment() << "\n\n";
    }
    new_file.close();
    QMessageBox msgBox;
    msgBox.setText("Changes has been saved.");
    msgBox.exec();
}
