#include "QTableLinkButton/QTableLinkButton.h"

QTableLinkButton::QTableLinkButton(QWidget *parent, const QString& _type_of_object, int _row) :
    QPushButton(parent), type_of_objects(_type_of_object), row_in_table(_row)
{

}

QTableLinkButton::~QTableLinkButton()
{

}

int QTableLinkButton::getRowInTable()
{
    return row_in_table;
}

QString QTableLinkButton::getTypeOfObject()
{
    return type_of_objects;
}

void QTableLinkButton::setLinkInRow(Links _link)
{
    link_in_row = _link;
}

Links QTableLinkButton::getLinkInRow()
{
    return link_in_row;
}
