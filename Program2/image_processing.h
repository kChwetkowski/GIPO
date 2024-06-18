#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QImage>
#include<QDebug>
#include <algorithm>



void applyHSLManipulation(const QImage *src, QImage *dst, int slider_h, int slider_s, int slider_l);
void applyLABManipulation(const QImage *src, QImage *dst, int slider_l2, int slider_a, int slider_b);
void l(const QImage* src, QImage* dst, int dv);
void a(const QImage* src, QImage* dst, int dv);
void b(const QImage* src, QImage* dst, int dv);


#endif // IMAGE_PROCESSING_H
