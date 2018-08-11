QT += core gui widgets
TEMPLATE = app

TARGET = hello

TRANSLATIONS = hello_rus.ts

HEADERS += application.h \
	   mywidget.h

SOURCES += application.h \
           main.cpp \
           mywidget.cpp
