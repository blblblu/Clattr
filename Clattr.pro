#-------------------------------------------------
#
# Project created by QtCreator 2012-03-17T22:03:15
#
#-------------------------------------------------

QT       += core gui

TARGET = Clattr
TEMPLATE = app


SOURCES +=  src/settings.cpp \
    src/main.cpp \
    src/letter.cpp \
    src/clattr.cpp

HEADERS  += clattr.h \
    settings.h \
    src/settings.h \
    src/letter.h \
    src/clattr.h

RESOURCES += \
    clattr.qrc

OTHER_FILES += \
    README.markdown \
    templates/scrlttr2/template.tex \
    templates/scrlttr2old/template.tex \
    clattr_de_DE.ts \
    clattr_de_DE.qm \
    translations/clattr_de_DE.ts \
    translations/clattr_de_DE.qm

TRANSLATIONS    += translations/clattr_de_DE.ts

FORMS += \
    ui/settings.ui \
    ui/clattr.ui
