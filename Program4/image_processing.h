#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QImage>
#include <cmath>

void translation(const QImage& src, QImage& dst, int tx, int ty);
void rotation(const QImage& src, QImage& dst, float alpha);
void scalingLinear(const QImage& src, QImage& dst, float scaleFactor);

#endif // IMAGE_PROCESSING_H
