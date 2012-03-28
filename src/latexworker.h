#ifndef LATEXWORKER_H
#define LATEXWORKER_H

#include <QObject>
#include <QSettings>

class LatexWorker : public QObject
{
	Q_OBJECT
public:
	explicit LatexWorker(QObject *parent = 0);
	bool isRunning();
	void setJobData(const QString newOutputDirectory, const QString newPathToFile);
	
signals:

public slots:
	void doWork();
	
private:
	bool nowRunning;
	QString outputDirectory;
	QString pathToFile;
};

#endif // LATEXWORKER_H
