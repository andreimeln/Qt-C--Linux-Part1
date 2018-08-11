#include "application.h"

#include <QTranslator>

namespace MYAPP {

  Application::Application(int argc, char *argv[])
    : QApplication(argc, argv) {

    setup_language("rus");

  }

  void Application::setup_language(const QString & lcode)
  {
    QTranslator *T = new QTranslator(this);
    T->load("hello_" + lcode);
    installTranslator(T);
  }

}
