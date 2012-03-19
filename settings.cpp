#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(acceptSettings()));
}

Settings::~Settings(){
    delete ui;
}


void Settings::acceptSettings(){
    std::cout << "OK clicked" << std::endl;
}
