#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QImage>
#include<QPainter>

void brightness(const QImage* src, QImage* dst, int dv);
void contrast(const QImage* src, QImage* dst, int dv);
void gamma(const QImage* src, QImage* dst, int dv);
void histRed(const QImage* image, QImage* hist);
void histGreen(const QImage* image, QImage* hist);
void histBlue(const QImage* image, QImage* hist);
void histLum(const QImage* image, QImage* hist);

#endif // IMAGE_PROCESSING_H
