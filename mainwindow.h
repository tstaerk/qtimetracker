#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    QTimer *timer;

private slots:
    QString save();
    QString load();
    void on_actionQuit_triggered();
    void slottimer();
    void slotstarttiming();
    void slotstoptiming();
    void slotaddtask();
    void slotdeletetask();
};

#endif // MAINWINDOW_H
