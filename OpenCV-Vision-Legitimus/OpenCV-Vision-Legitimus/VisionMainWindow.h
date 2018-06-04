#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VisionMainWindow.h"
#include "videoPlayer.h"

class VisionMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	VisionMainWindow(QWidget *parent = Q_NULLPTR);
	~VisionMainWindow();
private slots:
	//Display video in GUI
	void updatePlayerUI(QImage img);
private:
	Ui::VisionMainWindowClass ui;
	VideoPlayer* videoPlayer;
};
