#include "taskdialog.h"
#include "ui_taskdialog.h"

taskDialog::taskDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::taskDialog)
{
    caps=false;
    accepted=false;
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

QString taskDialog::text()
{
    return ui->lineEdit->text();
}

void taskDialog::on_pushButton_28_clicked()
{
    accepted=true;
    close();
}

void taskDialog::on_pb_q_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("Q"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("q"));
}

void taskDialog::on_pb_w_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("W"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("w"));
}

void taskDialog::on_pb_e_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("E"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("e"));
}

void taskDialog::on_pb_r_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("R"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("r"));
}

void taskDialog::on_pb_t_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("T"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("t"));
}

void taskDialog::on_pb_y_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("Y"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("y"));
}

void taskDialog::on_pb_u_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("U"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("u"));
}

void taskDialog::on_pb_i_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("I"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("i"));
}

void taskDialog::on_pb_o_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("O"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("o"));
}

void taskDialog::on_pb_p_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("P"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("p"));
}

void taskDialog::on_pb_a_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("A"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("a"));
}

void taskDialog::on_pb_s_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("S"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("s"));
}

void taskDialog::on_pb_d_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("D"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("d"));
}

void taskDialog::on_pushButton_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("F"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("f"));
}

void taskDialog::on_pushButton_18_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("G"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("g"));
}

void taskDialog::on_pushButton_20_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("H"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("h"));
}

void taskDialog::on_pushButton_19_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("J"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("j"));
}

void taskDialog::on_pushButton_2_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("K"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("k"));
}

void taskDialog::on_pushButton_4_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("L"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("l"));
}

void taskDialog::on_pushButton_22_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("Z"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("z"));
}

void taskDialog::on_pushButton_23_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("X"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("x"));
}

void taskDialog::on_pushButton_24_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("C"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("c"));
}

void taskDialog::on_pushButton_25_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("V"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("v"));
}

void taskDialog::on_pushButton_3_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("B"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("b"));
}

void taskDialog::on_pushButton_26_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("N"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("n"));
}

void taskDialog::on_pushButton_21_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("M"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("m"));
}

void taskDialog::on_pushButton_27_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(" "));
}

void taskDialog::on_pushButton_29_clicked()
{
    caps=!caps;
}

void taskDialog::on_pushButton_31_clicked()
{
    accepted=false;
    close();
}

bool taskDialog::hasaccepted()
{
    return accepted;
}

void taskDialog::on_pushButton_30_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().left(ui->lineEdit->text().length()-1)); // Uni... what?
}
