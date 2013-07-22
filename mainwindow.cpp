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

#include <QInputDialog>
#include <QDateTime>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QMouseEvent>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskdialog.h"

/*
  A task is marked as running using column 3. Column 3 holds the time when the task was started if it is running.
  Column 4 holds the time of the task when it was started.
  */

// Gallery of unmodern art
static char *ch_new[] = {
/* columns rows colors chars-per-pixel */
"22 22 2 1",
"+ c #009900",
"  c None",
/* pixels */
"                      ",
"                      ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"  ++++++++++++++++++  ",
"  ++++++++++++++++++  ",
"  ++++++++++++++++++  ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"         +++          ",
"                      ",
"                      ",
"                      ",
};
static char *ch_start[] = {
/* columns rows colors chars-per-pixel */
"22 22 2 1",
"+ c #009900",
"  c None",
/* pixels */
"                      ",
"                      ",
"      ++              ",
"      +++             ",
"      ++++            ",
"      +++++           ",
"      ++++++          ",
"      +++++++         ",
"      ++++++++        ",
"      +++++++++       ",
"      ++++++++++      ",
"      +++++++++       ",
"      ++++++++        ",
"      +++++++         ",
"      ++++++          ",
"      +++++           ",
"      ++++            ",
"      +++             ",
"      ++              ",
"                      ",
"                      ",
"                      ",
};
static char *ch_stop[] = {
/* columns rows colors chars-per-pixel */
"22 22 2 1",
"+ c #404040",
"  c None",
/* pixels */
"                      ",
"                      ",
"                      ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"   ++++++++++++++++   ",
"                      ",
"                      ",
"                      ",
};
static char *ch_delete[] = {
/* columns rows colors chars-per-pixel */
"22 22 2 1",
"+ c #900000",
"  c None",
/* pixels */
"                      ",
"                      ",
"  +++             +++ ",
"  ++++           ++++ ",
"   ++++         ++++  ",
"    ++++       ++++   ",
"     ++++     ++++    ",
"      ++++   ++++     ",
"       ++++ ++++      ",
"        +++++++       ",
"         +++++        ",
"         +++++         ",
"         +++++        ",
"        +++++++       ",
"       ++++ ++++      ",
"      ++++   ++++     ",
"     ++++     ++++    ",
"    ++++       ++++   ",
"   ++++         ++++  ",
"  ++++           ++++ ",
"                      ",
"                      ",
};
static char* ch_complete[] =  {
        "15 13 7 1",
        "       c None",
        ".      c #000000",
        "+      c #009000",
        "@      c #ACACAC",
        "#      c #E9E9E9",
        "$      c #989898",
        "%      c #FFFFFF",
        "               ",
        "              +",
        "             ++",
        "           +++ ",
        "          +++  ",
        "         +++   ",
        "        +++    ",
        "       +++     ",
        "+     +++      ",
        " ++  +++       ",
        "  +++++        ",
        "   +++         ",
        "    +          "};

