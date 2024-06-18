#include "Image_processing.h"

void brightness(const QImage *src, QImage *dst, int dv)
{
    for(int y=0; y<src->height(); y++){

        QRgb* rgb_src = (QRgb*)src->scanLine(y);
        QRgb* rgb_dst = (QRgb*)dst->scanLine(y);

        for(int x=0; x<src->width(); x++){

           //QRgb rgb = src->pixel(x, y);


//            int r = ((rgb_src[x] >> 16) & 0xFF);
//            int g = ((rgb_src[x] >> 8) & 0xFF);
//            int b = ((rgb_src[x]) & 0xFF);
           int r = qRed(rgb_src[x]);
           int g = qGreen(rgb_src[x]);
           int b = qBlue(rgb_src[x]);


            r = std::clamp(r + dv, 0, 255);
            g = std::clamp(g + dv, 0, 255);
            b = std::clamp(b + dv, 0, 255);

            QRgb rgb;// = b + (g<<8) + (r<<16);
            rgb = qRgb(r,g,b);
            rgb_dst[x] = rgb;
           //dst->setPixel(x, y, rgb);

        }
    }
}

// void contrast(const QImage *src, QImage *dst, int dv)
// {
//     for(int y=0; y<src->height(); y++){

//         QRgb* rgb_src = (QRgb*)src->scanLine(y);
//         QRgb* rgb_dst = (QRgb*)dst->scanLine(y);

//         for(int x=0; x<src->width(); x++){

//             //QRgb rgb = src->pixel(x, y);


//             //            int r = ((rgb_src[x] >> 16) & 0xFF);
//             //            int g = ((rgb_src[x] >> 8) & 0xFF);
//             //            int b = ((rgb_src[x]) & 0xFF);
//             int r = qRed(rgb_src[x]);
//             int g = qGreen(rgb_src[x]);
//             int b = qBlue(rgb_src[x]);


//             //r = std::clamp(((r/2)+c)/(r/2)*x-c, 0, 255);
//             g = std::clamp(g + dv, 0, 255);
//             b = std::clamp(b + dv, 0, 255);

//             QRgb rgb;// = b + (g<<8) + (r<<16);
//             rgb = qRgb(r,g,b);
//             rgb_dst[x] = rgb;
//             //dst->setPixel(x, y, rgb);

//         }
//     }
// }
//2 dodatkowe slidery,gamma,kontrast
//gamma to float z przedziału 0<=R<=1
//float tf = r/255.0f (dzielenie float)
//(int)tf*255;

void contrast(const QImage *src, QImage *dst, int contrast)
{
    double factor = (259.0 * (contrast + 255.0)) / (255.0 * (259.0 - contrast));

    for(int y = 0; y < src->height(); y++) {
        QRgb* rgb_src = (QRgb*)src->scanLine(y);
        QRgb* rgb_dst = (QRgb*)dst->scanLine(y);

        for(int x = 0; x < src->width(); x++) {
            int r = qRed(rgb_src[x]);
            int g = qGreen(rgb_src[x]);
            int b = qBlue(rgb_src[x]);

            r = std::clamp(static_cast<int>(factor * (r - 128) + 128), 0, 255);
            g = std::clamp(static_cast<int>(factor * (g - 128) + 128), 0, 255);
            b = std::clamp(static_cast<int>(factor * (b - 128) + 128), 0, 255);

            rgb_dst[x] = qRgb(r, g, b);
        }
    }
}

void gamma(const QImage *src, QImage *dst, int gammaValue)
{
    // Przeskalowanie z zakresu 0-150 na zakres 0.0-15.0
    float scaledGamma = static_cast<float>(gammaValue) / 10.0;

    for(int y = 0; y < src->height(); y++) {
        QRgb* rgb_src = (QRgb*)src->scanLine(y);
        QRgb* rgb_dst = (QRgb*)dst->scanLine(y);

        for(int x = 0; x < src->width(); x++) {
            int r = qRed(rgb_src[x]);
            int g = qGreen(rgb_src[x]);
            int b = qBlue(rgb_src[x]);

            r = std::clamp(static_cast<int>(255.0 * pow(r / 255.0, scaledGamma)), 0, 255);
            g = std::clamp(static_cast<int>(255.0 * pow(g / 255.0, scaledGamma)), 0, 255);
            b = std::clamp(static_cast<int>(255.0 * pow(b / 255.0, scaledGamma)), 0, 255);

            rgb_dst[x] = qRgb(r, g, b);
        }
    }
}


///r,g,b,luminancja (4 histogramy)
/// int nist[256]={0}
/// hist[v]++;
///

