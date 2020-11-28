#ifndef GRAPHREPRESENT_H
#define GRAPHREPRESENT_H

#include <QWidget>

namespace Ui {
class GraphRepresent;
}

class GraphRepresent : public QWidget
{
    Q_OBJECT

public:
    explicit GraphRepresent(QWidget *parent = nullptr);
    ~GraphRepresent();

private:
    Ui::GraphRepresent *ui;
};

#endif // GRAPHREPRESENT_H