// watches (c) 2000 by blacky, see http://websvn.kde.org/trunk/KDE/kdepim/ktimetracker/pics/watch-0.xpm?view=log
static char * watch_0_xpm[] = {
"15 13 7 1",
"       c None",
".      c #000000",
"+      c #4A4A4A",
"@      c #ACACAC",
"#      c #E9E9E9",
"$      c #989898",
"%      c #FFFFFF",
"    +@#.#@+    ",
"   $%%%.%%%$   ",
"  $%%%%.%%%%$  ",
" +%%%%%.%%%%%+ ",
" @%%%%%.%%%%%@ ",
" #%%%%%.%%%%%# ",
".%%%%%%.%%%%%%.",
" #%%%%%%%%%%%# ",
" @%%%%%%%%%%%@ ",
" +%%%%%%%%%%%+ ",
"  $%%%%%%%%%$  ",
"   $%%%%%%%$   ",
"    +@#%#@+    "};
/* XPM */
static char * watch_1_xpm[] = {
"15 13 7 1",
" 	c None",
".	c #000000",
"+	c #4A4A4A",
"@	c #ACACAC",
"#	c #E9E9E9",
"$	c #FFFFFF",
"%	c #989898",
"    +@#$#@+    ",
"   %$$$$$$$%   ",
"  %$$$$$$$$.%  ",
" +$$$$$$$$.$$+ ",
" @$$$$$$$.$$$@ ",
" #$$$$$$.$$$$# ",
".$$$$$$.$$$$$$.",
" #$$$$$$$$$$$# ",
" @$$$$$$$$$$$@ ",
" +$$$$$$$$$$$+ ",
"  %$$$$$$$$$%  ",
"   %$$$$$$$%   ",
"    +@#$#@+    "};
static char * watch_2_xpm[] = {
"15 13 7 1",
" 	c None",
".	c #000000",
"+	c #4A4A4A",
"@	c #ACACAC",
"#	c #E9E9E9",
"$	c #FFFFFF",
"%	c #989898",
"    +@#$#@+    ",
"   %$$$$$$$%   ",
"  %$$$$$$$$$%  ",
" +$$$$$$$$$$$+ ",
" @$$$$$$$$$$$@ ",
" #$$$$$$$$$$$# ",
".$$$$$$........",
" #$$$$$$$$$$$# ",
" @$$$$$$$$$$$@ ",
" +$$$$$$$$$$$+ ",
"  %$$$$$$$$$%  ",
"   %$$$$$$$%   ",
"    +@#$#@+    "};
static char * watch_3_xpm[] = {
"15 13 7 1",
"       c None",
".      c #000000",
"+      c #4A4A4A",
"@      c #ACACAC",
"#      c #E9E9E9",
"$      c #FFFFFF",
"%      c #989898",
"    +@#$#@+    ",
"   %$$$$$$$%   ",
"  %$$$$$$$$$%  ",
" +$$$$$$$$$$$+ ",
" @$$$$$$$$$$$@ ",
" #$$$$$$$$$$$# ",
".$$$$$$.$$$$$$.",
" #$$$$$$.$$$$# ",
" @$$$$$$$.$$$@ ",
" +$$$$$$$$.$$+ ",
"  %$$$$$$$$.%  ",
"   %$$$$$$$%   ",
"    +@#$#@+    "};
static char * watch_4_xpm[] = {
"15 13 7 1",
"       c None",
".      c #000000",
"+      c #4A4A4A",
"@      c #ACACAC",
"#      c #E9E9E9",
"$      c #FFFFFF",
"%      c #989898",
"    +@#$#@+    ",
"   %$$$$$$$%   ",
"  %$$$$$$$$$%  ",
" +$$$$$$$$$$$+ ",
" @$$$$$$$$$$$@ ",
" #$$$$$$$$$$$# ",
".$$$$$$.$$$$$$.",
" #$$$$$.$$$$$# ",
" @$$$$$.$$$$$@ ",
" +$$$$$.$$$$$+ ",
"  %$$$$.$$$$%  ",
"   %$$$.$$$%   ",
"    +@#.#@+    "};
static char * watch_5_xpm[] = {
"15 13 7 1",
"       c None",
".      c #000000",
"+      c #4A4A4A",
"@      c #ACACAC",
"#      c #E9E9E9",
"$      c #FFFFFF",
"%      c #989898",
"    +@#$#@+    ",
"   %$$$$$$$%   ",
"  %$$$$$$$$$%  ",
" +$$$$$$$$$$$+ ",
" @$$$$$$$$$$$@ ",
" #$$$$$$$$$$$# ",
".$$$$$$.$$$$$$.",
" #$$$$.$$$$$$# ",
" @$$$.$$$$$$$@ ",
" +$$.$$$$$$$$+ ",
"  %.$$$$$$$$%  ",
"   %$$$$$$$%   ",
"    +@#$#@+    "};
static char * watch_6_xpm[] = {
"15 13 7 1",
"       c None",
".      c #000000",
"+      c #4A4A4A",
"@      c #ACACAC",
"#      c #E9E9E9",
"$      c #FFFFFF",
"%      c #989898",
"    +@#$#@+    ",
"   %$$$$$$$%   ",
"  %$$$$$$$$$%  ",
" +$$$$$$$$$$$+ ",
" @$$$$$$$$$$$@ ",
" #$$$$$$$$$$$# ",
"........$$$$$$.",
" #$$$$$$$$$$$# ",
" @$$$$$$$$$$$@ ",
" +$$$$$$$$$$$+ ",
"  %$$$$$$$$$%  ",
"   %$$$$$$$%   ",
"    +@#$#@+    "};
static char * watch_7_xpm[] = {
"15 13 7 1",
"       c None",
".      c #000000",
"+      c #4A4A4A",
"@      c #ACACAC",
"#      c #E9E9E9",
"$      c #FFFFFF",
"%      c #989898",
"    +@#$#@+    ",
"   %$$$$$$$%   ",
"  %.$$$$$$$$%  ",
" +$$.$$$$$$$$+ ",
" @$$$.$$$$$$$@ ",
" #$$$$.$$$$$$# ",
".$$$$$$.$$$$$$.",
" #$$$$$$$$$$$# ",
" @$$$$$$$$$$$@ ",
" +$$$$$$$$$$$+ ",
"  %$$$$$$$$$%  ",
"   %$$$$$$$%   ",
"    +@#$#@+    "};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->treeWidget, SIGNAL(mousedoubleclicked(QMouseEvent*)),this,SLOT(on_mousedoubleclick(QMouseEvent*)));
    prepareicons();
    load();
    timer=new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(slottimer()));
    const QPixmap pm_watch_0(watch_0_xpm);
    QIcon qi_watch_0(pm_watch_0);
    const QPixmap pm_new(ch_new);
    QIcon qi_new(pm_new);
    ui->btn_addtask->setIcon(qi_new);
    const QPixmap pm_start(ch_start);
    QIcon qi_start(pm_start);
    ui->btn_starttimer->setIcon(qi_start);
    const QPixmap pm_stop(ch_stop);
    QIcon qi_stop(pm_stop);
    ui->btn_stoptimer->setIcon(qi_stop);
    const QPixmap pm_delete(ch_delete);
    QIcon qi_delete(pm_delete);
    ui->btn_deletetask->setIcon(qi_delete);
    ui->treeWidget->resizeColumnToContents(coltaskname);
    ui->treeWidget->header()->resizeSection(coltimericon,20);
    ui->treeWidget->header()->resizeSection(coltime,120);
    ui->treeWidget->header()->resizeSection(colcomplete,20);
    ui->treeWidget->setRootIsDecorated(false);
    ui->treeWidget->setColumnCount(6);
    ui->treeWidget->setColumnHidden(collaststart,true);
    ui->treeWidget->setColumnHidden(collasttime,true);
    QTreeWidgetItem *item1 = ui->treeWidget->headerItem();
    // col 1: task name
    item1->setText(coltimericon, QApplication::translate("MainWindow", "", 0, QApplication::UnicodeUTF8)); // col 2: timer icon
    item1->setText(coltime, QApplication::translate("MainWindow", "time (hh:mm:ss)", 0, QApplication::UnicodeUTF8)); // col 3: time col
    // col 4: last start time of task, e.g. Sunday 11:45 (hidden)
    // col 5: last content of col 2 before start, e.g. 00:00:19 (hidden)
    item1->setText(colcomplete, QApplication::translate("MainWindow", "", 0, QApplication::UnicodeUTF8)); // col 0: completed
}

