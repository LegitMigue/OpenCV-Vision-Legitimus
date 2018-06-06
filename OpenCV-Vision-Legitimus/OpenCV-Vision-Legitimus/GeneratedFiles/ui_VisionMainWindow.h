/********************************************************************************
** Form generated from reading UI file 'VisionMainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VISIONMAINWINDOW_H
#define UI_VISIONMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisionMainWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *videoFrame;
    QPlainTextEdit *consolePlainText;
    QSplitter *splitter_3;
    QSplitter *splitter_2;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *serialPortsLabel;
    QPushButton *refreshSerialPortsPushButton;
    QComboBox *serialPortsComboBox;
    QSplitter *splitter;
    QPushButton *serialConnectPushButton;
    QPushButton *serialDisconnectPushButton;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QPushButton *serialPortTest1Button;
    QPushButton *serialPortTest2Button;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *VisionMainWindowClass)
    {
        if (VisionMainWindowClass->objectName().isEmpty())
            VisionMainWindowClass->setObjectName(QStringLiteral("VisionMainWindowClass"));
        VisionMainWindowClass->resize(1127, 608);
        centralWidget = new QWidget(VisionMainWindowClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        videoFrame = new QLabel(centralWidget);
        videoFrame->setObjectName(QStringLiteral("videoFrame"));
        videoFrame->setGeometry(QRect(50, 40, 631, 391));
        videoFrame->setStyleSheet(QStringLiteral("Background-color: #000;"));
        consolePlainText = new QPlainTextEdit(centralWidget);
        consolePlainText->setObjectName(QStringLiteral("consolePlainText"));
        consolePlainText->setGeometry(QRect(710, 40, 361, 271));
        QPalette palette;
        QBrush brush(QColor(0, 170, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(0, 0, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush2(QColor(120, 120, 120, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        consolePlainText->setPalette(palette);
        QFont font;
        font.setPointSize(9);
        font.setBold(true);
        font.setWeight(75);
        consolePlainText->setFont(font);
        consolePlainText->setStyleSheet(QStringLiteral("Background-color: #000;"));
        splitter_3 = new QSplitter(centralWidget);
        splitter_3->setObjectName(QStringLiteral("splitter_3"));
        splitter_3->setGeometry(QRect(53, 450, 384, 54));
        splitter_3->setOrientation(Qt::Horizontal);
        splitter_2 = new QSplitter(splitter_3);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Horizontal);
        layoutWidget = new QWidget(splitter_2);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        serialPortsLabel = new QLabel(layoutWidget);
        serialPortsLabel->setObjectName(QStringLiteral("serialPortsLabel"));
        QFont font1;
        font1.setPointSize(10);
        serialPortsLabel->setFont(font1);

        horizontalLayout->addWidget(serialPortsLabel);

        refreshSerialPortsPushButton = new QPushButton(layoutWidget);
        refreshSerialPortsPushButton->setObjectName(QStringLiteral("refreshSerialPortsPushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral("Resources/VistalCO_refresh_icon_2.png"), QSize(), QIcon::Normal, QIcon::Off);
        refreshSerialPortsPushButton->setIcon(icon);

        horizontalLayout->addWidget(refreshSerialPortsPushButton);

        serialPortsComboBox = new QComboBox(layoutWidget);
        serialPortsComboBox->setObjectName(QStringLiteral("serialPortsComboBox"));
        serialPortsComboBox->setEditable(false);

        horizontalLayout->addWidget(serialPortsComboBox);

        splitter_2->addWidget(layoutWidget);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        serialConnectPushButton = new QPushButton(splitter);
        serialConnectPushButton->setObjectName(QStringLiteral("serialConnectPushButton"));
        splitter->addWidget(serialConnectPushButton);
        serialDisconnectPushButton = new QPushButton(splitter);
        serialDisconnectPushButton->setObjectName(QStringLiteral("serialDisconnectPushButton"));
        splitter->addWidget(serialDisconnectPushButton);
        splitter_2->addWidget(splitter);
        splitter_3->addWidget(splitter_2);
        layoutWidget1 = new QWidget(splitter_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        serialPortTest1Button = new QPushButton(layoutWidget1);
        serialPortTest1Button->setObjectName(QStringLiteral("serialPortTest1Button"));

        verticalLayout->addWidget(serialPortTest1Button);

        serialPortTest2Button = new QPushButton(layoutWidget1);
        serialPortTest2Button->setObjectName(QStringLiteral("serialPortTest2Button"));

        verticalLayout->addWidget(serialPortTest2Button);

        splitter_3->addWidget(layoutWidget1);
        VisionMainWindowClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VisionMainWindowClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1127, 21));
        VisionMainWindowClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(VisionMainWindowClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        VisionMainWindowClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(VisionMainWindowClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        VisionMainWindowClass->setStatusBar(statusBar);

        retranslateUi(VisionMainWindowClass);

        QMetaObject::connectSlotsByName(VisionMainWindowClass);
    } // setupUi

    void retranslateUi(QMainWindow *VisionMainWindowClass)
    {
        VisionMainWindowClass->setWindowTitle(QApplication::translate("VisionMainWindowClass", "VisionMainWindow", nullptr));
        videoFrame->setText(QApplication::translate("VisionMainWindowClass", "TextLabel", nullptr));
        consolePlainText->setPlainText(QString());
        serialPortsLabel->setText(QApplication::translate("VisionMainWindowClass", "Available Serial Ports", nullptr));
        refreshSerialPortsPushButton->setText(QString());
        serialConnectPushButton->setText(QApplication::translate("VisionMainWindowClass", "Connect", nullptr));
        serialDisconnectPushButton->setText(QApplication::translate("VisionMainWindowClass", "Disconnect", nullptr));
        serialPortTest1Button->setText(QApplication::translate("VisionMainWindowClass", "Test 1", nullptr));
        serialPortTest2Button->setText(QApplication::translate("VisionMainWindowClass", "Test 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VisionMainWindowClass: public Ui_VisionMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISIONMAINWINDOW_H
