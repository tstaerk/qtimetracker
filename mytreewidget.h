#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QTreeWidget>

class mytreewidget : public QTreeWidget {
    Q_OBJECT
public:
    mytreewidget(QWidget *parent = 0){};
    ~mytreewidget(){};
};
#endif // MYTREEWIDGET_H
