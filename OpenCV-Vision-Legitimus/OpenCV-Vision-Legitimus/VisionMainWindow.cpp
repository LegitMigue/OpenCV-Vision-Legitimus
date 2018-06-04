#include "VisionMainWindow.h"

VisionMainWindow::VisionMainWindow(QWidget *parent)
	: QMainWindow(parent)
{
	videoPlayer = new VideoPlayer();
	QObject::connect(videoPlayer, SIGNAL(processedImage(QImage)),
		this, SLOT(updatePlayerUI(QImage)));

	ui.setupUi(this);

	videoPlayer->Play();
}

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