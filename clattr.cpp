#include "clattr.h"
#include "ui_clattr.h"

Clattr::Clattr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clattr)
{
    ui->setupUi(this);

    Letter letter = Letter();

    setUiData(letter);

    settings = new Settings(this);

    connect(ui->actionSettings, SIGNAL(triggered()),this, SLOT(showSettings()));

    connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
    connect(ui->actionLicense, SIGNAL(triggered()), this, SLOT(showLicense()));
    connect(ui->actionAboutQt, SIGNAL(triggered()), this, SLOT(showAboutQt()));
}

Clattr::~Clattr(){
    delete ui;
    delete settings;
}

void Clattr::setUiData(Letter &letter){
    // document settings
    // // document
    ui->inputTemplate->setText(letter.chosenTemplate);
    ui->inputFontsize->setValue(letter.chosenFontsize);
    ui->inputLanguage->setText(letter.chosenLanguage);
    ui->inputAlign->setCurrentIndex(letter.chosenAlign);
    // // time
    ui->inputDate->setDate(letter.chosenDate);
    // content
    // // addresses
    ui->inputSendername->setText(letter.chosenSenderName);
    ui->inputSenderaddress->setPlainText(letter.chosenSenderAddress);
    ui->inputReceiver->setPlainText(letter.chosenReceiver);
    // // sentences
    ui->inputObject->setText(letter.chosenObject);
    ui->inputOpening->setText(letter.chosenOpening);
    ui->inputClosing->setText(letter.chosenClosing);
    ui->inputSignature->setPlainText(letter.chosenSignature);
    // // text
    ui->inputText->setPlainText(letter.chosenText);
    // extras
    // // packages
    ui->inputPackages->setPlainText(letter.chosenPackages);
    // // attachements
    ui->boolAttachement->setEnabled(letter.chosenBoolAttachements);
    ui->inputAttachement->setPlainText(letter.chosenAttachements);
}

void Clattr::showSettings(){
    settings->exec();
}

void Clattr::showAbout() {
    QString title = tr ("About Clattr");
    QString text = tr ("Easily create LaTeX letters<br />(c) 2012 Sebastian Schulz");

    QMessageBox::about(this, title, text);
}

void Clattr::showAboutQt() {
    QMessageBox::aboutQt(this);
}

void Clattr::showLicense() {
    QString title = tr("License");
    QString text = tr("Copyright (C) 2012  Sebastian Schulz<br />"
                      "This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.<br />"
                      "This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.<br />"
                      "You should have received a copy of the GNU General Public License along with this program.  If not, see <a href=\"http://www.gnu.org/licenses/\">http://www.gnu.org/licenses/</a>.");

    QMessageBox::about(this, title, text);
}
