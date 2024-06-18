#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"
#include "image_processing.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(openImage(bool)));
    connect(ui->slider_h, SIGNAL(valueChanged(int)), this, SLOT(changeHue(int)));
    connect(ui->slider_s, SIGNAL(valueChanged(int)), this, SLOT(changeSaturation(int)));
    connect(ui->slider_l, SIGNAL(valueChanged(int)), this, SLOT(changeLightness(int)));

    connect(ui->slider_l2, SIGNAL(valueChanged(int)), this, SLOT(changeL(int)));
    connect(ui->slider_a, SIGNAL(valueChanged(int)), this, SLOT(changeA(int)));
    connect(ui->slider_b, SIGNAL(valueChanged(int)), this, SLOT(changeB(int)));

    hueValue = ui->slider_h->value();
    saturationValue = ui->slider_s->value();
    lightnessValue = ui->slider_l->value();
    lValue = ui->slider_l2->value();
    aValue = ui->slider_a->value();
    bValue = ui->slider_b->value();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage(bool) {
    int w = ui->label->width();
    int h = ui->label->height();
    QString filename = QFileDialog::getOpenFileName();
    if (!filename.isEmpty()){
        reference_image.load(filename);
        transformed_image = reference_image;
        QPixmap pix(QPixmap::fromImage(transformed_image));
        ui->label->setPixmap(pix);
        ui->label->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
        transformImage();
    }
}


void MainWindow::changeL(int v) {
    lValue = v;
    ui->l_Value->setText(QString(" %1").arg(v));
    transformImage();
}

void MainWindow::changeA(int v) {
    aValue = v;
    ui->a_Value->setText(QString(" %1").arg(v));
    transformImage();
}

void MainWindow::changeB(int v) {
    bValue = v;
    ui->b_Value->setText(QString(" %1").arg(v));
    transformImage();
}

void MainWindow::changeHue(int v) {
    hueValue = v;
    ui->hue_value->setText(QString(" %1").arg(v));
    transformImage();
}

void MainWindow::changeSaturation(int v) {
    saturationValue = v;
    ui->saturation_value->setText(QString(" %1").arg(v));
    transformImage();
}

void MainWindow::changeLightness(int v) {
    lightnessValue = v;
    ui->lightness_value->setText(QString(" %1").arg(v));
    transformImage();
}


void MainWindow::transformImage() {
    if(ui->radio_HSL->isChecked()){
        applyHSLManipulation(&reference_image, &transformed_image, hueValue, saturationValue, lightnessValue);
    }
    if(ui->radio_LAB->isChecked()){
        applyLABManipulation(&reference_image, &transformed_image, lValue, aValue, bValue);

    }

    int w = ui->label->width();
    int h = ui->label->height();
    QPixmap pix(QPixmap::fromImage(transformed_image));
    ui->label->setPixmap(pix.scaled(w, h, Qt::KeepAspectRatio));
}
