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
    bool hasaccepted();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::taskDialog *ui;
    bool accepted;
    bool caps;

private slots:
    void on_pb_q_clicked();
    void on_pb_w_clicked();
    void on_pb_e_clicked();
    void on_pb_r_clicked();
    void on_pb_t_clicked();
    void on_pb_y_clicked();
    void on_pb_backspace_clicked();
    void on_pb_esc_clicked();
    void on_pb_caps_clicked();
    void on_pb_m_clicked();
    void on_pb_n_clicked();
    void on_pb_b_clicked();
    void on_pb_v_clicked();
    void on_pb_c_clicked();
    void on_pb_x_clicked();
    void on_pb_z_clicked();
    void on_pb_l_clicked();
    void on_pb_k_clicked();
    void on_pb_j_clicked();
    void on_pb_h_clicked();
    void on_pb_g_clicked();
    void on_pb_f_clicked();
    void on_pb_d_clicked();
    void on_pb_s_clicked();
    void on_pb_a_clicked();
    void on_pb_enter_clicked();
    void on_pb_space_clicked();
    void on_pb_p_clicked();
    void on_pb_o_clicked();
    void on_pb_i_clicked();
    void on_pb_u_clicked();
};

#endif // TASKDIALOG_H
