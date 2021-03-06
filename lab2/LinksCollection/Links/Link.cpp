/**
*   @file Links.cpp
*	@author Kirill Kotsko
*	@version 1.1
*/
#include "Links/Links.h"

QString Links::name() const
{
    return _name;
}

void Links::setName(const QString& name)
{
    _name = name;
}

QString Links::type() const
{
    return _type;
}

void Links::setType(const QString& type)
{
    _type = type;
}

QString Links::link() const
{
    return _link;
}

void Links::setLink(const QString& link)
{
    _link = link;
}

QString Links::comment() const
{
    return _comment;
}

void Links::setComment(const QString& comment)
{
    _comment = comment;
}

bool Links::is_web() const
{
    return _is_web;
}

void Links::setIsWeb(bool is_web)
{
    _is_web = is_web;
}

Links::Links()
{

}
