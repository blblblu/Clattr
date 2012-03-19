#ifndef CLATTR_H
#define CLATTR_H

#include <QMainWindow>
#include <QMessageBox>
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
    void setUiData(Letter &letter);

private slots:
    void showSettings();
    void showAbout();
    void showAboutQt();
    void showLicense();
};

#endif // CLATTR_H