void histRed(const QImage *image, QImage *hist)
{
    int h[256] = {}; // Tablica do przechowywania ilości pikseli dla każdej wartości czerwieni

    // Obliczanie histogramu
    for (int y = 0; y < image->height(); ++y) {
        const QRgb *scanline = reinterpret_cast<const QRgb *>(image->constScanLine(y));
        for (int x = 0; x < image->width(); ++x) {
            int red = qRed(scanline[x]);
            ++h[red]; // Zwiększ licznik dla wartości czerwieni w histogramie
        }
    }

    // Normalizacja histogramu (skalowanie wartości do zakresu 0-100)
    int max_hist_value = *std::max_element(h, h + 256);
    float scale = static_cast<float>(hist->height()) / max_hist_value;

    hist->fill(Qt::white); // Wypełnij obraz histogramu kolorem białym

    // Rysowanie histogramu za pomocą QPainter
    QPainter painter(hist);
    painter.setPen(Qt::red); // Ustawienie koloru rysowania na czarny

    for (int i = 0; i < 256; ++i) {
        int v = scale * h[i]; // Skaluj wartość histogramu
        painter.drawLine(i, hist->height(), i, hist->height() - v); // Narysuj pionową linię dla wartości i
    }
}

void histGreen(const QImage *image, QImage *hist)
{
    int h[256] = {}; // Tablica do przechowywania ilości pikseli dla każdej wartości zielonej

    // Obliczanie histogramu
    for (int y = 0; y < image->height(); ++y) {
        const QRgb *scanline = reinterpret_cast<const QRgb *>(image->constScanLine(y));
        for (int x = 0; x < image->width(); ++x) {
            int green = qGreen(scanline[x]);
            ++h[green]; // Zwiększ licznik dla wartości zielonej w histogramie
        }
    }

    // Normalizacja histogramu (skalowanie wartości do zakresu 0-100)
    int max_hist_value = *std::max_element(h, h + 256);
    float scale = static_cast<float>(hist->height()) / max_hist_value;

    hist->fill(Qt::white); // Wypełnij obraz histogramu kolorem białym

    // Rysowanie histogramu za pomocą QPainter
    QPainter painter(hist);
    painter.setPen(Qt::green); // Ustawienie koloru rysowania na czarny

    for (int i = 0; i < 256; ++i) {
        int v = scale * h[i]; // Skaluj wartość histogramu
        painter.drawLine(i, hist->height(), i, hist->height() - v); // Narysuj pionową linię dla wartości i
    }
}

void histBlue(const QImage *image, QImage *hist)
{
    int h[256] = {}; // Tablica do przechowywania ilości pikseli dla każdej wartości niebieskiej

    // Obliczanie histogramu
    for (int y = 0; y < image->height(); ++y) {
        const QRgb *scanline = reinterpret_cast<const QRgb *>(image->constScanLine(y));
        for (int x = 0; x < image->width(); ++x) {
            int blue = qBlue(scanline[x]);
            ++h[blue]; // Zwiększ licznik dla wartości niebieskiej w histogramie
        }
    }

    // Normalizacja histogramu (skalowanie wartości do zakresu 0-100)
    int max_hist_value = *std::max_element(h, h + 256);
    float scale = static_cast<float>(hist->height()) / max_hist_value;

    hist->fill(Qt::white); // Wypełnij obraz histogramu kolorem białym

    // Rysowanie histogramu za pomocą QPainter
    QPainter painter(hist);
    painter.setPen(Qt::blue); // Ustawienie koloru rysowania na czarny

    for (int i = 0; i < 256; ++i) {
        int v = scale * h[i]; // Skaluj wartość histogramu
        painter.drawLine(i, hist->height(), i, hist->height() - v); // Narysuj pionową linię dla wartości i
    }
}

void histLum(const QImage *image, QImage *hist)
{
    int h[256] = {}; // Tablica do przechowywania ilości pikseli dla każdej wartości luminancji

    // Obliczanie histogramu
    for (int y = 0; y < image->height(); ++y) {
        const QRgb *scanline = reinterpret_cast<const QRgb *>(image->constScanLine(y));
        for (int x = 0; x < image->width(); ++x) {
            int luminance = qGray(scanline[x]); // Oblicz luminancję piksela
            ++h[luminance]; // Zwiększ licznik dla wartości luminancji w histogramie
        }
    }

    // Normalizacja histogramu (skalowanie wartości do zakresu 0-100)
    int max_hist_value = *std::max_element(h, h + 256);
    float scale = static_cast<float>(hist->height()) / max_hist_value;

    hist->fill(Qt::white); // Wypełnij obraz histogramu kolorem białym

    // Rysowanie histogramu za pomocą QPainter
    QPainter painter(hist);
    painter.setPen(Qt::gray); // Ustawienie koloru rysowania na czarny

    for (int i = 0; i < 256; ++i) {
        int v = scale * h[i]; // Skaluj wartość histogramu
        painter.drawLine(i, hist->height(), i, hist->height() - v); // Narysuj pionową linię dla wartości i
    }
}
