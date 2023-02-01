QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    persona.cpp \
    personadialog.cpp \
    principal.cpp
 TRANSLATIONS += \
 AgendaTelefonica_it.ts

HEADERS += \
    persona.h \
    personadialog.h \
    principal.h

FORMS += \
    personadialog.ui \
    principal.ui

RESOURCES += \
    Resources.qrc

DISTFILES += \
    AgendaTelefonica_en.ts \
    AgendaTelefonica_it.ts


