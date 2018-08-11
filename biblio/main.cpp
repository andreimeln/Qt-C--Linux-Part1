#include "mainwindow.h"
#include "application.h"

int main(int argc, char *argv[])
{
    BIBLIO::Application App(argc, argv);

    BIBLIO::MainWindow w;
    w.show();

    return App.exec();
}
