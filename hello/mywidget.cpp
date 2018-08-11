#include "mywidget.h"

#include <QPushButton>

namespace MYAPP
{

  MyWidget::MyWidget(QWidget *parent):
    QWidget(parent)
  {
    QPushButton *PB = new QPushButton(this);
    PB->setText(tr("Hello, world"));
    // PB->setProperty("text", tr("Hello, world"));
    connect(PB,SIGNAL(clicked()), this, SLOT(close()));
  }

} //MYAPP
