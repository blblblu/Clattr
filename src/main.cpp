#include <QApplication>
#include <QLibraryInfo>
#include <QLocale>
#include <QTranslator>
#include "clattr.h"

int main(int argc, char *argv[]){
	QApplication::setOrganizationName("Sebastian Schulz");
	QApplication::setApplicationName("Clattr");

	QApplication a(argc, argv);

	QTranslator qtTranslator;
	qtTranslator.load("qt_" + QLocale::system().name(), QLibraryInfo::location(QLibraryInfo::TranslationsPath));
	a.installTranslator(&qtTranslator);

	QTranslator myappTranslator;
	myappTranslator.load(":/translations/clattr_" + QLocale::system().name());
	a.installTranslator(&myappTranslator);

	Clattr w;
	w.show();

	return a.exec();
}
