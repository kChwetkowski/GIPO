#include "mainwindow.h"
#include <QMouseEvent>
#include <QKeyEvent>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QPainter>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), line_started(false), circle_started(false)
{
}

MainWindow::~MainWindow()
{
}



void MainWindow::drawLine(int x1, int y1, int x2, int y2) {
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);
    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;
    int err = dx - dy;
    int x = x1;
    int y = y1;

    while (true)
    {
        setPixel(x, y);
        if (x == x2 && y == y2)
            break;
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            y += sy;
        }
    }
}

void MainWindow::drawCircle(int x1, int y1, int x2, int y2) {
    int radius = qMax(abs(x2 - x1), abs(y2 - y1));
    int d = 5 - 4 * radius;
    int x = 0;
    int y = radius;
    int deltaA = (-2 * radius + 5) * 4;
    int deltaB = 3 * 4;

    while (x <= y) {
        pixels(x1, y1, x, y);
        if (d > 0) {
            d += deltaA;
            y -= 1;
            x += 1;
            deltaA += 4 * 4;
            deltaB += 2 * 4;
        } else {
            d += deltaB;
            x += 1;
            deltaA += 2 * 4;
            deltaB += 2 * 4;
        }
    }
}

void MainWindow::pixels(int x0, int y0, int x, int y) {
    setPixel(x0 - x, y0 - y);
    setPixel(x0 - x, y0 + y);
    setPixel(x0 + x, y0 - y);
    setPixel(x0 + x, y0 + y);
    setPixel(x0 - y, y0 - x);
    setPixel(x0 - y, y0 + x);
    setPixel(x0 + y, y0 - x);
    setPixel(x0 + y, y0 + x);
}

void MainWindow::setPixel(int x, int y) {
    if (image.rect().contains(x, y)) {
        image.setPixelColor(x, y, Qt::white);
    }
}



void MainWindow::mousePressEvent(QMouseEvent *event)
{
    int x = event->position().x();
    int y = event->position().y();

    if (event->button() == Qt::LeftButton)
    {
        if (line_started) {
            drawLine(startPoint.x(), startPoint.y(), x, y);
            line_started = false;
        } else {
            startPoint = event->pos();
            line_started = true;
        }
    }
    if (event->button() == Qt::RightButton && event->modifiers() == Qt::ControlModifier)
    {
        if (circle_started) {
            drawCircle(startPoint.x(), startPoint.y(), x, y);
            circle_started = false;
        }
        else {
            startPoint = event->pos();
            circle_started = true;
        }
    }


    update();
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_P){}
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.drawImage(0,0, image);
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    image = QImage(event->size(), QImage::Format_RGB32);
    image.fill(0);
}


/*
 * pierwsze klikniece x1y1 druge x2y2 etc (n/2 odcinkow)
 * pierwsze środek drugie promień
 */

