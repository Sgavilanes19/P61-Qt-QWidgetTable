QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11


SOURCES += \
    main.cpp \
    persona.cpp \
    personadialog.cpp \
    principal.cpp
 TRANSLATIONS += \
 AgendaTelefonica_it.ts\
 AgendaTelefonica_en.ts

HEADERS += \
    persona.h \
    personadialog.h \
    principal.h

FORMS += \
    personadialog.ui \
    principal.ui

RESOURCES += \
    Resources.qrc





