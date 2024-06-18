#ifndef IMAGE_PROCESSING_H
#define IMAGE_PROCESSING_H

#include <QImage>
#include <QList>
#include <QImage>


void applyCustomFilter(const QImage* src, QImage* dst, const QList<QList<int>> &mask);
void applyMedianFilter(const QImage* src, QImage* dst, int windowSize);
int findMedian(const QVector<int> &values);

#endif // IMAGE_PROCESSING_H
