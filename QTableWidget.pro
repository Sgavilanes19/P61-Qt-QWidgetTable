QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


SOURCES += \
    main.cpp \
    persona.cpp \
    personadialog.cpp \
    principal.cpp

HEADERS += \
    persona.h \
    personadialog.h \
    principal.h

TRANSLATIONS += \
Agenda_en.ts \
Agenda_it.ts

FORMS += \
    personadialog.ui \
    principal.ui

RESOURCES += \
    Resources.qrc





