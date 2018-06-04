#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_VisionMainWindow.h"

class VisionMainWindow : public QMainWindow
{
	Q_OBJECT

public:
	VisionMainWindow(QWidget *parent = Q_NULLPTR);

private:
	Ui::VisionMainWindowClass ui;
};
