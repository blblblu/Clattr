#include "latexworker.h"

LatexWorker::LatexWorker(QObject *parent) :
	QObject(parent)
{
	nowRunning = false;
	outputDirectory = "";
	pathToFile = "";
}

bool LatexWorker::isRunning(){
	return nowRunning;
}

void LatexWorker::doWork(){
	nowRunning = true;

    int fail = system(QSettings().value("latex/latexcommand", "pdflatex").toString().toUtf8() + " --halt-on-error --output-directory=" + outputDirectory.toUtf8() + " " + pathToFile.toUtf8());

	outputDirectory = "";
	pathToFile = "";

	nowRunning = false;
}

void LatexWorker::setJobData(const QString newOutputDirectory, const QString newPathToFile){
	outputDirectory = newOutputDirectory;
	pathToFile = newPathToFile;
}
