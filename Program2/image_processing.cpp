#include "image_processing.h"

QTextStream& qStdOut()
{
    static QTextStream ts( stdout );
    return ts;
}

struct RGB {
    int r, g, b;
};

struct HSL {
    float h, s, l;
};

struct LAB {
    float l, a, b;
};

struct XYZ {
    float x, y, z;
};

HSL rgb2hsl(int r, int g, int b) {
    HSL result;

    float fr = (float)r / 256.0f;
    float fg = (float)g / 256.0f;
    float fb = (float)b / 256.0f;

    float maxVal = std::max({fr, fg, fb});
    float minVal = std::min({fr, fg, fb});

    result.h = result.s = result.l = (maxVal + minVal) / 2.0f;

    if (maxVal == minVal) {
        result.h = result.s = 0.0f;
    } else {
        float d = maxVal - minVal;
        result.s = (result.l > 0.5f) ? d / (2.0f - maxVal - minVal) : d / (maxVal + minVal);

        if (maxVal == fr) {
            result.h = 60*((fg - fb) / d) + (fg < fb ? 360.0f : 0.0f);
        } else if (maxVal == fg) {
            result.h = 60*((fb - fr) / d) + 120.0f;
        } else if (maxVal == fb) {
            result.h = 60*((fr - fg) / d) + 240.0f;
        }

        result.h /= 360.0f;
    }
    //qStdOut() << result.h << result.s << result.l;
    return result;

}

float hue2rgb(float p, float q, float t) {
    if (t < 0.0f)
        t += 1.0f;
    if (t > 1.0f)
        t -= 1.0f;
    if (t < (1.0f / 6.0f))
        return p + (q - p) * 6.0f * t;
    if ((t < (1.0f / 2.0f)) && (t >= (1.0f / 6.0f)))
        return q;
    if (t > ((2.0f / 3.0f)) && (t < (2.0f / 3.0f) ))
        return p + (q - p) * (2.0 / 3.0 - t) * 6.0f;

    return p;
}

RGB hsl2rgb(float h, float s, float l) {
    RGB result;

    if (0.0 == s) {
        result.r = result.g = result.b = l * 256; // *255 ????
    } else {
        float q = l < 0.5f ? l * (1.0f + s) : l + s - (l * s);
        float p = 2.0f * l - q;
        result.r = hue2rgb(p, q, h + (1.0f / 3.0f)) * 256;
        result.g = hue2rgb(p, q, h) * 256;
        result.b = hue2rgb(p, q, h - (1.0f / 3.0f)) * 256;
    }

    return result;
}


void applyHSLManipulation(const QImage *src, QImage *dst, int slider_h, int slider_s, int slider_l)
{
    float scaledH = static_cast<float>(slider_h) / 360.0f;
    float scaledS = static_cast<float>(slider_s) / 100.0f;
    float scaledL = static_cast<float>(slider_l) / 100.0f;

    for(int y = 0; y < dst->height(); y++)
    {
        QRgb* pixel_dst = (QRgb*)dst->scanLine(y);
        QRgb* pixel_src = (QRgb*)src->scanLine(y);
        for(int x = 0; x < dst->width(); x++)
        {
            RGB rgb;
            HSL hsl;

            rgb.r = qRed(pixel_src[x]);
            rgb.g = qGreen(pixel_src[x]);
            rgb.b = qBlue(pixel_src[x]);

            hsl = rgb2hsl(rgb.r, rgb.g, rgb.b);

            hsl.h += scaledH;
            hsl.s += scaledS;
            hsl.l += scaledL;


            hsl.h = std::clamp(hsl.h, 0.0f, 0.99f);
            hsl.s = std::clamp(hsl.s, 0.0f, 0.99f);
            hsl.l = std::clamp(hsl.l, 0.0f, 0.99f);

            rgb = hsl2rgb(hsl.h, hsl.s, hsl.l);
            pixel_dst[x] = qRgb(rgb.r, rgb.g, rgb.b);
        }
    }
}

