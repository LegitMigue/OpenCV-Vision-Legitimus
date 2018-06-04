#pragma once
#ifndef VIDEOPLAYER_H
#define VIDEOPLAYER_H
#include <QMutex>
#include <QThread>
#include <QImage>
#include <QWaitCondition>
#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
using namespace cv;
class VideoPlayer : public QThread
{
	Q_OBJECT
private:
	bool stop;
	int frameRate;
	Mat videoFrame;
	VideoCapture cameraCapture;
	Mat RGBVideoFrame;
	QImage videoMainImg;
	QMutex videoQMutex;
	QWaitCondition videoQCondition;
signals:
	//Main signal for GUI thread
	void processedImage(const QImage &image);
protected:
	//Convert VideoCapture from primary camera to QImage and emit it to GUI 
	void run();
public:
	VideoPlayer(QObject *parent = 0);
	~VideoPlayer();
	bool isStopped() const;
	//Start thread and video streaming
	void Play();
	//Stop video streaming
	void Stop();
};
#endif // VIDEOPLAYER_H