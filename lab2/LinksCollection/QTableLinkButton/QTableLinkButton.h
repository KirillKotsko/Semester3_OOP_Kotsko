#pragma once
#ifndef QTABLELINKBUTTON_H
#define QTABLELINKBUTTON_H

#include <QPushButton>
#include <QString>

class QTableLinkButton : public QPushButton
{
    Q_OBJECT
public:
    explicit QTableLinkButton(QWidget *parent = 0, const QString& _type_of_object = "Pictures", int _row = 0);
    ~QTableLinkButton();
    int getRowInTable();
    QString getTypeOfObject();

public slots:

private:
    QString type_of_objects;
    int row_in_table;
};

#endif // QTABLELINKBUTTON_H
