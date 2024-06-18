#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QVector>

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
    void setMaskSize();
    void applyChanges();
    void applyMedianChanges();

private:
    Ui::MainWindow *ui;
    QVector<QVector<int>> maskInputs;
};
#endif // MAINWINDOW_H