MainWindow::~MainWindow()
{
    slotstoptiming();
    delete ui;
}

void MainWindow::prepareicons()
{
    const QPixmap pm_watch_0(watch_0_xpm);
    qi_watch[0]=QIcon(pm_watch_0);
    QPixmap pm_watch(watch_1_xpm);
    qi_watch[1]=QIcon(pm_watch);
    pm_watch=QPixmap(watch_2_xpm);
    qi_watch[2]=QIcon(pm_watch);
    pm_watch=QPixmap(watch_3_xpm);
    qi_watch[3]=QIcon(pm_watch);
    pm_watch=QPixmap(watch_4_xpm);
    qi_watch[4]=QIcon(pm_watch);
    pm_watch=QPixmap(watch_5_xpm);
    qi_watch[5]=QIcon(pm_watch);
    pm_watch=QPixmap(watch_6_xpm);
    qi_watch[6]=QIcon(pm_watch);
    pm_watch=QPixmap(watch_7_xpm);
    qi_watch[7]=QIcon(pm_watch);
    QPixmap pm_complete=QPixmap(ch_complete);
    qi_complete=QIcon(pm_complete);
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type())
    {
        case QEvent::LanguageChange:
            ui->retranslateUi(this);
            break;
        default:
            break;
    }
}

void MainWindow::on_actionQuit_triggered()
{
    close();
}

