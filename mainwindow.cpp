#include <QInputDialog>
#include <QDateTime>
#include <QFile>
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
    load();
    prepareicons();
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
    ui->treeWidget->resizeColumnToContents(0);
    ui->treeWidget->header()->resizeSection(1,20);
    ui->treeWidget->header()->resizeSection(2,50);
    ui->treeWidget->setColumnCount(5);
    ui->treeWidget->setColumnHidden(3,true);
    ui->treeWidget->setColumnHidden(4,true);
    QTreeWidgetItem *item1 = ui->treeWidget->headerItem();
    item1->setText(1, QApplication::translate("MainWindow", "", 0, QApplication::UnicodeUTF8));
    item1->setText(2, QApplication::translate("MainWindow", "time (hh:mm:ss)", 0, QApplication::UnicodeUTF8));
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
        if (!ui->treeWidget->topLevelItem(i)->text(3).isEmpty()) result=i;
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
    if (taskdialog->hasaccepted()) ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(taskdialog->text())));
    save();
    ui->treeWidget->resizeColumnToContents(0);
}

void MainWindow::slotstarttiming()
{
    ui->treeWidget->currentItem()->setIcon(1,qi_watch[0]);
    ui->treeWidget->currentItem()->setText(3,QDateTime::currentDateTime().toString());
    ui->treeWidget->currentItem()->setText(4,ui->treeWidget->currentItem()->text(2));
    timer->start(1000);
}

int timestringtoseconds(QString timestring)
{
    QTime qtime1=QTime::fromString(timestring);
    return qtime1.hour()*3600+qtime1.minute()*60+qtime1.second();
}

QString timestring(int seconds)
{
    return QTime((int)(seconds/3600),(int)(seconds/60),seconds%60).toString();
}

void MainWindow::slotstoptiming()
{
    if (!ui->treeWidget->currentItem()->text(3).isEmpty())
    { // task is really running
        timer->stop();
        const QPixmap pm_watch_0(watch_0_xpm);
        QIcon qi_watch_0(pm_watch_0);
        ui->treeWidget->currentItem()->setIcon(1,QIcon());
        QDateTime laststart=QDateTime::fromString(ui->treeWidget->currentItem()->text(3));
        QDateTime now=QDateTime::currentDateTime();
        int time=laststart.secsTo(now);
        ui->treeWidget->currentItem()->setText(3,QString()); // mark task as not running
    }
    save();
}

void MainWindow::slotdeletetask()
{
    delete(ui->treeWidget->currentItem());
    save();
}

void MainWindow::slottimer()
{
    static int turn=0;
    if (++turn>=8) turn-=8;
    ui->treeWidget->topLevelItem(runningtaskindex())->setIcon(1,qi_watch[turn]);
    ui->treeWidget->currentItem()->setText(2,timestring(timestringtoseconds(ui->treeWidget->currentItem()->text(4))+QDateTime::fromString(ui->treeWidget->currentItem()->text(3)).secsTo(QDateTime::currentDateTime())));
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
            file1.write(ui->treeWidget->topLevelItem(i)->text(0).append("\n").toUtf8());
            file1.write(ui->treeWidget->topLevelItem(i)->text(2).append("\n").toUtf8());
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
            ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(QString(line))));
            line=file1.readLine();
            line.replace("\n","");
            ui->treeWidget->topLevelItem(ui->treeWidget->topLevelItemCount()-1)->setText(2,line);
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
