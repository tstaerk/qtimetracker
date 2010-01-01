#include <QInputDialog>
#include <QFile>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    const QPixmap pm_new(ch_new);
    QIcon qi_new(pm_new);
    ui->toolBar->addAction(qi_new,QString("Add a task"),this,SLOT(slotaddtask()));
    const QPixmap pm_start(ch_start);
    QIcon qi_start(pm_start);
    ui->toolBar->addAction(qi_start,QString("Start timing"));
    const QPixmap pm_stop(ch_stop);
    QIcon qi_stop(pm_stop);
    ui->toolBar->addAction(qi_stop,QString("Stop timing"));
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
    QString taskname = QInputDialog::getText(this, QString("Question"),
                                              QString("task name:"), QLineEdit::Normal,
                                              QString(""), &ok);
         if (ok && !taskname.isEmpty())
             ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(taskname)));
    save();
}

void MainWindow::slotdeletetask()
{
    delete(ui->treeWidget->currentItem());
}

QString MainWindow::save()
{
    QString err;
    QFile file1(QString("qtimetracker.txt"));
    if (!file1.open(QIODevice::ReadWrite | QIODevice::Text)) err=QString("Could not open file");
    else
    {
        for (int i=0; i<ui->treeWidget->topLevelItemCount(); i=i+1)
        {
            file1.write(ui->treeWidget->topLevelItem(i)->text(0).append("\n").toUtf8());
        }
        file1.close();
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
            ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(QString(line))));
            i++;
        }
        file1.close();
    }
    return err;
}

void MainWindow::on_MainWindow_iconSizeChanged(QSize iconSize)
{

}
