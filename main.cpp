#include <QApplication>
#include "clattr.h"

int main(int argc, char *argv[]){
	QApplication a(argc, argv);
	Clattr w;
	w.show();

	return a.exec();
}
