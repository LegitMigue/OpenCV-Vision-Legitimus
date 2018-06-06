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
	//Initializing Serial Port
	serial = new QSerialPort;

	//Udate and show available serial ports
	updateSerialPorts();

	//GUI signals connections
	connect(ui.refreshSerialPortsPushButton, SIGNAL(released()), this, SLOT(on_refreshSerialPortsButton_clicked()));
	connect(ui.serialConnectPushButton, SIGNAL(released()), this, SLOT(on_serialPortConnectionButton_clicked()));
	connect(ui.serialDisconnectPushButton, SIGNAL(released()), this, SLOT(on_serialPortDisconnectionButton_clicked()));
	connect(ui.serialPortTest1Button, SIGNAL(released()), this, SLOT(on_serialPortTest1Button_clicked()));
	connect(ui.serialPortTest2Button, SIGNAL(released()), this, SLOT(on_serialPortTest2Button_clicked()));
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

//Update serial ports list and insert then in a combobox
void VisionMainWindow::updateSerialPorts()
{
	QString temp;
	ui.serialPortsComboBox->clear();
	ui.consolePlainText->appendPlainText("Avaiable serial ports:");
	Q_FOREACH(QSerialPortInfo port, QSerialPortInfo::availablePorts()) {
		ui.serialPortsComboBox->addItem(port.portName());
		ui.consolePlainText->appendPlainText("Com port: " + port.portName());
		if (port.hasProductIdentifier()) {
			temp = port.productIdentifier();
			ui.consolePlainText->appendPlainText("Product identifier: " + temp);
		}
		if (port.hasVendorIdentifier()) {
			temp = port.vendorIdentifier();
			ui.consolePlainText->appendPlainText("Vendor identifier: " + temp);
		}
	}


}

//Connect to the selected serial port
void VisionMainWindow::serialPortConnection()
{
	QString port = ui.serialPortsComboBox->currentText();

	ui.consolePlainText->appendPlainText("Connected to port: " + port);

	serial->setPortName(port);
	serial->open(QIODevice::ReadWrite);
	serial->setBaudRate(QSerialPort::Baud9600);
	serial->setDataBits(QSerialPort::Data8);
	serial->setParity(QSerialPort::NoParity);
	serial->setStopBits(QSerialPort::OneStop);
	serial->setFlowControl(QSerialPort::NoFlowControl);
	serial->setDataTerminalReady(true);

}

//Disconnect from the connected serial port
void VisionMainWindow::serialPortDisconnection()
{
	serial->close();
}

//Button handlers
void VisionMainWindow::on_refreshSerialPortsButton_clicked()
{
	updateSerialPorts();
}
void VisionMainWindow::on_serialPortConnectionButton_clicked()
{
	serialPortConnection();
}
void VisionMainWindow::on_serialPortDisconnectionButton_clicked()
{
	serialPortDisconnection();
}
void VisionMainWindow::on_serialPortTest1Button_clicked()
{
	serial->write("1\n");
	//serial->flush();
	serial->waitForBytesWritten(1000);
}
void VisionMainWindow::on_serialPortTest2Button_clicked()
{
	serial->write("2\n");
	//serial->flush();
	serial->waitForBytesWritten(1000);
}
//Destructor
VisionMainWindow::~VisionMainWindow()
{
	delete videoPlayer;
	//GUI destructor is already implemented by QT
}