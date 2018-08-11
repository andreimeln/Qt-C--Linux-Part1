#include "example1.h"

namespace BIBLIO {

Example1::Example1(QWidget *parent)
    : QDialog(parent)
{
    ui.setupUI(this);
    ui.cbxKind->addItem(tr("Vasya"),1);
    ui.cbxKind->addItem(tr("Petya"),2);
}

Example1::~Example1()
{

}

} //namespace BIBLIO
