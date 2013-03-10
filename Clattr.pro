#-------------------------------------------------
#
# Project created by QtCreator 2012-03-17T22:03:15
#
#-------------------------------------------------

QMAKE_LFLAGS += -static-libgcc

QT       += core gui widgets

TARGET = Clattr
TEMPLATE = app

FORMS += \
    ui/settings.ui \
    ui/clattr.ui


SOURCES +=  src/settings.cpp \
    src/main.cpp \
    src/letter.cpp \
    src/clattr.cpp \
    src/latexworker.cpp

HEADERS  += \
    src/settings.h \
    src/letter.h \
    src/clattr.h \
    src/latexworker.h

RESOURCES += \
    clattr.qrc

OTHER_FILES += \
    README.markdown \
    templates/scrlttr2/template.tex \
    templates/scrlttr2old/template.tex \
    clattr_de_DE.qm \
    translations/clattr_de_DE.ts \
    translations/clattr_de_DE.qm

TRANSLATIONS    += translations/clattr_de_DE.ts
