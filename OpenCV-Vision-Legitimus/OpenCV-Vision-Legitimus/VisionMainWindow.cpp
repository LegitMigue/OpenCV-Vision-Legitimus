#include "VisionMainWindow.h"

//Main window
VisionMainWindow::VisionMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	videoPlayer = new VideoPlayer();
	//Connect to the VideoPlayer thread signal get it (or wait for it) and send it to updatePlayerUI function
	QObject::connect(videoPlayer, SIGNAL(processedImage(QImage)),
		this, SLOT(updatePlayerUI(QImage)));
	
	//Start GUI
	ui.setupUi(this);

	//Start VideoPlayer thread
	videoPlayer->Play();
}

//Recieve QImage from VideoPlayer thread and draw it in GUI video frame (keeping video frame resolution ratio)
void VisionMainWindow::updatePlayerUI(QImage img)
{
	if (!img.isNull())
	{
		ui.videoFrame->setAlignment(Qt::AlignCenter);
		ui.videoFrame->setPixmap(QPixmap::fromImage(img).scaled(ui.videoFrame->size(),
			Qt::KeepAspectRatio, Qt::FastTransformation));
	}
}

VisionMainWindow::~VisionMainWindow()
{
	delete videoPlayer;
	
}