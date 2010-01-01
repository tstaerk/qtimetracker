#ifndef TASKDIALOG_H
#define TASKDIALOG_H

#include <QDialog>

namespace Ui {
    class taskDialog;
}

class taskDialog : public QDialog {
    Q_OBJECT
public:
    taskDialog(QWidget *parent = 0);
    ~taskDialog();
    QString text();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::taskDialog *ui;

private slots:
    void on_pushButton_6_clicked();
    void on_buttonBox_accepted();
    void on_pushButton_5_clicked();
};

#endif // TASKDIALOG_H
