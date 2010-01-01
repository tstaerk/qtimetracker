#include <QInputDialog>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "taskdialog.h"

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
static char * watch_0_xpm[] = {
"15 15 7 1",
"       c None",
".      c #000000",
"+      c #4A4A4A",
"@      c #ACACAC",
"#      c #E9E9E9",
"$      c #989898",
"%      c #FFFFFF",
"       .       ",
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
"    +@#%#@+    ",
"       .       "};

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load();
    const QPixmap pm_watch_0(watch_0_xpm);
    QIcon qi_watch_0(pm_watch_0);
    const QPixmap pm_new(ch_new);
    QIcon qi_new(pm_new);
    ui->toolBar->addAction(qi_new,QString("Add a task"),this,SLOT(slotaddtask()));
    const QPixmap pm_start(ch_start);
    QIcon qi_start(pm_start);
    ui->toolBar->addAction(qi_start,QString("Start timing"),this,SLOT(slotstarttiming()));
    const QPixmap pm_stop(ch_stop);
    QIcon qi_stop(pm_stop);
    ui->toolBar->addAction(qi_stop,QString("Stop timing"),this,SLOT(slotstoptiming()));
    const QPixmap pm_delete(ch_delete);
    QIcon qi_delete(pm_delete);
    ui->toolBar->addAction(qi_delete,QString("Delete task"),this,SLOT(slotdeletetask()));
    ui->treeWidget->resizeColumnToContents(0);
    ui->treeWidget->resizeColumnToContents(1);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
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

void MainWindow::slotaddtask()
{
    bool ok;
    /*
    QString taskname = QInputDialog::getText(this, QString("Question"),
                                              QString("task name:"), QLineEdit::Normal,
                                              QString(""), &ok);
         if (ok && !taskname.isEmpty())
             ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(taskname)));
    save();
    */
    taskDialog* taskdialog=new taskDialog();
    taskdialog->exec();
    ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(taskdialog->text())));
    save();
}

void MainWindow::slotstarttiming()
{
    const QPixmap pm_watch_0(watch_0_xpm);
    QIcon qi_watch_0(pm_watch_0);
    ui->treeWidget->currentItem()->setIcon(1,qi_watch_0);
}

void MainWindow::slotstoptiming()
{
    const QPixmap pm_watch_0(watch_0_xpm);
    QIcon qi_watch_0(pm_watch_0);
    ui->treeWidget->currentItem()->setIcon(1,QIcon());
}

void MainWindow::slotdeletetask()
{
    delete(ui->treeWidget->currentItem());
    save();
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
            i++;
        }
        file1.close();
    }
    return err;
}
