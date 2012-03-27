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

/*!
 * \brief Letter Class
 */
class Letter
{
public:
	/*!
	 * \brief Constructor
	 *
	 */
	Letter();
	/*!
	 * \brief Constructor, setting whole content at once
	 *
	 * \param newAlign ...
	 * \param newAttachements ...
	 * \param newBoolAttachements ...
	 * \param newClosing ...
	 * \param newDate ...
	 * \param newFontsize ...
	 * \param newLanguage ...
	 * \param newObject ...
	 * \param newOpening ...
	 * \param newPackages ...
	 * \param newReceiver ...
	 * \param newSenderAddress ...
	 * \param newSenderName ...
	 * \param newSignature ...
	 * \param newTemplate ...
	 * \param newText ...
	 */
	Letter(
			const int newAlign,
			const QString newAttachements,
			const bool newBoolAttachements,
			const QString newClosing,
			const QDate newDate,
			const int newFontsize,
			const QString newLanguage,
			const QString newObject,
			const QString newOpening,
			const QString newPackages,
			const QString newReceiver,
			const QString newSenderAddress,
			const QString newSenderName,
			const QString newSignature,
			const QString newTemplate,
			const QString newText);

	/*!
	 * \brief set whole content at once
	 *
	 * \param newAlign ...
	 * \param newAttachements ...
	 * \param newBoolAttachements ...
	 * \param newClosing ...
	 * \param newDate ...
	 * \param newFontsize ...
	 * \param newLanguage ...
	 * \param newObject ...
	 * \param newOpening ...
	 * \param newPackages ...
	 * \param newReceiver ...
	 * \param newSenderAddress ...
	 * \param newSenderName ...
	 * \param newSignature ...
	 * \param newTemplate ...
	 * \param newText ...
	 * \return void
	 */
	void setContent(
			const int newAlign,
			const QString newAttachements,
			const bool newBoolAttachements,
			const QString newClosing,
			const QDate newDate,
			const int newFontsize,
			const QString newLanguage,
			const QString newObject,
			const QString newOpening,
			const QString newPackages,
			const QString newReceiver,
			const QString newSenderAddress,
			const QString newSenderName,
			const QString newSignature,
			const QString newTemplate,
			const QString newText);

	/*!
	 * \brief creates a LaTeX document
	 *
	 * \param templateDir ...
	 * \return QString
	 */
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
