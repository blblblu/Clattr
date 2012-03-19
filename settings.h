#ifndef SETTINGS_H
#define SETTINGS_H

#include <iostream>
#include <QDialog>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();
    
private:
    Ui::Settings *ui;

private slots:
    void acceptSettings();
};

#endif // SETTINGS_H
