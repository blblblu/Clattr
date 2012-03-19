#include "letter.h"

Letter::Letter(){
    SetContent(ALIGN_JUSTIFY, "", false, "", QDate::currentDate(), 10, "ngerman", "", "", "", "", "", "", "", "scrlttr2", "");
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
    SetContent(
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
}

void Letter::SetContent(
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

    letter.SetContent(
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
