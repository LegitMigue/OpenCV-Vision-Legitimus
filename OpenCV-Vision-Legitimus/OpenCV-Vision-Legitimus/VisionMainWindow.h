#pragma once

#include <QtWidgets/QMainWindow>
#include <QSerialPortInfo>
#include <QSerialPort>
#include "ui_VisionMainWindow.h"
#include "videoPlayer.h"

class VisionMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	VisionMainWindow(QWidget *parent = Q_NULLPTR);
	~VisionMainWindow();
protected:

private slots:
	//Display video in GUI
	void updatePlayerUI(QImage img);
	//Buttons handlers
	void on_refreshSerialPortsButton_clicked();
	void on_serialPortConnectionButton_clicked();
	void on_serialPortDisconnectionButton_clicked();
	void on_serialPortTest1Button_clicked();
	void on_serialPortTest2Button_clicked();

private:
	Ui::VisionMainWindowClass ui;
	VideoPlayer* videoPlayer;
	QSerialPort *serial;

	void updateSerialPorts();
	void serialPortConnection();
	void serialPortDisconnection();
};
