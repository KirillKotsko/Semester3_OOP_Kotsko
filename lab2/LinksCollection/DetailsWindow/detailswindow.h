/**
*   @file detailswindow.h
*	@author Kirill Kotsko
*	@version 1.1
*/
#pragma once
#ifndef DETAILSWINDOW_H
#define DETAILSWINDOW_H

#include <QWidget>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QDesktopServices>
#include <QMessageBox>
#include <vector>
#include "Links/Links.h"

namespace Ui {
class DetailsWindow;
}

/**
 * @brief The DetailsWindow class
 *
 * Form which show info link, can show object of link and edit
 * and save some info about link.
 */
class DetailsWindow : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief constructor
     *
     * @param QWidget parent
     */
    explicit DetailsWindow(QWidget *parent = nullptr);

    /**
     * Destructor
     */
    ~DetailsWindow();

    /**
     * @brief set number of row in table
     * @param _row
     */
    void setRowInTable(int _row);

    /**
     * @brief get number of row in table
     * @return row
     */
    int getRowInTable() const;

    /**
     * @brief set type of object
     * @param _type
     */
    void setTypeOfObjects(QString _type);

    /**
     * @brief set link
     *
     * Fills in the link information form.
     */
    void setLink();

    /**
     * @brief get type of objects
     * @return type_of_object
     */
    QString getTypeOfObjects() const;

private slots:

    /**
     * @brief Open this object which link referred to.
     */
    void on_btnOpen_clicked();

    /**
     * @brief Back to the main window(main menu).
     */
    void on_btnBack_clicked();

    /**
     * @brief Save changes to data base changed in link info(name or comment).
     */
    void on_btnSave_clicked();

private:

    /**
     * @brief user interface of this form
     */
    Ui::DetailsWindow *ui;

    /** Type of object */
    QString type_of_objects;

    /** Row in table */
    int row_in_table;

    /** Link which show in this form */
    Links link_to_show;
};

#endif // DETAILSWINDOW_H
