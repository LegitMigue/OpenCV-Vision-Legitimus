#include "VisionMainWindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VisionMainWindow w;
	w.show();
	return a.exec();
}
