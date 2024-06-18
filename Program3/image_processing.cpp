#include "image_processing.h"
#include <QColor>
#include <QDebug>
#include <QImage>
#include <QVector>
#include <algorithm>

void applyCustomFilter(const QImage *src, QImage *dst, const QList<QList<int>> &mask)
{


    int maskRows = mask.size();
    int maskCols = mask[0].size();
    int halfRows = maskRows / 2;
    int halfCols = maskCols / 2;

    *dst = QImage(src->size(), src->format());


    for (int y = 0; y < src->height(); ++y) {
        for (int x = 0; x < src->width(); ++x) {
            double sumR = 0.0, sumG = 0.0, sumB = 0.0;

            for (int i = -halfRows; i <= halfRows; ++i) {
                for (int j = -halfCols; j <= halfCols; ++j) {
                    int pixelX = qBound(0, x + j, src->width() - 1);
                    int pixelY = qBound(0, y + i, src->height() - 1);
                    QColor pixelColor(src->pixel(pixelX, pixelY));
                    int maskValue = mask[i + halfRows][j + halfCols];

                    sumR += pixelColor.red() * maskValue;
                    sumG += pixelColor.green() * maskValue;
                    sumB += pixelColor.blue() * maskValue;
                }
            }

            int newRed = qBound(0, static_cast<int>(sumR), 255);
            int newGreen = qBound(0, static_cast<int>(sumG), 255);
            int newBlue = qBound(0, static_cast<int>(sumB), 255);

            dst->setPixelColor(x, y, QColor(newRed, newGreen, newBlue));
        }
    }
}


int findMedianChannel(int channel1, int channel2) {
    return (channel1 + channel2) / 2;
}


QRgb findMedian(const QVector<QRgb> &values) {
    QVector<QRgb> sortedValues = values;
    std::sort(sortedValues.begin(), sortedValues.end());
    int size = sortedValues.size();
    if (size % 2 == 0) {
        QRgb color1 = sortedValues[size / 2 - 1];
        QRgb color2 = sortedValues[size / 2];
        return qRgb(findMedianChannel(qRed(color1), qRed(color2)),
                    findMedianChannel(qGreen(color1), qGreen(color2)),
                    findMedianChannel(qBlue(color1), qBlue(color2)));
    } else {
        return sortedValues[size / 2];
    }
}

void applyMedianFilter(const QImage *src, QImage *dst, int windowSize) {
    int width = src->width();
    int height = src->height();
    int margin = windowSize / 2;

    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            QVector<QRgb> windowValues;

            for (int j = -margin; j <= margin; ++j) {
                for (int i = -margin; i <= margin; ++i) {
                    int pixelX = qBound(0, x + i, width - 1);
                    int pixelY = qBound(0, y + j, height - 1);
                    QRgb pixelColor = src->pixel(pixelX, pixelY);
                    windowValues.append(pixelColor);
                }
            }

            QRgb medianColor = findMedian(windowValues);
            dst->setPixelColor(x, y, QColor(medianColor));
        }
    }
}
