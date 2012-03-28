#ifndef CLATTR_H
#define CLATTR_H

#include <QApplication>
#include <QDataStream>
#include <QDesktopServices>
#include <QFile>
#include <QFileDialog>
#include <QIODevice>
#include <QMainWindow>
#include <QMessageBox>
#include <QtDebug>
#include <QTextStream>
#include <QThread>

#include "latexworker.h"
#include "letter.h"
#include "settings.h"

namespace Ui {
class Clattr;
}

/*!
 * \brief Clattr class (main window)
 */
class Clattr : public QMainWindow
{
	Q_OBJECT

public:
	/*!
	 * \brief Constructor
	 *
	 * \param parent ... default is 0
	 */
	explicit Clattr(QWidget *parent = 0);
	/*!
	 * \brief Destructor
	 *
	 */
	~Clattr();

private:
	Ui::Clattr *ui;
	LatexWorker * latexWorker;
	QThread *latexThread;
	Letter uiData();
	void setUiData(Letter &letter);

private slots:
	void exportAsTex();
	void newFile();
	void openLetter();
	void saveLetterAs();
	void showAbout();
	void showAboutQt();
	void showLicense();
	void showSettings();
};

#endif // CLATTR_H
