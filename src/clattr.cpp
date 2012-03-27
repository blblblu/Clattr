#include "clattr.h"
#include "ui_clattr.h"

Clattr::Clattr(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::Clattr)
{
	ui->setupUi(this);

	Letter letter;

	setUiData(letter);

	connect(ui->actionAbout, SIGNAL(triggered()), this, SLOT(showAbout()));
	connect(ui->actionAboutQt, SIGNAL(triggered()), this, SLOT(showAboutQt()));
	connect(ui->actionExportAsTex, SIGNAL(triggered()), this, SLOT(exportAsTex()));
	connect(ui->actionLicense, SIGNAL(triggered()), this, SLOT(showLicense()));
	connect(ui->actionNew, SIGNAL(triggered()), this, SLOT(newFile()));
	connect(ui->actionOpen, SIGNAL(triggered()), this, SLOT(openLetter()));
	connect(ui->actionSaveAs, SIGNAL(triggered()), this, SLOT(saveLetterAs()));
	connect(ui->actionSettings, SIGNAL(triggered()),this, SLOT(showSettings()));
}

Clattr::~Clattr() {
	delete ui;
}

Letter Clattr::uiData() {
	return Letter(
				ui->inputAlign->currentIndex(),
				ui->inputAttachement->document()->toPlainText(),
				ui->boolAttachement->checkState(),
				ui->inputClosing->text(),
				ui->inputDate->date(),
				ui->inputFontsize->value(),
				ui->inputLanguage->text(),
				ui->inputObject->text(),
				ui->inputOpening->text(),
				ui->inputPackages->document()->toPlainText(),
				ui->inputReceiver->document()->toPlainText(),
				ui->inputSenderaddress->document()->toPlainText(),
				ui->inputSendername->text(),
				ui->inputSignature->document()->toPlainText(),
				ui->inputTemplate->currentText(),
				ui->inputText->document()->toPlainText());
}

void Clattr::setUiData(Letter &letter) {
	ui->inputAlign->setCurrentIndex(letter.chosenAlign);
	ui->inputAttachement->setPlainText(letter.chosenAttachements);
	ui->boolAttachement->setChecked(letter.chosenBoolAttachements);
	ui->inputClosing->setText(letter.chosenClosing);
	ui->inputDate->setDate(letter.chosenDate);
	ui->inputFontsize->setValue(letter.chosenFontsize);
	ui->inputLanguage->setText(letter.chosenLanguage);
	ui->inputObject->setText(letter.chosenObject);
	ui->inputOpening->setText(letter.chosenOpening);
	ui->inputPackages->setPlainText(letter.chosenPackages);
	ui->inputReceiver->setPlainText(letter.chosenReceiver);
	ui->inputSenderaddress->setPlainText(letter.chosenSenderAddress);
	ui->inputSendername->setText(letter.chosenSenderName);
	ui->inputSignature->setPlainText(letter.chosenSignature);
	ui->inputTemplate->setEditText(letter.chosenTemplate);
	ui->inputText->setPlainText(letter.chosenText);
}

void Clattr::exportAsTex() {
	QString pathToFile = QFileDialog::getSaveFileName(this, tr("Export letter as *.tex"), QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation), tr("TeX document (*.tex)"));
	QFile file(pathToFile);
	if(file.open(QIODevice::WriteOnly | QIODevice::Text)) {
		QTextStream out(&file);
		try{
			out << uiData().toTex(QApplication::applicationDirPath() + "/templates");
			file.close();

			// ask user wheter he wants to run LaTeX
			int reply = QMessageBox::question(this, tr("Run LaTeX"), tr("Do you want to run LaTeX?"), QMessageBox::Yes, QMessageBox::No);
			if(reply == QMessageBox::Yes){
				QString outputDirectory = QFileDialog::getExistingDirectory(this, tr("Choose output directory"), QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation));
				int fail = system(QSettings().value("latex/latexcommand").toString().toAscii() + " --halt-on-error --output-directory=" + outputDirectory.toAscii() + " " + pathToFile.toAscii());
				if(fail){
					QMessageBox::warning(this, tr("Error"), tr("Couldn't create output file"));
				}
			}
			// catch exceptions thrown by Letter::toTex()
		} catch(int e){
			switch(e){
			case 1:
				QMessageBox::warning(0, tr("Error"), tr("Couldn't open template"));
				break;
			}
		}
	} else {
		QMessageBox::warning(this, tr("Error"), tr("*.tex file couldn't be saved"));
	}
}

void Clattr::newFile(){
	Letter letter;
	setUiData(letter);
}

void Clattr::openLetter() {
	QString pathToFile = QFileDialog::getOpenFileName(this, tr("Open letter"), QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation), tr("Clattr files (*.cltr)"));
	QFile file(pathToFile);
	if(file.open(QIODevice::ReadOnly)) {
		QDataStream in(&file);
		Letter letter;

		try{
			in >> letter;
		} catch(int e){
			switch(e){
			case 2:
				QMessageBox::warning(0, tr("Error"), tr("Bad file type"));
				break;
			}
		}

		file.close();
		setUiData(letter);
	} else {
		qWarning() << tr("Error: Chosen file not found").toAscii();
	}
}

void Clattr::saveLetterAs() {
	QString pathToFile = QFileDialog::getSaveFileName(this, tr("Save letter as"), QDesktopServices::storageLocation(QDesktopServices::DocumentsLocation), tr("Clattr files (*.cltr)"));
	QFile file(pathToFile);
	if(file.open(QIODevice::WriteOnly)) {
		QDataStream out(&file);
		out << uiData();
		file.close();
	} else {
		qWarning() << tr("Error: file couldn't be saved");
	}
}

void Clattr::showAbout() {
	QString title = tr("About Clattr");
	QString text = tr("Easily create LaTeX letters<br />(c) 2012 Sebastian Schulz");

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

void Clattr::showSettings() {
	Settings settings(this);
	settings.exec();
}
