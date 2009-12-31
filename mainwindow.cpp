#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->toolBar->addAction(QString("Add a task"),this,SLOT(slotaddtask()));
    static char *ch_start[] = {
    /* columns rows colors chars-per-pixel */
    "22 22 2 1",
    "+ c #808080",
    "  c None",
    /* pixels */
    "                      ",
    "                      ",
    "   ++                 ",
    "   +++                ",
    "   ++++               ",
    "   +++++              ",
    "   ++++++             ",
    "   +++++++            ",
    "   ++++++++           ",
    "   +++++++++          ",
    "   ++++++++++         ",
    "   +++++++++          ",
    "   ++++++++           ",
    "   +++++++            ",
    "   ++++++             ",
    "   +++++              ",
    "   ++++               ",
    "   +++                ",
    "   ++                 ",
    "                      ",
    "                      ",
    "                      ",
    };
    const QPixmap pm_start(ch_start);
    QIcon qi_start(pm_start);
    ui->toolBar->addAction(qi_start,QString("Start timing"));
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
    ui->treeWidget->addTopLevelItem(new QTreeWidgetItem(QStringList(QString("new task"))));
}

void MainWindow::on_MainWindow_iconSizeChanged(QSize iconSize)
{

}
