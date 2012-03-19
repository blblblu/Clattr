#include "letter.h"

Letter::Letter(){
    SetContent("scrlttr2", 10, "ngerman", ALIGN_JUSTIFY, QDate::currentDate(), "", "", "", "", "", "", "", "", "", false, "");
}

Letter::Letter(
    QString newTemplate,
    int newFontsize,
    QString newLanguage,
    int newAlign,
    QDate newDate,
    QString newSenderName,
    QString newSenderAddress,
    QString newReceiver,
    QString newObject,
    QString newOpening,
    QString newClosing,
    QString newSignature,
    QString newText,
    QString newPackages,
    bool newBoolAttachements,
    QString newAttachements){
    SetContent(
        newTemplate,
        newFontsize,
        newLanguage,
        newAlign,
        newDate,
        newSenderName,
        newSenderAddress,
        newReceiver,
        newObject,
        newOpening,
        newClosing,
        newSignature,
        newText,
        newPackages,
        newBoolAttachements,
        newAttachements);
}

void Letter::SetContent(
    QString newTemplate,
    int newFontsize,
    QString newLanguage,
    int newAlign,
    QDate newDate,
    QString newSenderName,
    QString newSenderAddress,
    QString newReceiver,
    QString newObject,
    QString newOpening,
    QString newClosing,
    QString newSignature,
    QString newText,
    QString newPackages,
    bool newBoolAttachements,
    QString newAttachements){
        chosenTemplate         = newTemplate;
        chosenFontsize         = newFontsize;
        chosenLanguage         = newLanguage;
        chosenAlign            = newAlign;
        chosenDate             = newDate;
        chosenSenderName       = newSenderName;
        chosenSenderAddress    = newSenderAddress;
        chosenReceiver         = newReceiver;
        chosenObject           = newObject;
        chosenOpening          = newOpening;
        chosenClosing          = newClosing;
        chosenSignature        = newSignature;
        chosenText             = newText;
        chosenPackages         = newPackages;
        chosenBoolAttachements = newBoolAttachements;
        chosenAttachements     = newAttachements;
}

QDataStream &operator<<(QDataStream &out, const Letter &letter){
    out << letter.chosenTemplate
        << letter.chosenFontsize
        << letter.chosenLanguage
        << letter.chosenAlign
        << letter.chosenDate
        << letter.chosenSenderName
        << letter.chosenSenderAddress
        << letter.chosenReceiver
        << letter.chosenObject
        << letter.chosenOpening
        << letter.chosenClosing
        << letter.chosenSignature
        << letter.chosenText
        << letter.chosenPackages
        << letter.chosenBoolAttachements
        << letter.chosenAttachements;

    return out;
}

QDataStream &operator>>(QDataStream &in, Letter &letter){
    QString newTemplate;
    int newFontsize;
    QString newLanguage;
    int newAlign;
    QDate newDate;
    QString newSenderName;
    QString newSenderAddress;
    QString newReceiver;
    QString newObject;
    QString newOpening;
    QString newClosing;
    QString newSignature;
    QString newText;
    QString newPackages;
    bool newBoolAttachements;
    QString newAttachements;

    in  >> newTemplate
        >> newFontsize
        >> newLanguage
        >> newAlign
        >> newDate
        >> newSenderName
        >> newSenderAddress
        >> newReceiver
        >> newObject
        >> newOpening
        >> newClosing
        >> newSignature
        >> newText
        >> newPackages
        >> newBoolAttachements
        >> newAttachements;

    letter.SetContent(
        newTemplate,
        newFontsize,
        newLanguage,
        newAlign,
        newDate,
        newSenderName,
        newSenderAddress,
        newReceiver,
        newObject,
        newOpening,
        newClosing,
        newSignature,
        newText,
        newPackages,
        newBoolAttachements,
        newAttachements);
    return in;
}
