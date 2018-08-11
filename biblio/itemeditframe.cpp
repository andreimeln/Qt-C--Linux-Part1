#include "itemeditframe.h"
#include "items.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QSpacerItem>
#include <QComboBox>
#include <QIntValidator>

namespace BIBLIO {

ItemEditFrame::ItemEditFrame(QWidget *parent)
    : QFrame(parent)
{
    Dt = 0;
    setFrameStyle(StyledPanel | Sunken);
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *L = new QVBoxLayout(this);
    setup_Author(L);
    setup_Title(L);
    setup_Subtitle(L);
    {
      QHBoxLayout *L1 = new QHBoxLayout();
      L1->setMargin(0);
      L->addLayout(L1);
      setup_Location(L1);
      setup_Publisher(L1);
      setup_Year(L1);
      setup_TotalPages(L1);
      setup_Journal(L1);
    }{
      QHBoxLayout *L1 = new QHBoxLayout();
      L1->setMargin(0);
      L->addLayout(L1);
      setup_Journal(L1);
      setup_Volume(L1);
      setup_Issue(L1);
      setup_Pages(L1);
     }

    setup_Comment(L);

    cbxKind->currentIndexChanged(0);
}

void ItemEditFrame::attach(DATA::Object *X)
{
    Dt = X;
    if (!Dt) return;
    // common part
    edtAuthor->setText(X->Author);
    edtTitle->setText(X->Title);
    { // for book
        DATA::book *B = dynamic_cast<DATA::Book*>X;
        if (B)
        {
            QString N;
            N.setNum(B->TotalPages);
            edtTotalPages->setText(N);
            int k = cbxKind->findData(Book);
            if (k >= 0)
                cbxKind->setCurrentIndex(k);
            cbxKind->setEnabled(false);
        }
    }{
        // for article
        DATA::Article *B = dynamic_cast<DATA::Article*>X;
        if (B)
        {
            edtJournal->setText(B->Journal);
            int k = cbxKind->findData(Article);
            if (k >= 0)
                cbxKind->setCurrentIndex(k);
            cbxKind->setEnabled(false);
        }
    }
}

void ItemEditFrame::save(void)
{

}

void ItemEditFrame::isValid() const
{
    if (edtTitle->text().size() <= 0) return true;
    return edtTitle->text().at(0) != '.'; // must not begin with dot
}

void ItemEditFrame::save(void){

}

void ItemEditFrame::setup_Author(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Author"));
    L1->addWidget(lbl);

    QLineEdit *txt = edtAuthor = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Title(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Title"));
    L1->addWidget(lbl);

    QLineEdit *txt = edtTitle = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Subtitle(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Subtitle"));
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Location(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Location"));
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Publisher(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Publisher"));
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Year(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Year"));
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_TotalPages(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = lblTotalPages = new QLabel(this);
    lbl->setText(tr("Total pages"));
    L1->addWidget(lbl);

    QLineEdit *txt = edtTotalPages = new QLineEdit(this);
    txt->setValidator(new QIntValidator(0,1000000));
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Journal(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = edtJournal = new QLabel(this);
    lbl->setText(tr("Journal"));
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Volume(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Volume"));
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Issue(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Issue"));
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Pages(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Pages"));
    //HLP::setHorPolicy(lbl,QSizePolicy::Minimum);
    //HLP::setWidth(lbl,50);
    L1->addWidget(lbl);

    QLineEdit *txt = new QLineEdit(this);
    //HLP::setHorPolicy(txt,QSizePolicy::Minimum);
    //HLP::setWidth(txt,50);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Comment(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->setSpacing(0);
    L1->setMargin(0);
    L1->addItem(L1);

    QLabel *lbl = new QLabel(this);
    lbl->setText(tr("Comment"));
    L1->addWidget(lbl);
    QLineEdit *txt = new QLineEdit(this);
    L1->addWidget(txt);
}

void ItemEditFrame::setup_Kind(QLayout *L)
{
    QVBoxLayout *L1 = new QVBoxLayout();
    L1->addItem(L1);

    QSpacerItem *Sp = new QSpacerItem(0,0,QSizePolicy::Expanding);
    L1->addItem(Sp);

    QComboBox *cbx = cbxKind = new QComboBox(this);
    cbx->addItem(tr("---"), Unknown);
    cbx->addItem(tr("Book"), Book);
    cbx->addItem(tr("Article"), Article);
    cbx->setCurrentIndex(0);
    connect(cbx, SIGNAL(currentIndexChanged(int)), this, SLOT(kindSelected(int)));
    L1->addWidget(cbx);
}

void ItemEditFrame::kindSelected(int index)
{
    QComboBox *C = dynamic_cast<QComboBox*>(sender());
    if (! C)
    {
        /// @TODO write message to log
        return;
    }
    bool OK = false;
    int K = C->itemData(index).toInt(&OK);
    if (! OK)
    {
        /// @TODO write message to log
        return;
    }

    switch(K)
    {
    case Unknown:
        lblTotalPages->setVisible(true);
        lblTotalPages->setEnabled(false);
        edtTotalPages->setVisible(true);
        edtTotalPages->setEnabled(false);
        break;
    case Book:
        lblTotalPages->setVisible(true);
        lblTotalPages->setEnabled(true);
        edtTotalPages->setVisible(true);
        edtTotalPages->setEnabled(true);
        break;
    case Article:
        lblTotalPages->setVisible(false);
        lblTotalPages->setEnabled(false);
        edtTotalPages->setVisible(false);
        edtTotalPages->setEnabled(false);
        break;
    default:
        /// @TODO write to log
        return;
    }
}

ItemEditFrame::~ItemEditFrame()
{

}

} // namespace BIBLIO
