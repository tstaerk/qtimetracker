#ifndef MYTREEWIDGET_H
#define MYTREEWIDGET_H

#include <QTreeWidget>
#include <QDebug>

class mytreewidget : public QTreeWidget {
    Q_OBJECT
public:
    mytreewidget(QWidget *parent = 0){};
    ~mytreewidget(){};
    void mousePressEvent(QMouseEvent *event) {qDebug() << "test";emit mousepressed(event);QTreeWidget::mousePressEvent(event);}

signals:
    void mousepressed(QMouseEvent *event);

};
#endif // MYTREEWIDGET_H
