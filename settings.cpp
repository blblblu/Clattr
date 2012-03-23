#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    connect(this, SIGNAL(accepted()), this, SLOT(acceptSettings()));
    connect(this, SIGNAL(rejected()), this, SLOT(rejectSettings()));

    qSettings = new QSettings("Sebastian Schulz", "Clattr");

    ui->inputLatexCommand->setText(this->latexCommand());
}

Settings::~Settings(){
    delete ui;
    delete qSettings;
}

QString Settings::latexCommand(){
    return qSettings->value("latex/latexCommand", "pdflatex").toString();
}

void Settings::acceptSettings(){
    qSettings->setValue("latex/latexCommand", ui->inputLatexCommand->text());
}

void Settings::rejectSettings(){
    ui->inputLatexCommand->setText(this->latexCommand());
}
