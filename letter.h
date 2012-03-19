#ifndef LETTER_H
#define LETTER_H

#include <QDate>
#include <QString>
#include <QDataStream>

#define ALIGN_JUSTIFY 0
#define ALIGN_LEFT    1
#define ALIGN_RIGHT   2

class Letter
{
public:
    Letter();
    Letter(
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
        QString newAttachements);
    void SetContent(
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
        QString newAttachements);
    QString chosenTemplate;
    int chosenFontsize;
    QString chosenLanguage;
    int chosenAlign;
    // // time
    QDate chosenDate;
    // content
    // // addresses
    QString chosenSenderName;
    QString chosenSenderAddress;
    QString chosenReceiver;
    // // sentences
    QString chosenObject;
    QString chosenOpening;
    QString chosenClosing;
    QString chosenSignature;
    // // text
    QString chosenText;
    // extras
    // // packages
    QString chosenPackages;
    // // attachements
    bool chosenBoolAttachements;
    QString chosenAttachements;
};

QDataStream &operator<<(QDataStream &out, const Letter &letter);
QDataStream &operator>>(QDataStream &in, Letter &letter);

#endif // LETTER_H