XYZ rgb2xyz(int r, int g, int b) {

    float var_R = (float)r / 256.0f;
    float var_G = (float)g / 256.0f;
    float var_B = (float)b / 256.0f;

    const float gamma = 2.2f;
    var_R = pow(var_R, gamma);
    var_G = pow(var_G, gamma);
    var_B = pow(var_B, gamma);

    float X = var_R * 0.41242f + var_G * 0.35759f + var_B * 0.18046f;
    float Y = var_R * 0.21266f + var_G * 0.71517f + var_B * 0.07218f;
    float Z = var_R * 0.01933f + var_G * 0.11919f + var_B * 0.95044f;
    return {X, Y, Z};

}

const float epsilon = 0.008856f;
const float kappa = 903.3f;

LAB xyz2lab(float x, float y, float z) {
    float xr = x / 0.9505f;
    float yr = y / 1.0000f;
    float zr = z / 1.0891f;

    float fx = (xr > epsilon) ? pow(xr, 1.0f / 3.0f) : (kappa * xr + 16.0f) / 116.0f;
    float fy = (yr > epsilon) ? pow(yr, 1.0f / 3.0f) : (kappa * yr + 16.0f) / 116.0f;
    float fz = (zr > epsilon) ? pow(zr, 1.0f / 3.0f) : (kappa * zr + 16.0f) / 116.0f;

    float L = 116.0f * fy - 16.0f;
    float a = 500.0f * (fx - fy);
    float b = 200.0f * (fy - fz);

    return {L, a, b};
}




XYZ lab2xyz(float L, float a, float b) {
    float yr = (L > kappa * epsilon) ? pow(((L + 16.0f) / 116.0f), 3.0f) : L / kappa;
    float fy = (yr > epsilon) ? (L+16.0f)/116.0f : (kappa*yr + 16.0f)/116.0f;

    float fx = a / 500.0f + fy;
    float fz = fy - (b / 200.0f);

    float fx3 = pow(fx, 3);
    float fz3 = pow(fz, 3);


    float xr = (fx3 > epsilon) ? fx3 : (116.0f * fx - 16.0f) / kappa;
    float zr = (fz3 > epsilon) ? fz3 : (116.0f * fz - 16.0f) / kappa;

    float X = xr * 0.9505f;
    float Y = yr * 1.0000f;
    float Z = zr * 1.0891f;

    return {X, Y, Z};
}

RGB xyz2rgb(float x, float y, float z) {
    float gamma = 2.2f;
    float var_X = x;
    float var_Y = y;
    float var_Z = z;


    float var_R = var_X *  3.24071f + var_Y * (-1.53726f) + var_Z * (-0.49857f);
    float var_G = var_X * (-0.9689f) + var_Y *  (1.87599f) + var_Z *  0.04155f;
    float var_B = var_X *  0.05563f + var_Y * (-0.20399f) + var_Z *  1.05707f;



    var_R = pow(var_R, 1.0f / gamma);
    var_G = pow(var_G, 1.0f / gamma);
    var_B = pow(var_B, 1.0f / gamma);

    return {std::clamp(var_R * 256.0f, 0.0f, 255.0f), std::clamp(var_G * 256.0f, 0.0f, 255.0f), std::clamp(var_B * 256.0f, 0.0f, 255.0f)};
}

void applyLABManipulation(const QImage *src, QImage *dst, int slider_l, int slider_a, int slider_b) {
    for (int y = 0; y < dst->height(); y++) {
        QRgb* pixel_dst = (QRgb*)dst->scanLine(y);
        QRgb* pixel_src = (QRgb*)src->scanLine(y);
        for (int x = 0; x < dst->width(); x++) {
            RGB rgb;
            LAB lab;

            XYZ xyz = rgb2xyz(qRed(pixel_src[x]), qGreen(pixel_src[x]), qBlue(pixel_src[x]));
            lab = xyz2lab(xyz.x, xyz.y, xyz.z);

            lab.l += slider_l;
            lab.a += slider_a;
            lab.b += slider_b;

            lab.l = std::clamp(lab.l, 0.0f, 100.0f);
            lab.a = std::clamp(lab.a, -128.0f, 127.0f);
            lab.b = std::clamp(lab.b, -128.0f, 127.0f);

            xyz = lab2xyz(lab.l, lab.a, lab.b);
            rgb = xyz2rgb(xyz.x, xyz.y, xyz.z);

            pixel_dst[x] = qRgb(rgb.r, rgb.g, rgb.b);
        }
    }
}
