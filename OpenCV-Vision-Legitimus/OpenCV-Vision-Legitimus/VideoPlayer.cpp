#include "videoPlayer.h"
VideoPlayer::VideoPlayer(QObject *parent)
	: QThread(parent)
{
	stop = true;
}

void VideoPlayer::Play()
{
	if (!isRunning()) {
		if (isStopped()) {
			stop = false;
		}
		start(LowPriority);
	}
}

void VideoPlayer::run()
{
	int delay = (1000 / frameRate);
	while (!stop) {
		if (!cameraCapture.read(videoFrame))
		{
			stop = true;
		}
		if (videoFrame.channels() == 3) {
			cv::cvtColor(videoFrame, RGBVideoFrame, CV_BGR2RGB);
			videoMainImg = QImage((const unsigned char*)(RGBVideoFrame.data),
				RGBVideoFrame.cols, RGBVideoFrame.rows, QImage::Format_RGB888);
		}
		else
		{
			videoMainImg = QImage((const unsigned char*)(videoFrame.data),
				videoFrame.cols, videoFrame.rows, QImage::Format_Indexed8);
		}
		emit processedImage(videoMainImg);
		this->msleep(delay);
	}
}

VideoPlayer::~VideoPlayer()
{
	videoQMutex.lock();
	stop = true;
	cameraCapture.release();
	videoQCondition.wakeOne();
	videoQMutex.unlock();
	wait();
}
void VideoPlayer::Stop()
{
	stop = true;
}
bool VideoPlayer::isStopped() const {
	return this->stop;
}