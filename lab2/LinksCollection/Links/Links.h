/**
*   @file Links.h
*	@author Kirill Kotsko
*	@version 1.1
*/
#pragma once
#ifndef LINKS_H
#define LINKS_H

#include <QString>

/**
 * @brief The Links class
 *
 * Class which represent the link.
 */
class Links {
private:

    /** Name of object which link referred to */
    QString _name;

    /** Type of object which link referred to */
    QString _type;

    /** URL of link */
    QString _link;

    /** Comment for this link */
    QString _comment;

    /** Link is web or not */
    bool _is_web;

public:

    /** Default constructor */
    Links();

    /**
     * @brief Constructor
     * @param name of object
     * @param type of object
     * @param url
     * @param comment
     * @param link is web or not
     */
    explicit Links(const QString& name,
                   const QString& type,
                   const QString& link,
                   const QString& comment,
                   bool is_web) :
                   _name(name), _type(type), _link(link), _comment(comment), _is_web(is_web) {}

    /**
     * @brief get name
     * @return name
     */
    QString name() const;

    /**
     * @brief set name
     * @param name
     */
    void setName(const QString& name);

    /**
     * @brief get type
     * @return type
     */
    QString type() const;

    /**
     * @brief set type
     * @param type
     */
    void setType(const QString& type);

    /**
     * @brief get link
     * @return link
     */
    QString link() const;

    /**
     * @brief set link
     * @param link
     */
    void setLink(const QString& link);

    /**
     * @brief get comment
     * @return comment
     */
    QString comment() const;

    /**
     * @brief set comment
     * @param comment
     */
    void setComment(const QString& comment);

    /**
     * @brief get is_web
     * @return is_web
     */
    bool is_web() const;

    /**
     * @brief set is_web
     * @param is_web
     */
    void setIsWeb(bool is_web);

};

#endif // LINKS_H
