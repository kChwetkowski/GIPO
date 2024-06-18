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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QImage reference_image;
    QImage transformed_image;
    QLabel *lblValue = new QLabel();
    QSlider* sldValue = new QSlider(Qt::Horizontal);

public slots:
    void openImage();
    void changeBrightness(int);
    void changeContrast(int);
    void changeGamma(int);
    void drawHist();


};
#endif // MAINWINDOW_H
