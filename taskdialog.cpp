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

void taskDialog::on_pushButton_7_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("e"));
}

void taskDialog::on_pushButton_8_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("r"));
}

void taskDialog::on_pushButton_9_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("t"));
}

void taskDialog::on_pushButton_10_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("y"));
}

void taskDialog::on_pushButton_11_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("u"));
}

void taskDialog::on_pushButton_12_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("i"));
}

void taskDialog::on_pushButton_14_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("o"));
}

void taskDialog::on_pushButton_13_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("p"));
}

void taskDialog::on_pushButton_27_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(" "));
}

void taskDialog::on_pushButton_28_clicked()
{
    close();
}

void taskDialog::on_pushButton_15_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("a"));
}

void taskDialog::on_pushButton_16_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("s"));
}

void taskDialog::on_pushButton_17_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("d"));
}

void taskDialog::on_pushButton_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("f"));
}

void taskDialog::on_pushButton_18_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("g"));
}

void taskDialog::on_pushButton_20_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("h"));
}

void taskDialog::on_pushButton_19_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("j"));
}

void taskDialog::on_pushButton_2_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("k"));
}

void taskDialog::on_pushButton_4_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("l"));
}

void taskDialog::on_pushButton_22_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("z"));
}

void taskDialog::on_pushButton_23_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("x"));
}

void taskDialog::on_pushButton_24_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("c"));
}

void taskDialog::on_pushButton_25_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("v"));
}

void taskDialog::on_pushButton_3_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("b"));
}

void taskDialog::on_pushButton_26_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("n"));
}

void taskDialog::on_pushButton_21_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append("m"));
}
