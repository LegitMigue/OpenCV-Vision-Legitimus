#include "videoPlayer.h"
VideoPlayer::VideoPlayer(QObject *parent)
	: QThread(parent)
{
	//CameraCapture = 0 to get default camera input (to change)
	cameraCapture = 0;
	stop = true;
}

void VideoPlayer::Play()
{
	//Start the VideoPlayer Thread
	if (!isRunning()) {
		if (isStopped()) {
			stop = false;
		}
		start(LowPriority);
	}
}

void VideoPlayer::run()
{
	//Calculate a normal delay based on camera framerate to prevent non useful emits from the thread
	int delay = (1000 / frameRate)+1;
	while (!stop) {
		if (!cameraCapture.read(videoFrame))
		{
			stop = true;
		}
		//If we got color from the camera, use it
		if (videoFrame.channels() == 3) {
			cv::cvtColor(videoFrame, RGBVideoFrame, CV_BGR2RGB);
			videoMainImg = QImage((const unsigned char*)(RGBVideoFrame.data),
				RGBVideoFrame.cols, RGBVideoFrame.rows, QImage::Format_RGB888);
		}
		//If not, use grey scale
		else
		{
			videoMainImg = QImage((const unsigned char*)(videoFrame.data),
				videoFrame.cols, videoFrame.rows, QImage::Format_Indexed8);
		}
		//Thread emit QImage to the QT GUI
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