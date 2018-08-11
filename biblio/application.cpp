#include "application.h"

#include <QTranslator>

namespace BIBLIO {

Application::Application(int argc, char *argv[])
    : QApplication(argc, argv) {

    pTranslator = new QTranslator(this);
    //pTranslator->load("biblio_rus.qm");
    pTranslator->load(":/lang/isl");
    installTranslator(pTranslator);

    //setLayoutDirection(Qt::LeftToRight); // of keyboard layout

    pModel = new BiblioModel(this);
}

Application::~Application()
{

}

} // namespace BIBLIO
