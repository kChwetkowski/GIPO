#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Image_processing.h"
#include <QFileDialog>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // ui->horizontalSlider->setStyleSheet("QSlider::groove:horizontal { border: 1px solid #999999; height: 8px; background: #FFFFFF; margin: 2px 0; } QSlider::sub-page:horizontal { background: qlineargradient(x1: 0, y1: 0, x2: 0, y2: 1, stop: 0 #B1B1B1, stop: 1 #c4c4c4); background: qlineargradient(x1: 0, y1: 0, x2: 1, y2: 0, stop: 0 #B1B1B1, stop: 1 #c4c4c4); border: 1px solid #999999; height: 8px; margin: 2px 0; } QSlider::add-page:horizontal { background: #575757; border: 1px solid #999999; height: 8px; margin: 2px 0; } QSlider::handle:horizontal { background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #B5B5B5, stop:1 #8f8f8f); border: 1px solid #5c5c5c; width: 18px; margin: -2px 0; border-radius: 3px; }");
//     ui->horizontalSlider->setTickPosition(QSlider::TicksBothSides); // Ustawienie pozycji znaczników
// ui->horizontalSlider->setTickInterval(10);

    connect(ui->actionOpen, SIGNAL(triggered()),
            this,           SLOT(openImage()));

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),
            this,                 SLOT(changeBrightness(int)));

    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)),
            this,                 SLOT(changeContrast(int)));

    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)),
            this,                 SLOT(changeGamma(int)));

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);



}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawHist()
{
    QImage histRedImage(256, 100, QImage::Format_ARGB32);
    QImage histGreenImage(256, 100, QImage::Format_ARGB32);
    QImage histBlueImage(256, 100, QImage::Format_ARGB32);
    QImage histLumiImage(256, 100, QImage::Format_ARGB32);

    histRed(&reference_image, &histRedImage);
    histGreen(&reference_image, &histGreenImage);
    histBlue(&reference_image, &histBlueImage);
    histLum(&reference_image, &histLumiImage);

    ui->label_hist_red->setPixmap(QPixmap::fromImage(histRedImage));
    ui->label_hist_green->setPixmap(QPixmap::fromImage(histGreenImage));
    ui->label_hist_blue->setPixmap(QPixmap::fromImage(histBlueImage));
    ui->label_hist_lum->setPixmap(QPixmap::fromImage(histLumiImage));
}


void MainWindow::openImage()
{
    int w = ui->label->width ();
    int h = ui->label->height ();
    QString filename = QFileDialog::getOpenFileName();
    if (!filename.isEmpty()){
        reference_image.load(filename);
        transformed_image = reference_image;
        QPixmap pix(QPixmap::fromImage(transformed_image));
        ui->label->setPixmap(pix);
        ui->label->setPixmap (pix.scaled (w,h,Qt::KeepAspectRatio));
        drawHist();

    }
}

void MainWindow::changeBrightness(int v)
{
    int w = ui->label->width ();
    int h = ui->label->height ();
    brightness(&reference_image, &transformed_image, v);
    QPixmap pix(QPixmap::fromImage(transformed_image));
    ui->label->setPixmap(pix);
    ui->label->setPixmap (pix.scaled (w,h,Qt::KeepAspectRatio));
    ui->label_brightness_display->setText(QString(" %1").arg(v));
}

void MainWindow::changeContrast(int v)
{
    int w = ui->label->width ();
    int h = ui->label->height ();
    contrast(&reference_image, &transformed_image, v);
    QPixmap pix(QPixmap::fromImage(transformed_image));
    ui->label->setPixmap(pix);
    ui->label->setPixmap (pix.scaled (w,h,Qt::KeepAspectRatio));
    ui->label_contrast_display->setText(QString(" %1").arg(v));
}

void MainWindow::changeGamma(int v)
{
    int w = ui->label->width ();
    int h = ui->label->height ();
    gamma(&reference_image, &transformed_image, v);
    QPixmap pix(QPixmap::fromImage(transformed_image));
    ui->label->setPixmap(pix);
    ui->label->setPixmap (pix.scaled (w,h,Qt::KeepAspectRatio));
    //float floatValue = 0.1;
    //int sliderValue = static_cast<int>(floatValue * 100);
    ui->label_gamma_display->setText(QString(" %1").arg(static_cast<float>(v) / 10.0, 0, 'f', 2));

}












//    int h[256] = {};
//int max_hist_value = *std::max_element(h, h+256);
//for(int i=0; i<image->height()*image->width();i++)
//    h[qRed(rgb[i])]++;

//QImage histogram_red(256, 100, QImage::Format_ARGB32);
//float scale = max_hist_value/histogram_red.height();

//for(int i=0; i<256; i++)
//{
//    int v = scale*h[i];
//    for(int y=0; y < v; y++)
//    {
//        histogram_red.setPixel(i, histogram_red.height() - y, qRgb(255,0,0));
//    }
//}
