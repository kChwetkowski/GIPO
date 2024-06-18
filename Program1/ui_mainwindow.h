/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionExit;
    QWidget *centralwidget;
    QLabel *label;
    QSlider *horizontalSlider;
    QSlider *horizontalSlider_2;
    QSlider *horizontalSlider_3;
    QLabel *label_brightness;
    QLabel *label_contrast;
    QLabel *label_gamma;
    QLabel *label_gamma_display;
    QLabel *label_contrast_display;
    QLabel *label_brightness_display;
    QLabel *label_hist_red;
    QLabel *label_hist_green;
    QLabel *label_hist_blue;
    QLabel *label_hist_lum;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1101, 770);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName("actionExit");
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setMinimumSize(QSize(1101, 727));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(20, 160, 801, 521));
        label->setFrameShape(QFrame::NoFrame);
        label->setAlignment(Qt::AlignCenter);
        horizontalSlider = new QSlider(centralwidget);
        horizontalSlider->setObjectName("horizontalSlider");
        horizontalSlider->setGeometry(QRect(10, 10, 1071, 20));
        horizontalSlider->setMinimum(-99);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider_2 = new QSlider(centralwidget);
        horizontalSlider_2->setObjectName("horizontalSlider_2");
        horizontalSlider_2->setGeometry(QRect(10, 60, 1071, 20));
        horizontalSlider_2->setMinimum(-99);
        horizontalSlider_2->setOrientation(Qt::Horizontal);
        horizontalSlider_3 = new QSlider(centralwidget);
        horizontalSlider_3->setObjectName("horizontalSlider_3");
        horizontalSlider_3->setGeometry(QRect(10, 110, 1071, 20));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(horizontalSlider_3->sizePolicy().hasHeightForWidth());
        horizontalSlider_3->setSizePolicy(sizePolicy);
        horizontalSlider_3->setMinimum(0);
        horizontalSlider_3->setMaximum(150);
        horizontalSlider_3->setPageStep(1);
        horizontalSlider_3->setValue(10);
        horizontalSlider_3->setOrientation(Qt::Horizontal);
        label_brightness = new QLabel(centralwidget);
        label_brightness->setObjectName("label_brightness");
        label_brightness->setGeometry(QRect(500, 30, 61, 16));
        label_contrast = new QLabel(centralwidget);
        label_contrast->setObjectName("label_contrast");
        label_contrast->setGeometry(QRect(500, 90, 49, 16));
        label_gamma = new QLabel(centralwidget);
        label_gamma->setObjectName("label_gamma");
        label_gamma->setGeometry(QRect(500, 140, 49, 16));
        label_gamma_display = new QLabel(centralwidget);
        label_gamma_display->setObjectName("label_gamma_display");
        label_gamma_display->setGeometry(QRect(570, 140, 111, 16));
        label_contrast_display = new QLabel(centralwidget);
        label_contrast_display->setObjectName("label_contrast_display");
        label_contrast_display->setGeometry(QRect(570, 90, 121, 16));
        label_brightness_display = new QLabel(centralwidget);
        label_brightness_display->setObjectName("label_brightness_display");
        label_brightness_display->setGeometry(QRect(570, 30, 131, 16));
        label_hist_red = new QLabel(centralwidget);
        label_hist_red->setObjectName("label_hist_red");
        label_hist_red->setGeometry(QRect(840, 160, 256, 100));
        label_hist_red->setFrameShape(QFrame::NoFrame);
        label_hist_green = new QLabel(centralwidget);
        label_hist_green->setObjectName("label_hist_green");
        label_hist_green->setGeometry(QRect(840, 300, 256, 100));
        label_hist_green->setFrameShape(QFrame::NoFrame);
        label_hist_blue = new QLabel(centralwidget);
        label_hist_blue->setObjectName("label_hist_blue");
        label_hist_blue->setGeometry(QRect(840, 440, 256, 100));
        label_hist_blue->setFrameShape(QFrame::NoFrame);
        label_hist_lum = new QLabel(centralwidget);
        label_hist_lum->setObjectName("label_hist_lum");
        label_hist_lum->setGeometry(QRect(840, 580, 256, 100));
        label_hist_lum->setFrameShape(QFrame::NoFrame);
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1101, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionExit);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, &QAction::triggered, MainWindow, qOverload<>(&QMainWindow::close));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
        actionExit->setText(QCoreApplication::translate("MainWindow", "Exit", nullptr));
        label->setText(QString());
        label_brightness->setText(QCoreApplication::translate("MainWindow", "Brightness", nullptr));
        label_contrast->setText(QCoreApplication::translate("MainWindow", "Contrast", nullptr));
        label_gamma->setText(QCoreApplication::translate("MainWindow", "Gamma", nullptr));
        label_gamma_display->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        label_contrast_display->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_brightness_display->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        label_hist_red->setText(QString());
        label_hist_green->setText(QString());
        label_hist_blue->setText(QString());
        label_hist_lum->setText(QString());
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
