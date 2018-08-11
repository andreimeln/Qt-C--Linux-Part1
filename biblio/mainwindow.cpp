#include "mainwindow.h"

#include <QPushButton>
#include <QToolButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QDockWidget>
#include <QFrame>
#include <QIcon>

#include "edit.h"
#include "itemeditdialog.h"
#include "table.h"

namespace BIBLIO {

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    QActionGroup *agModes = new QActionGroup(this);
    agModes->setExclusive(true);
    {
        QAction *A = 0;
        A = actNewItem = new QAction(this);
        A->setText(tr("Item"));
        connect(A,SIGNAL(triggered()), this, SLOT(newItem()));
    }{
        QAction *A = 0;
        QIcon Ic(":/icons/table");
        A = actTableMode = new QAction(this);
        A->setText(tr("Table Mode"));
        A->setIcon(Ic);
        agModes->addAction(A);
        modeActions.insert("Table",A);
        connect(A,SIGNAL(triggered()), this, SLOT(tableMode()));
    }{
        QAction *A = 0;
        A = actEditMode = new QAction(this);
        A->setText(tr("Edit Mode"));
        A->setCheckable(true);
        agModes->addAction(A);
        modeActions.insert("Edit",A);
        connect(A,SIGNAL(triggered()), this, SLOT(tableMode()));
    }


    QMenu *mItem = menuBar()->addMenu(tr("Item (A)"));
    mItem->addAction(actNewItem);

    QMenu *mModes = menuBar()->addMenu(tr("Modes"));
    mItem->addAction(actTableMode);
    mItem->addAction(actEditMode);

    QToolBar *tbModes = new QToolBar(this);
    tbModes->setWindowTitle(tr("Modes"));
    tbModes->addAction(actTableMode);
    tbModes->addAction(actEditMode);
    addToolBar(Qt::TopToolBarArea, tbModes);

    QToolBar *tbEmpty = new QToolBar(this);
    tbModes->setWindowTitle(tr("Empty"));
    addToolBar(Qt::TopToolBarArea, tbEmpty);

    //Edit *T = new Edit(this); //new QTextEdit(this);
    //setCentralWidget(T);
    //editMode();
    tableMode();

    QMenu *mWindows = menuBar()->addMenu(tr("Windows"));

    // a few test docked windows
    {
    QDockWidget *D1 = new QDockWidget(this);
    D1->setWindowTitle(tr("Yellow"));
    QFrame *F1 = new QFrame(this);
    F1->setStyleSheet("background: yellow"); //#FFFF00
    D1->setWidget(F1);
    addDockWidget(Qt::LeftDockWidgetArea, D1);
    mWindows->addAction(D1->toggleViewAction());
    }{
    QDockWidget *D1 = new QDockWidget(this);
    D1->setWindowTitle(tr("Yellow"));
    QFrame *F1 = new QFrame(this);
    F1->setStyleSheet("background: green"); //#FFFF00
    D1->setWidget(F1);
    addDockWidget(Qt::LeftDockWidgetArea, D1);
    mWindows->addAction(D1->toggleViewAction());
    }{
    QDockWidget *D1 = new QDockWidget(this);
    D1->setWindowTitle(tr("Yellow"));
    QFrame *F1 = new QFrame(this);
    F1->setStyleSheet("background: red"); //#FFFF00
    D1->setWidget(F1);
    addDockWidget(Qt::LeftDockWidgetArea, D1);
    mWindows->addAction(D1->toggleViewAction());
    }

    //mWindows->addAction


/*
    QToolButton *B = new QToolButton(this);
    B->setText(tr("Item (B)"));
    B->move(100,100);
    //connect(B,SIGNAL(clicked()), this, SLOT(newItem));
    B->setDefaultAction(actNewItem);

    QPushButton *C = new QPushButton(this);
    C->setText(tr("Item 1"));
    C->move(100,200);
    //connect(C,SIGNAL(clicked()), this, SLOT(newItem));
    //C->addAction(actNewItem);
    connect(C,SIGNAL(clicked()), actNewItem, SIGNAL(triggered())); // pass on the signal to another

    //B->setEnabled(false);

    actNewItem->setEnabled(false);
    */

}

MainWindow::~MainWindow()
{

}

void MainWindow::newItem()
{
    //ItemEditDialog Dia(this);
    //Dia.exec();

    ItemEditDialog *Dia = new ItemEditDialog(this);
    Dia->show();
}

void MainWindow::tableMode(void)
{
    QWidget *W = centralWidget();
    // check if mode switch is needed at all
    if (dynamic_cast<Table*>(W)) return;
    if (W)
    {
        // check if we can turn off the old mode
        bool OK = true;
        cancelMode(&OK);
        if (!OK)
        {
            QString modeName = W->property("modeName").toString();
            QAction *A = modeActions.value(modeName,0);
            if (A) A->setChecked(true);
            return;
        }
        // turn off old mode
        setCentralWidget(0); // remove centran widget
        delete W;

    }
    // turn on new mode
    W = new Table(this);
    setCentralWidget(W); // place a new central widget
    actTableMode->setChecked(true);
}

void MainWindow::editMode(void)
{
    // check if we can turn off the old mode
    bool OK = true;
    cancelMode(&OK);
    if (!OK) return;
    // switch mode
    QWidget *W = centralWidget();
    if (dynamic_cast<Edit*> (W)) return;
    setCentralWidget(0); // remove central widget
    delete W;
    W = new Edit(this);
    //W->setProperty("modeAction",actEditMode);
    setCentralWidget(W); // place a new central widget
    //connect(this, SIGNAL(cancelMode(bool*)), W, slot(onCancelMode(bool*)));
    actEditMode->setChecked(true);
}

} // namespace BIBLIO
