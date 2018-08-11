#include "itemeditdialog.h"

#include <QFrame>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSizePolicy>
#include <QSpacerItem>
#include <QCloseEvent>

namespace BIBLIO {

/********************************************************************/

namespace IED_HELPER {

    Buttons::Buttons(QWidget *parent)
        : QFrame (parent)
{
    setFrameStyle(StyledPanel | Sunken); // F = this
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    QHBoxLayout *L = new QHBoxLayout(this);
    L->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimum));
    {
        QPushButton *B = pOK = new QPushButton(this);
        L->addWidget(B);
        B->setText(tr("OK"));
        connect(B,SIGNAL(clicked()),this,SIGNAL(accepting()));
    } {
        QPushButton *B = pCancel = new QPushButton(this);
        L->addWidget(B);
        B->setText(tr("Cancel"));
        connect(B,SIGNAL(clicked()),this,SIGNAL(rejecting()));
    }

}

} // namespace IED_HELPER

/********************************************************************/

ItemEditDialog::ItemEditDialog(QWidget *parent)
    : QDialog(parent)
{
    setWindowTitle(tr("Editing a reference"));

    QVBoxLayout *L0 = new QVBoxLayout(this);

    {   // Top frame
        Edt = new ItemEditFrame();
        /*
        QFrame *F = new QFrame(this);
        F->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        F->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        L0->addWidget(F);
        */
        L0->addWidget(Edt);
    }{  // Bottom frame
        Btn = new IED_HELPER::Buttons(this);
        L0->addWidget(Btn);
        connect(Btn, SIGNAL(accepting()),this,SLOT(accept()));
        connect(Btn, SIGNAL(rejecting()),this,SLOT(reject()));

        //QFrame *F = new QFrame(this);
        /*
        F->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
        F->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
        L0->addWidget(F);
        QHBoxLayout *L = new QHBoxLayout(F);
        L->addItem(new QSpacerItem(0,0,QSizePolicy::Expanding,QSizePolicy::Minimal));
        {
            QPushButton *B = pOK = new QPushButton(F);
            L->addWidget(B);
            B->setText(tr("OK"));
            connect(B,SIGNAL(clicked()),this,SLOT(accept()));
        } {
            QPushButton *B = pCancel = new QPushButton(F);
            L->addWidget(B);
            B->setText(tr("Cancel"));
            connect(B,SIGNAL(clicked()),this,SLOT(reject()));

        }
        */
    }
}

/*======================================================================*/

void closeEvent(QCloseEvent *e)
{
    switch (result())
    {
    case Rejected:
        e->accept();
        break;
    case Accepted:
        if (Edt->isValid())
        {
            Edt->save();
            e->accept();
        } else {
            e->ignore();
        }
        break;
    default:
        e->accept();
        break;
    }
    QDialog::closeEvent(e);
}

/*======================================================================*/


ItemEditDialog::~ItemEditDialog()
{

}

} // namespace BIBLIO
