#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QImage image;

public:
     MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



    void setPixel(int x, int y);
    void drawLine(int x1, int y1, int x2, int y2);
    void drawCircle(int x1, int y1, int x2, int y2);
    void pixels(int x0, int y0, int x, int y);

protected:
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*) {};
    void mouseReleaseEvent(QMouseEvent*) {};
    void mouseDoubeClick(QMouseEvent*) {};

    void keyPressEvent(QKeyEvent*);
    void keyReleaseEvent(QKeyEvent*) {};

    void paintEvent(QPaintEvent*);
    void resizeEvent(QResizeEvent*);
private:
    QPoint startPoint;
    QPoint endPoint;
    bool line_started;
    bool circle_started;
};
#endif // MAINWINDOW_H
