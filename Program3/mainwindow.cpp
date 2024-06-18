#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "image_processing.h"
#include <QVector>
#include "QFileDialog"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(openImage(bool)));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(setMaskSize()));
    connect(ui->calculate, SIGNAL(clicked()), this, SLOT(applyChanges()));
    connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(applyMedianChanges()));
    maskInputs = QList<QList<int>>();
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

void MainWindow::setMaskSize()
{
    ui->tableWidget->clear();
    ui->tableWidget->setRowCount(0);
    ui->tableWidget->setColumnCount(0);

    int size = ui->spinBox->value();


    ui->tableWidget->setRowCount(size);
    ui->tableWidget->setColumnCount(size);

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            QTableWidgetItem *item = new QTableWidgetItem(QString::number(0));
            ui->tableWidget->setItem(i, j, item);
        }
    }
}


void MainWindow::applyChanges()
{
    if (!reference_image.isNull()) {
        int maskSize = ui->spinBox->value();
        QList<QList<int>> maskValues;
        for (int i = 0; i < maskSize; ++i) {
            QList<int> rowValues;
            for (int j = 0; j < maskSize; ++j) {
                QTableWidgetItem *item = ui->tableWidget->item(i, j);
                if (item) {
                    int value = item->text().toInt();
                    rowValues.append(value);
                } else {
                    rowValues.append(0);
                }
            }
            maskValues.append(rowValues);
        }


        // for (int i = 0; i < maskValues.size(); ++i) {
        //     for (int j = 0; j < maskValues[i].size(); ++j) {
        //         std::cout << maskValues[i][j] << " ";
        //     }
        //     std::cout << std::endl;
        // }


            QImage resultImage;
            applyCustomFilter(&reference_image, &resultImage, maskValues);
            transformed_image = resultImage;
            ui->label->setPixmap(QPixmap::fromImage(transformed_image));
        } else {
            qDebug() << "Frame layout is not a grid layout";
        }
    }


    void MainWindow::applyMedianChanges()
    {
        transformed_image = reference_image;
        int windowSize = ui->spinBox_2->value();
        applyMedianFilter(&reference_image, &transformed_image, windowSize);
        ui->label->setPixmap(QPixmap::fromImage(transformed_image));;
    }
