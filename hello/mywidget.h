#ifndef MYWIDGET_H
#define MYWIDGET_H

#include <QWidget>

namespace MYAPP
{
  class MyWidget : public QWidget {

    Q_OBJECT

  public:
    MyWidget(QWidget *parent = 0);
    //MyWidget(const MyWidget &M);

    virtual ~MyWidget(void) {}; // virtual

    //const MyWidget & operator = (const MyWidget & M); // assignment operator

  };
} //namespace MYAPP

#endif // MYWIDGET_IF
