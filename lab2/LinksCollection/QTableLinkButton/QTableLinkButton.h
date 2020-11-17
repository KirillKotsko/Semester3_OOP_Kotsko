/**
*   @file QTableLinkButton.h
*	@author Kirill Kotsko
*	@version 1.1
*/
#pragma once
#ifndef QTABLELINKBUTTON_H
#define QTABLELINKBUTTON_H

#include <QPushButton>
#include <QString>
#include "Links/Links.h"

/**
* @brief Class QTableLinkButton
*
* Button which become dynamic, and integrate to the QTable.
* This button also this button remembers information about row, type of object in this table and link in this row.
*/
class QTableLinkButton : public QPushButton
{
    Q_OBJECT

public:

    /**
    * @brief constructor
    *
    * @param QWidget parent
    * @param type of object in table
    * @param number of row in table
    */
    explicit QTableLinkButton(QWidget *parent = 0, const QString& _type_of_object = "Pictures", int _row = 0);

    /** Destructor */
    ~QTableLinkButton();

    /**
     * @brief get row in table
     * @return  Number of row in table
     */
    int getRowInTable();

    /**
     * @brief get type of object
     * @return Type of object in table
     */
    QString getTypeOfObject();

    /**
     * @brief set link in row
     * @param link
     */
    void setLinkInRow(Links _link);

    /**
     * @brief get link in row
     * @return link
     */
    Links getLinkInRow();


public slots:

private:

    /** Type of object in table */
    QString type_of_objects;

    /** Number of row in table */
    int row_in_table;

    /** Link in this row */
    Links link_in_row;
};

#endif // QTABLELINKBUTTON_H
