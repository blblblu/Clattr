#ifndef CLATTR_H
#define CLATTR_H

#include <QMainWindow>

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

private slots:
    void showAbout();
    void showAboutQt();
    void showLicense();
};

#endif // CLATTR_H
