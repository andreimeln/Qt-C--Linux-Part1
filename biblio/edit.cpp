#include "edit.h"

namespace BIBLIO {

Edit::Edit(QWidget *parent) : QTextEdit(parent)
{
    setProperty("modeName","Edit");
}

void Edit::onCancelMode(bool *OK)
{
    QString S = toPlainText();
    if (OK) {
        *OK = S.simplified().isEmpty();
    }
}

Edit::~Edit()
{

}

} // namespace BIBLIO
