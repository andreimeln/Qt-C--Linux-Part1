#ifndef EXAMPLE1_H
#define EXAMPLE1_H

#include <QDialog>

#include "ui_example1.h"

namespace BIBLIO {

class Example1 : public QDialog
{
    Q_OBJECT

private:
    UI::Example1 ui;

public:
    Example1(QWidget *parent = 0);
    virtual ~Example();
};

} // namespace BIBLIO

#endif // EXAMPLE1_H
