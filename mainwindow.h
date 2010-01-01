#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;

private slots:
    QString save();
    QString load();
    void on_MainWindow_iconSizeChanged(QSize iconSize);
    void on_actionQuit_triggered();
    void slotaddtask();
    void slotdeletetask();
};

#endif // MAINWINDOW_H