int MainWindow::runningtaskindex()
{
    int result=-1;
    for (int i=0; i<taskcount(); i=i+1)
    {
        if (!ui->treeWidget->topLevelItem(i)->text(collaststart).isEmpty()) result=i;
    }
    return result;
}

int MainWindow::taskcount()
{
    return ui->treeWidget->topLevelItemCount();
}

void MainWindow::slotaddtask()
{
    taskDialog* taskdialog=new taskDialog();
    taskdialog->exec();
    if (taskdialog->hasaccepted())
    {
        ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(QString())));
        ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setText(coltaskname,taskdialog->text());
        ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setFlags(ui->treeWidget->topLevelItem((ui->treeWidget->topLevelItemCount()-1))->flags() | Qt::ItemIsEditable);
        save();
        ui->treeWidget->resizeColumnToContents(coltaskname);
    }
}

int timestringtoseconds(QString timestring)
{
    QTime qtime1=QTime::fromString(timestring);
    return qtime1.hour()*3600+qtime1.minute()*60+qtime1.second();
}

QString timestring(int seconds)
{
    return QTime((int)(seconds/3600),(int)(seconds/60)%60,seconds%60).toString();
}

void MainWindow::slotstarttiming()
{
    stopalltimers();
    if (ui->treeWidget->currentItem())
    {
        ui->treeWidget->currentItem()->setIcon(coltimericon,qi_watch[0]);
        ui->treeWidget->currentItem()->setText(collaststart,QDateTime::currentDateTime().toString());
        ui->treeWidget->currentItem()->setText(collasttime,ui->treeWidget->currentItem()->text(coltime));
        oldtimeinseconds=-1; // dear slottimer, please note the current time column
        timer->start(1000);
    }
    else QMessageBox::information(0,"Info","First select a task that you want to start timing for.");
}

void MainWindow::slotstoptiming()
{
    if (ui->treeWidget->currentItem())
    {
        if (!ui->treeWidget->currentItem()->text(collaststart).isEmpty())
        { // task is really running
            timer->stop();
            ui->treeWidget->currentItem()->setIcon(coltimericon,QIcon());
            ui->treeWidget->currentItem()->setText(collaststart,QString()); // mark task as not running
        }
        save();
    }
}

void MainWindow::stopalltimers()
{
    timer->stop();
    for (int i=0; i<taskcount(); i=i+1)
    {
        if (!ui->treeWidget->topLevelItem(i)->text(collaststart).isEmpty())
        { // task is really running
            ui->treeWidget->topLevelItem(i)->setIcon(coltimericon,QIcon());
            ui->treeWidget->topLevelItem(i)->setText(collaststart,QString()); // mark task as not running
        }
    }
    save();
}

