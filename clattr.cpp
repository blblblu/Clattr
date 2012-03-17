#include <QMessageBox>
#include "clattr.h"
#include "ui_clattr.h"

Clattr::Clattr(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Clattr)
{
    ui->setupUi(this);

    connect(ui->actionAbout, SIGNAL(triggered(bool)), this, SLOT(showAbout()));
    connect(ui->actionLicense, SIGNAL(triggered(bool)), this, SLOT(showLicense()));
    connect(ui->actionAboutQt, SIGNAL(triggered(bool)), this, SLOT(showAboutQt()));
}

Clattr::~Clattr()
{
    delete ui;
}


void Clattr::showAbout(){
    QString title = tr ("About Clattr");
    QString text = tr ("Easily create LaTeX letters<br />(c) 2012 Sebastian Schulz");

    QMessageBox::about (this, title, text);
}

void Clattr::showAboutQt(){
    QMessageBox::aboutQt(this);
}

void Clattr::showLicense(){
    QString title = tr ("License");
    QString text = tr ("Copyright (C) 2011  Sebastian Schulz<br />"
                        "This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.<br />"
                        "This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for more details.<br />"
                        "You should have received a copy of the GNU General Public License along with this program.  If not, see <http://www.gnu.org/licenses/>.");

    QMessageBox::about (this, title, text);
}
