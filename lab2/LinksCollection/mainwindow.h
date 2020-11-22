/**
*   @file mainwindow.h
*	@author Kirill Kotsko
*	@version 1.1
*/
#pragma once
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "Links/Links.h"
#include "AddLinkWindow/addlinkwindow.h"
#include "QTableLinkButton/QTableLinkButton.h"
#include "DetailsWindow/detailswindow.h"

#include <QMessageBox>
#include <QWidget>
#include <QTextStream>
#include <QMainWindow>
#include <QFile>
#include <vector>
#include <QFileDialog>
#include <algorithm>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/**
 * @brief Main window of the program
 *
 * Program is represent the work with links.
 */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    /**
     * @brief constructor
     *
     * @param QWidget parent
     */
    MainWindow(QWidget *parent = nullptr);

    /**
     * @brief destructor
     */
    ~MainWindow();

private slots:

    /**
     * @brief open the form "AddLinkWindow"
     */
    void on_btnAddLink_clicked();

    /**
     * @brief change type of object which will be show on table
     * @param arg1
     */
    void on_inpType_currentTextChanged(const QString &arg1);

    /**
     * @brief refresh(update) table
     */
    void on_btnRefresh_clicked();

    /**
     * @brief open form
     */
    void slotShowLink();

    /**
     * @brief this button add link to "list_of_links"
     */
    void slotAddLinkToList();

    /**
     * @brief clear "list_of_links"
     */
    void on_btnClearList_clicked();

    /**
     * @brief Save collection("list of links") to the document
     */
    void on_btnSaveList_clicked();

    /**
     * @brief Search link by text "inpSearch"
     */
    void on_btnSearch_clicked();

private:

    /**
     * @brief form for add link
     */
    AddLinkWindow addlinkwindow;

    /**
     * @brief form to show details of the link
     */
    DetailsWindow detailswindow;

    /**
     * @brief user interface of the main window
     */
    Ui::MainWindow *ui;

    /**
     * @brief list of links choosen by user
     */
    std::vector<Links> list_of_links;

    void load_from_file();

    /**
     * @brief update the table due to value of "inpType"
     */
    void update_table();

    /**
     * @brief add link to the table
     * @param link
     */
    void add_link_to_table(const Links& link);

    /**
     * @brief add link to table search edition
     * @param current_link
     * @param row in real table
     */
    void add_link_to_table_search_edition(const Links& current_link, int row_in_real_table);

    /**
     * @brief Check if t is substring of s or not
     * @param s
     * @param t
     * @return true or false
     */
    bool isSubString(const QString &s, const QString &t);
};
#endif // MAINWINDOW_H
