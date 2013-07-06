#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QTreeWidget>
#include <QDebug>

class mytreewidget : public QTreeWidget {
    Q_OBJECT
public:
    mytreewidget(QWidget *parent = 0){};
    ~mytreewidget(){};
    void mouseDoubleClickEvent(QMouseEvent *event) {emit mousedoubleclicked(event);QTreeWidget::mouseDoubleClickEvent(event);}

signals:
    void mousedoubleclicked(QMouseEvent *event);

};
#endif // MYTREEWIDGET_H