void MainWindow::slotdeletetask()
{
    slotstoptiming();
    delete(ui->treeWidget->currentItem());
    save();
}

void MainWindow::slottimer()
{
    static int turn=0;
    if (++turn>=8) turn-=8;
    ui->treeWidget->topLevelItem(runningtaskindex())->setIcon(coltimericon,qi_watch[turn]);

    // time calculation
    if (oldtimeinseconds==-1)
    {
        oldtimeinseconds=timestringtoseconds(ui->treeWidget->topLevelItem(runningtaskindex())->text(coltime));
    }
    QDateTime laststart=QDateTime::fromString(ui->treeWidget->topLevelItem(runningtaskindex())->text(collaststart));
    int secondspassed=laststart.secsTo(QDateTime::currentDateTime());
    ui->treeWidget->topLevelItem(runningtaskindex())->setText(coltime,timestring(secondspassed+oldtimeinseconds));
}

QString MainWindow::save()
{
    QString err;
    int i;
    QFile file1(QString("qtimetracker.txt"));
    if (!file1.open(QIODevice::Truncate | QIODevice::WriteOnly | QIODevice::Text)) err=QString("Could not open file");
    else
    {
        for (i=0; i<ui->treeWidget->topLevelItemCount(); i=i+1)
        {
            file1.write(ui->treeWidget->topLevelItem(i)->text(coltaskname).append("\n").toUtf8());
            file1.write(ui->treeWidget->topLevelItem(i)->text(coltime).append("\n").toUtf8());
            if (ui->treeWidget->topLevelItem(i)->icon(colcomplete).isNull())
            {
                file1.write("incomplete\n");
            }
            else file1.write("complete\n");
        }
        file1.close();
        ui->statusBar->showMessage(QString("saved tasks:").append(QString::number((double)i)));
    }
    return err;
}

QString MainWindow::load()
{
    QString err;
    QFile file1(QString("qtimetracker.txt"));
    if (!file1.open(QIODevice::ReadOnly | QIODevice::Text)) err=QString("Could not open file");
    else
    {
        QByteArray line;
        int i=0;
        while (!file1.atEnd())
        {
            line=file1.readLine();
            line.replace("\n","");
            ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(QString())));
            ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setText(coltaskname,line);
            ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setFlags(ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->flags()|Qt::ItemIsEditable);
            line=file1.readLine();
            line.replace("\n","");
            ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setText(coltime,line);
            line=file1.readLine();
            if (line=="complete\n")
            {
                ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setIcon(colcomplete,qi_complete);
                ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setData(colcomplete,Qt::DisplayRole,QVariant(" "));
            }
            i++;
        }
        file1.close();
    }
    return err;
}

void MainWindow::on_btn_addtask_clicked()
{
    slotaddtask();
}

void MainWindow::on_btn_starttimer_clicked()
{
    slotstarttiming();
}

void MainWindow::on_btn_stoptimer_clicked()
{
    slotstoptiming();
}

void MainWindow::on_btn_deletetask_clicked()
{
    slotdeletetask();
}

void MainWindow::on_mousedoubleclick(QMouseEvent *e)
{
    if (ui->treeWidget->itemAt(e->x(),e->y())==0)
    {
        slotaddtask();
    }
}

void MainWindow::on_treeWidget_clicked(const QModelIndex &index)
{
    if (index.column()==colcomplete)
    {
        if (ui->treeWidget->currentItem()->icon(colcomplete).isNull())
        {
            ui->treeWidget->currentItem()->setIcon(colcomplete,qi_complete);
            ui->treeWidget->currentItem()->setData(colcomplete,Qt::DisplayRole,QVariant(" "));
        }
        else
        {
            ui->treeWidget->currentItem()->setIcon(colcomplete,QIcon());
            ui->treeWidget->currentItem()->setData(colcomplete,Qt::DisplayRole,QVariant());
        }
        save();
    }
}
