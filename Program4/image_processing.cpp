#include "image_processing.h"


void translation(const QImage& src, QImage& dst, int tx, int ty)
{
    for(int y = 0; y < dst.height(); y++)
    {
        int src_y = y - ty;
        if(src_y >= 0 && src_y < src.height())
        {
            QRgb* pixel_dst = (QRgb*)dst.scanLine(y);
            QRgb* pixel_src = (QRgb*)src.scanLine(src_y);
            for(int x = 0; x < dst.width(); x++)
            {
                int src_x = x - tx;
                if(src_x >= 0 && src_x < src.width())
                {
                    pixel_dst[x] = pixel_src[src_x];
                }
                else
                {
                    pixel_dst[x] = qRgb(0, 0, 0);
                }
            }
        }
        else
        {
            QRgb* pixel_dst = (QRgb*)dst.scanLine(y);
            for(int x = 0; x < dst.width(); x++)
            {
                pixel_dst[x] = qRgb(0, 0, 0);
            }
        }
    }
}


void rotation(const QImage& src, QImage& dst, float alpha)
{
    float ca = cos(alpha);
    float sa = sin(alpha);
    int center_x = src.width() / 2;
    int center_y = src.height() / 2;

    QImage tempImage = src.copy();

    for (int y = 0; y < dst.height(); y++)
    {
        QRgb* rgb_dst = (QRgb*)dst.scanLine(y);
        for (int x = 0; x < dst.width(); x++)
        {
            float xp = (x - center_x) * ca + (y - center_y) * sa + center_x;
            float yp = -(x - center_x) * sa + (y - center_y) * ca + center_y;

            int src_x = std::round(xp);
            int src_y = std::round(yp);

            if (src_x >= 0 && src_x < src.width() && src_y >= 0 && src_y < src.height())
            {
                QRgb* rgb_src = (QRgb*)tempImage.scanLine(src_y);
                rgb_dst[x] = rgb_src[src_x];
            }
            else
            {
                rgb_dst[x] = qRgb(0, 0, 0);
            }
        }
    }
}

void scalingLinear(const QImage& src, QImage& dst, float scaleFactor)
{
    int srcWidth = src.width();
    int srcHeight = src.height();
    int dstWidth = dst.width();
    int dstHeight = dst.height();

    float dstCenterX = dstWidth / 2.0f;
    float dstCenterY = dstHeight / 2.0f;

    for (int y = 0; y < dstHeight; y++)
    {

        float dstY = y - dstCenterY;
        float srcY = (dstY / scaleFactor) + srcHeight / 2.0f;

        for (int x = 0; x < dstWidth; x++)
        {
            float dstX = x - dstCenterX;
            float srcX = (dstX / scaleFactor) + srcWidth / 2.0f;

            if (srcX >= 0 && srcX < srcWidth && srcY >= 0 && srcY < srcHeight)
            {
                int x0 = std::floor(srcX);
                int y0 = std::floor(srcY);
                int x1 = std::min(x0 + 1, srcWidth - 1);
                int y1 = std::min(y0 + 1, srcHeight - 1);

                float dx = srcX - x0;
                float dy = srcY - y0;

                QRgb pixel00 = src.pixel(x0, y0);
                QRgb pixel01 = src.pixel(x0, y1);
                QRgb pixel10 = src.pixel(x1, y0);
                QRgb pixel11 = src.pixel(x1, y1);

                int r = (1 - dx) * (1 - dy) * qRed(pixel00) + dx * (1 - dy) * qRed(pixel10) + (1 - dx) * dy * qRed(pixel01) + dx * dy * qRed(pixel11);
                int g = (1 - dx) * (1 - dy) * qGreen(pixel00) + dx * (1 - dy) * qGreen(pixel10) + (1 - dx) * dy * qGreen(pixel01) + dx * dy * qGreen(pixel11);
                int b = (1 - dx) * (1 - dy) * qBlue(pixel00) + dx * (1 - dy) * qBlue(pixel10) + (1 - dx) * dy * qBlue(pixel01) + dx * dy * qBlue(pixel11);

                dst.setPixel(x, y, qRgb(r, g, b));
            }
            else
            {
                dst.setPixel(x, y, qRgb(0, 0, 0));
            }
        }
    }
}
