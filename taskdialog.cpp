/*
 * Copyright 2010-2013 by Thorsten Staerk
 * http://www.staerk.de/thorsten
 *
 * This file is part of qtimetracker.
 *
 * qtimetracker is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * qtimetracker is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with qtimetracker.  If not, see <http://www.gnu.org/licenses/>.
 */

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
    switch (e->type())
    {
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

void taskDialog::on_pb_enter_clicked()
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

void taskDialog::on_pb_f_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("F"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("f"));
}

void taskDialog::on_pb_g_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("G"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("g"));
}

void taskDialog::on_pb_h_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("H"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("h"));
}

void taskDialog::on_pb_j_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("J"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("j"));
}

void taskDialog::on_pb_k_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("K"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("k"));
}

void taskDialog::on_pb_l_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("L"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("l"));
}

void taskDialog::on_pb_z_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("Z"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("z"));
}

void taskDialog::on_pb_x_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("X"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("x"));
}

void taskDialog::on_pb_c_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("C"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("c"));
}

void taskDialog::on_pb_v_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("V"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("v"));
}

void taskDialog::on_pb_b_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("B"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("b"));
}

void taskDialog::on_pb_n_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("N"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("n"));
}

void taskDialog::on_pb_m_clicked()
{
    if (caps)
        ui->lineEdit->setText(ui->lineEdit->text().append("M"));
    else
        ui->lineEdit->setText(ui->lineEdit->text().append("m"));
}

void taskDialog::on_pb_space_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().append(" "));
}

void taskDialog::on_pb_caps_clicked()
{
    caps=!caps;
}

void taskDialog::on_pb_esc_clicked()
{
    accepted=false;
    close();
}

bool taskDialog::hasaccepted()
{
    return accepted;
}

void taskDialog::on_pb_backspace_clicked()
{
    ui->lineEdit->setText(ui->lineEdit->text().left(ui->lineEdit->text().length()-1)); // Uni... what?
}
