#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QFileDialog"

#include "image_processing.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(openImage(bool)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(sliderChanged()));
    connect(ui->horizontalSlider_2, SIGNAL(valueChanged(int)), this, SLOT(sliderChanged()));
    connect(ui->horizontalSlider_3, SIGNAL(valueChanged(int)), this, SLOT(rotationSliderChanged()));
    connect(ui->horizontalSlider_4, SIGNAL(valueChanged(int)), this, SLOT(scaleSliderChanged()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage(bool)
{
    QString name = QFileDialog::getOpenFileName();
    if (!name.isEmpty())
    {
        reference_image.load(name);
        transformed_image = reference_image;
        ui->label->setPixmap(QPixmap::fromImage(transformed_image));
    }
}

void MainWindow::sliderChanged()
{
    int tx = ui->horizontalSlider->value();
    int ty = ui->horizontalSlider_2->value();
    ui->trl_label->setText(QString(" %1").arg(tx));
    ui->tud_label->setText(QString(" %1").arg(ty));

    if (!reference_image.isNull()) {
        transformed_image = reference_image;
        translation(reference_image, transformed_image, tx, ty);
        ui->label->setPixmap(QPixmap::fromImage(transformed_image));
    }
}

void MainWindow::rotationSliderChanged()
{
    int rotationAngle = ui->horizontalSlider_3->value();
    ui->r_label->setText(QString(" %1").arg(rotationAngle));

    if (!reference_image.isNull()) {
        transformed_image = reference_image;
        rotation(transformed_image, transformed_image, rotationAngle * M_PI / 180.0f);
        ui->label->setPixmap(QPixmap::fromImage(transformed_image));
    }
}

void MainWindow::scaleSliderChanged()
{
    float scaleFactor = ui->horizontalSlider_4->value() / 100.0f;
    ui->s_label->setText(QString(" %1").arg(scaleFactor));

    if (!reference_image.isNull()) {
        transformed_image = reference_image;
        scalingLinear(reference_image, transformed_image, scaleFactor);
        ui->label->setPixmap(QPixmap::fromImage(transformed_image));
    }
}
