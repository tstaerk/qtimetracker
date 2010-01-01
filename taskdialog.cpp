#include "taskdialog.h"
#include "ui_taskdialog.h"

taskDialog::taskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taskDialog)
{
    ui->setupUi(this);
}

taskDialog::~taskDialog()
{
    delete ui;
}

void taskDialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

void taskDialog::on_pushButton_5_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("q"));
}

QString taskDialog::text()
{
    return ui->lineEdit->text();
}

void taskDialog::on_buttonBox_accepted()
{
    close();
}

void taskDialog::on_pushButton_6_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("w"));
}
