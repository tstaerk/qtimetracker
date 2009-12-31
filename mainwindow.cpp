#include <QInputDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

// Gallery of unmodern art
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
    ui->toolBar->addAction(QString("Add a task"),this,SLOT(slotaddtask()));

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
}

void MainWindow::slotdeletetask()
{
    delete(ui->treeWidget->currentItem());
}

void MainWindow::on_MainWindow_iconSizeChanged(QSize iconSize)
{

}
