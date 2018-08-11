//#include <QApplication>
//#include <QMainWindow>
#include "application.h"
#include "mywidget.h"

int main(int argc, char *argv[])
{

  MYAPP::Application App(argc,argv);

  //QMainWindow MW;
  //QWidget MW;

  MYAPP::MyWidget MW;
  MW.show();

  int Result = App.exec();

  return Result;

}
