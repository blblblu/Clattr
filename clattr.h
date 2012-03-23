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

#include "letter.h"
#include "settings.h"

namespace Ui {
class Clattr;
}

class Clattr : public QMainWindow
{
    Q_OBJECT

public:
    explicit Clattr(QWidget *parent = 0);
    ~Clattr();

private:
    Ui::Clattr *ui;
    Settings *settings;
    Letter uiData();
    void setUiData(Letter &letter);

private slots:
    void exportAsTex();
    void openLetter();
    void saveLetterAs();
    void showAbout();
    void showAboutQt();
    void showLicense();
    void showSettings();
};

#endif // CLATTR_H
