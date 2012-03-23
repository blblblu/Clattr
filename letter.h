#ifndef LETTER_H
#define LETTER_H

#include <QDataStream>
#include <QDate>
#include <QFile>
#include <QIODevice>
#include <QString>

#define ALIGN_JUSTIFY 0
#define ALIGN_LEFT    1
#define ALIGN_RIGHT   2

class Letter
{
public:
    Letter();
    Letter(
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
            QString newText);

    void setContent(
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
            QString newText);

    QString toTex(QString templateDir);

    int chosenAlign;
    QString chosenAttachements;
    bool chosenBoolAttachements;
    QString chosenClosing;
    QDate chosenDate;
    int chosenFontsize;
    QString chosenLanguage;
    QString chosenObject;
    QString chosenOpening;
    QString chosenPackages;
    QString chosenReceiver;
    QString chosenSenderAddress;
    QString chosenSenderName;
    QString chosenSignature;
    QString chosenTemplate;
    QString chosenText;
};

QDataStream &operator<<(QDataStream &out, const Letter &letter);
QDataStream &operator>>(QDataStream &in, Letter &letter);

#endif // LETTER_H
