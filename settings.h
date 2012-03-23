#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include <QSettings>
#include <QString>

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT
    
public:
    explicit Settings(QWidget *parent = 0);
    ~Settings();

    QString latexCommand();
    
private:
    Ui::Settings *ui;
    QSettings *qSettings;

private slots:
    void acceptSettings();
    void rejectSettings();
};

#endif // SETTINGS_H
