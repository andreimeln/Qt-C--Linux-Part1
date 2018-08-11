#include "helpers.h"

#include <QWidget>

namespace BIBLIO {
namespace HLP {

void setHorPolicy(QWidget *W, QSizePolicy::Policy Pol)
{
    QSizePolicy P = W->sizePolicy();
    P.setHorizontalPolicy(Pol);
    W->setSizePolicy(P);
}

/**
  * @TODO Define font size
  */

void setWidth(QWidget *W, int Width)
{
    QSize S = W->maximumSize();
    S.setWidth(Width);
    W->setMaximumSize(S);
}


} // namespace HLP
} // namespace BIBLIO
