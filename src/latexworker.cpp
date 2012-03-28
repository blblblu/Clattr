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

	int fail = system(QSettings().value("latex/latexcommand", "pdflatex").toString().toAscii() + " --halt-on-error --output-directory=" + outputDirectory.toAscii() + " " + pathToFile.toAscii());

	outputDirectory = "";
	pathToFile = "";

	nowRunning = false;
}

void LatexWorker::setJobData(const QString newOutputDirectory, const QString newPathToFile){
	outputDirectory = newOutputDirectory;
	pathToFile = newPathToFile;
}
