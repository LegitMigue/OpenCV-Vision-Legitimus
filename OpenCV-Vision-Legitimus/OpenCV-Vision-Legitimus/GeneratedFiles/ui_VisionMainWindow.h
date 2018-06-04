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
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_VisionMainWindowClass
{
public:
    QWidget *centralWidget;
    QLabel *videoFrame;
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
    } // retranslateUi

};

namespace Ui {
    class VisionMainWindowClass: public Ui_VisionMainWindowClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VISIONMAINWINDOW_H
