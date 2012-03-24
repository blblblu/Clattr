#include "letter.h"

Letter::Letter(){
	setContent(ALIGN_JUSTIFY, "", false, "", QDate::currentDate(), 10, "ngerman", "", "", "", "", "", "", "", "scrlttr2", "");
}

Letter::Letter(
		int newAlign,
		QString newAttachements,
		bool newBoolAttachements,
		QString newClosing,
		QDate newDate,
		int newFontsize,
		QString newLanguage,
		QString newObject,
		QString newOpening,
		QString newPackages,
		QString newReceiver,
		QString newSenderAddress,
		QString newSenderName,
		QString newSignature,
		QString newTemplate,
		QString newText){
	setContent(
				newAlign,
				newAttachements,
				newBoolAttachements,
				newClosing,
				newDate,
				newFontsize,
				newLanguage,
				newObject,
				newOpening,
				newPackages,
				newReceiver,
				newSenderAddress,
				newSenderName,
				newSignature,
				newTemplate,
				newText);
	;
}

QString Letter::toTex(QString templateDir){
	// replace \n with \\\\\n
	Letter *tmp = this;
	tmp->chosenAttachements.replace("\n", "\\\\\n");
	tmp->chosenReceiver.replace("\n", "\\\\\n");
	tmp->chosenSenderAddress.replace("\n", "\\\\\n");
	tmp->chosenSignature.replace("\n", "\\\\\n");
	tmp->chosenText.replace("\n", "\\\\\n");

	// load template
	QString texString;

	QFile templateFile(templateDir + "/" + chosenTemplate + "/template.tex");
	if(!templateFile.open(QIODevice::ReadOnly | QIODevice::Text)){
		throw 1;
	} else {
		texString = templateFile.readAll();
	}
	templateFile.close();

	// replace the dummies with the information of the given letter
	if(chosenAlign == ALIGN_LEFT){
		texString.replace("%<align>", "\\\\flushleft");
	} else if(chosenAlign == ALIGN_RIGHT) {
		texString.replace("%<align>", "\\\\flushright");
	}
	if(chosenBoolAttachements){
		texString.replace("%<boolattachement>", "");
		texString.replace("%<attachement>", tmp->chosenAttachements);
	}
	texString.replace("%<closing>", chosenClosing);
	texString.replace("%<date>", chosenDate.toString("dd.MM.yyyy"));
	texString.replace("%<fontsize>", QString().setNum(chosenFontsize));
	texString.replace("%<language>", chosenLanguage);
	texString.replace("%<object>", chosenObject);
	texString.replace("%<opening>", chosenOpening);
	texString.replace("%<packages>", chosenPackages);
	texString.replace("%<receiver>", chosenReceiver);
	texString.replace("%<senderaddress>", chosenSenderAddress);
	texString.replace("%<sendername>", chosenSenderName);
	texString.replace("%<signature>", chosenSignature);
	texString.replace("%<text>", chosenText);

	return texString;
}

void Letter::setContent(
		int newAlign,
		QString newAttachements,
		bool newBoolAttachements,
		QString newClosing,
		QDate newDate,
		int newFontsize,
		QString newLanguage,
		QString newObject,
		QString newOpening,
		QString newPackages,
		QString newReceiver,
		QString newSenderAddress,
		QString newSenderName,
		QString newSignature,
		QString newTemplate,
		QString newText){
	chosenAlign            = newAlign;
	chosenAttachements     = newAttachements;
	chosenBoolAttachements = newBoolAttachements;
	chosenClosing          = newClosing;
	chosenDate             = newDate;
	chosenFontsize         = newFontsize;
	chosenLanguage         = newLanguage;
	chosenObject           = newObject;
	chosenOpening          = newOpening;
	chosenPackages         = newPackages;
	chosenReceiver         = newReceiver;
	chosenSenderAddress    = newSenderAddress;
	chosenSenderName       = newSenderName;
	chosenSignature        = newSignature;
	chosenTemplate         = newTemplate;
	chosenText             = newText;
}

QDataStream &operator<<(QDataStream &out, const Letter &letter){
	out << letter.chosenAlign
			<< letter.chosenAttachements
			<< letter.chosenBoolAttachements
			<< letter.chosenClosing
			<< letter.chosenDate
			<< letter.chosenFontsize
			<< letter.chosenLanguage
			<< letter.chosenObject
			<< letter.chosenOpening
			<< letter.chosenPackages
			<< letter.chosenReceiver
			<< letter.chosenSenderAddress
			<< letter.chosenSenderName
			<< letter.chosenSignature
			<< letter.chosenTemplate
			<< letter.chosenText;

	return out;
}

QDataStream &operator>>(QDataStream &in, Letter &letter){
	int newAlign;
	QString newAttachements;
	bool newBoolAttachements;
	QString newClosing;
	QDate newDate;
	int newFontsize;
	QString newLanguage;
	QString newObject;
	QString newOpening;
	QString newPackages;
	QString newReceiver;
	QString newSenderAddress;
	QString newSenderName;
	QString newSignature;
	QString newTemplate;
	QString newText;

	in  >> newAlign
			>> newAttachements
			>> newBoolAttachements
			>> newClosing
			>> newDate
			>> newFontsize
			>> newLanguage
			>> newObject
			>> newOpening
			>> newPackages
			>> newReceiver
			>> newSenderAddress
			>> newSenderName
			>> newSignature
			>> newTemplate
			>> newText;

	letter.setContent(
				newAlign,
				newAttachements,
				newBoolAttachements,
				newClosing,
				newDate,
				newFontsize,
				newLanguage,
				newObject,
				newOpening,
				newPackages,
				newReceiver,
				newSenderAddress,
				newSenderName,
				newSignature,
				newTemplate,
				newText);
	return in;
}
