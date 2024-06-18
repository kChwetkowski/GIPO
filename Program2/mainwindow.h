#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QLabel>
#include <QSlider>
#include <QObject>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE


class MainWindow : public QMainWindow
{
    Q_OBJECT
    QImage reference_image, transformed_image;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void openImage(bool);
    void changeHue(int);
    void changeSaturation(int);
    void changeLightness(int);
    void transformImage();

    void changeL(int);
    void changeA(int);
    void changeB(int);


private:
    Ui::MainWindow *ui;
    int hueValue;
    int saturationValue;
    int lightnessValue;
    int aValue;
    int bValue;
    int lValue;
};
#endif // MAINWINDOW_H
