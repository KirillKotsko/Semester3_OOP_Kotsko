/**
*   @file addlinkwindow.h
*	@author Kirill Kotsko
*	@version 1.1
*/
#pragma once
#ifndef ADDLINKWINDOW_H
#define ADDLINKWINDOW_H

#include <QWidget>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QDesktopServices>
#include "Links/Links.h"

namespace Ui {
class AddLinkWindow;
}

/**
 * @brief The addLinkWindow class
 *
 * Form which add link to data base and to table.
 */
class AddLinkWindow : public QWidget
{
    Q_OBJECT

public:

    /**
     * @brief constructor AddLinkWindow
     * @param QWidget parent
     */
    explicit AddLinkWindow(QWidget *parent = nullptr);

    /**
     * @brief destructor
     */
    ~AddLinkWindow();

private slots:

    /**
     * @brief Choose object to add link
     *
     * When you click on this button you will be able choose object, and add this link.
     */
    void on_btnBrowseFile_clicked();

    /**
     * @brief Disable button "btnBrowseFile", when argument is true
     *
     * @param arg1
     */
    void on_btnWebCheck_stateChanged(int arg1);

    /**
     * @brief Back to the main window(main menu).
     */
    void on_btnBack_clicked();

    /**
     * @brief Save link in data base and in table.
     */
    void on_btnSave_clicked();

    /**
     * @brief Change value of "btnWebCheck" on true
     * @param arg1
     */
    void on_inpType_activated(const QString &arg1);

private:

    /**
     * @brief user interface of this form;
     */
    Ui::AddLinkWindow *ui;
};

#endif // ADDLINKWINDOW_H
