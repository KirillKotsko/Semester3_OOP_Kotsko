#ifndef LINKS_H
#define LINKS_H

#include <QString>

class Links {
private:
    QString _type;
    QString _link;
    QString _comment;
    bool _is_web;
public:
    Links();
    explicit Links(const QString& type,
                   const QString& link,
                   const QString& comment,
                   bool is_web) :
                   _type(type), _link(link), _comment(comment), _is_web(is_web) {}

    QString type() const;
    void setType(const QString& type);
    QString link() const;
    void setLink(const QString& link);
    QString comment() const;
    void setComment(const QString& comment);
    bool is_web() const;
    void setIsWeb(bool is_web);

};

#endif // LINKS_H
