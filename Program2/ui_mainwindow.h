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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QWidget *centralwidget;
    QSlider *slider_s;
    QSlider *slider_l;
    QSlider *slider_a;
    QSlider *slider_l2;
    QSlider *slider_b;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label;
    QSlider *slider_h;
    QLabel *hue_value;
    QLabel *saturation_value;
    QLabel *lightness_value;
    QLabel *b_Value;
    QLabel *l_Value;
    QLabel *a_Value;
    QRadioButton *radio_HSL;
    QRadioButton *radio_LAB;
    QMenuBar *menubar;
    QMenu *menuFile;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName("actionOpen");
        actionOpen->setCheckable(false);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(1);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy1);
        slider_s = new QSlider(centralwidget);
        slider_s->setObjectName("slider_s");
        slider_s->setGeometry(QRect(80, 40, 300, 16));
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(slider_s->sizePolicy().hasHeightForWidth());
        slider_s->setSizePolicy(sizePolicy2);
        slider_s->setMinimum(-100);
        slider_s->setMaximum(100);
        slider_s->setOrientation(Qt::Horizontal);
        slider_l = new QSlider(centralwidget);
        slider_l->setObjectName("slider_l");
        slider_l->setGeometry(QRect(80, 70, 300, 16));
        sizePolicy2.setHeightForWidth(slider_l->sizePolicy().hasHeightForWidth());
        slider_l->setSizePolicy(sizePolicy2);
        slider_l->setMinimum(-100);
        slider_l->setMaximum(100);
        slider_l->setOrientation(Qt::Horizontal);
        slider_a = new QSlider(centralwidget);
        slider_a->setObjectName("slider_a");
        slider_a->setGeometry(QRect(460, 40, 300, 16));
        sizePolicy2.setHeightForWidth(slider_a->sizePolicy().hasHeightForWidth());
        slider_a->setSizePolicy(sizePolicy2);
        slider_a->setMinimum(-128);
        slider_a->setMaximum(127);
        slider_a->setOrientation(Qt::Horizontal);
        slider_l2 = new QSlider(centralwidget);
        slider_l2->setObjectName("slider_l2");
        slider_l2->setGeometry(QRect(460, 10, 300, 16));
        sizePolicy2.setHeightForWidth(slider_l2->sizePolicy().hasHeightForWidth());
        slider_l2->setSizePolicy(sizePolicy2);
        slider_l2->setMinimum(-100);
        slider_l2->setMaximum(100);
        slider_l2->setOrientation(Qt::Horizontal);
        slider_b = new QSlider(centralwidget);
        slider_b->setObjectName("slider_b");
        slider_b->setGeometry(QRect(460, 70, 300, 16));
        sizePolicy2.setHeightForWidth(slider_b->sizePolicy().hasHeightForWidth());
        slider_b->setSizePolicy(sizePolicy2);
        slider_b->setMinimum(-128);
        slider_b->setMaximum(127);
        slider_b->setOrientation(Qt::Horizontal);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(10, 10, 53, 14));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 40, 61, 20));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 70, 53, 14));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(440, 10, 53, 14));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(440, 40, 53, 14));
        label_7 = new QLabel(centralwidget);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(440, 70, 53, 14));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 120, 791, 431));
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setAlignment(Qt::AlignCenter);
        slider_h = new QSlider(centralwidget);
        slider_h->setObjectName("slider_h");
        slider_h->setGeometry(QRect(80, 10, 300, 16));
        sizePolicy2.setHeightForWidth(slider_h->sizePolicy().hasHeightForWidth());
        slider_h->setSizePolicy(sizePolicy2);
        slider_h->setMinimum(0);
        slider_h->setMaximum(360);
        slider_h->setOrientation(Qt::Horizontal);
        hue_value = new QLabel(centralwidget);
        hue_value->setObjectName("hue_value");
        hue_value->setGeometry(QRect(390, 10, 49, 16));
        saturation_value = new QLabel(centralwidget);
        saturation_value->setObjectName("saturation_value");
        saturation_value->setGeometry(QRect(390, 40, 49, 16));
        lightness_value = new QLabel(centralwidget);
        lightness_value->setObjectName("lightness_value");
        lightness_value->setGeometry(QRect(390, 70, 49, 16));
        b_Value = new QLabel(centralwidget);
        b_Value->setObjectName("b_Value");
        b_Value->setGeometry(QRect(770, 70, 49, 16));
        l_Value = new QLabel(centralwidget);
        l_Value->setObjectName("l_Value");
        l_Value->setGeometry(QRect(770, 10, 49, 16));
        a_Value = new QLabel(centralwidget);
        a_Value->setObjectName("a_Value");
        a_Value->setGeometry(QRect(770, 40, 49, 16));
        radio_HSL = new QRadioButton(centralwidget);
        radio_HSL->setObjectName("radio_HSL");
        radio_HSL->setGeometry(QRect(180, 90, 89, 20));
        radio_LAB = new QRadioButton(centralwidget);
        radio_LAB->setObjectName("radio_LAB");
        radio_LAB->setGeometry(QRect(560, 100, 89, 20));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        menuFile = new QMenu(menubar);
        menuFile->setObjectName("menuFile");
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        menubar->addAction(menuFile->menuAction());
        menuFile->addAction(actionOpen);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        actionOpen->setText(QCoreApplication::translate("MainWindow", "Open", nullptr));
#if QT_CONFIG(shortcut)
        actionOpen->setShortcut(QCoreApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_CONFIG(shortcut)
        label_2->setText(QCoreApplication::translate("MainWindow", "Hue", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "Saturation", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Lightness", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "L", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "a", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "b", nullptr));
        label->setText(QString());
        hue_value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        saturation_value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        lightness_value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        b_Value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        l_Value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        a_Value->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        radio_HSL->setText(QCoreApplication::translate("MainWindow", "HSL", nullptr));
        radio_LAB->setText(QCoreApplication::translate("MainWindow", "LAB", nullptr));
        menuFile->setTitle(QCoreApplication::translate("MainWindow", "File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
