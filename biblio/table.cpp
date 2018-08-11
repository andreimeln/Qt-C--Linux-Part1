#include "table.h"
#include "application.h"
#include "itemeditdialog.h"

#include <QAction>

namespace BIBLIO {

Table::Table(QWidget *parent)
    : QTableView(parent)
{
    setProperty("modeName","Table");

    //Model = new BiblioModel(this);
    //setModel(qApp->model()); // bug - trying to create an instance of abstract class
    //setModel(dynamic_cast<Application*>(qApp)->Model);
    setModel(APP->Model);

    setContextMenuPolicy(Qt::ActionsContextMenu);

    {
        QAction *A = new QAction(this);
        A->setText(tr("Edit"));
        connect(A, SIGNAL(triggered()), this, SLOT(itemEditCurrent()));
        addAction(A);
    }{
        QAction *A = new QAction(this);
        A->setText(tr("New"));
        connect(A, SIGNAL(triggered()), this, SLOT(itemCreateNew()));
        addAction(A);
    }{
        QAction *A = new QAction(this);
        A->setText(tr("Delete"));
        connect(A, SIGNAL(triggered()), this, SLOT(itemDeleteCurrent()));
        addAction(A);
    }


}

Table::~Table()
{

}

void Table::itemEditCurrent(void)
{
    // find out which cell/string is celected
    if (! selectedIndexes().first().isValid()) return;
    int row = selectedIndexes().first().row();
    DATA::Object *X = APP->model()->at(row);
    // create dialog
    itemEditDialog Dia(this);
    Dia.attach(X);
    Dia.exec();
}

void Table::itemCreateNew(void)
{

}

void Table::itemDeleteCurrent(void)
{

}

} // namespace BIBLIO
