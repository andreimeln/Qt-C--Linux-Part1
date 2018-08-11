#-------------------------------------------------
#
# Project created by QtCreator 2017-01-31T16:19:25
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = biblio
TEMPLATE = app

TRANSLATIONS += biblio_rus.ts biblio_isl.ts

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES +=                  \
        application.cpp     \
        bibliomodel.cpp     \
        edit.cpp            \
        helpers1.cpp        \
        itemeditdialog.cpp  \
        itemeditframe.cpp   \
        main.cpp            \
        mainwindow.cpp      \
        table.cpp \
    example1.cpp

HEADERS  +=                 \
        application.h       \
        bibliomodel.h       \
        data.h              \
        edit.h              \
        helpers.h           \
        itemeditdialog.h    \
        itemeditframe.h     \
        items.h             \
        mainwindow.h        \
        table.h \
    example1.h
#FORMS    += mainwindow.ui

RESOURCES += \
    biblio.qrc
