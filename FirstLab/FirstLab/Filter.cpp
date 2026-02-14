#include "Filter.h"

template<typename T>
T clamp(T value, T max, T min) {
	if (value > max) return max;
	if (value < min) return min;
	return value;
}

QImage Filter::process(const QImage& img) const {
	QImage result(img);
	for (int x = 0; x < img.width(); x++) {
		for (int y = 0; y < img.height(); y++) {
			QColor color = calcNewPixelColor(img, x, y);
			result.setPixelColor(x, y, color);
		}
	}
	return result;
}

QColor InvertFilter::calcNewPixelColor(const QImage &img, int x, int y) const {
	QColor color = img.pixelColor(x, y);
	color.setRgb(255 - color.red(), 255 - color.green(), 255 - color.blue());
	return color;
}

QColor GrayScaleFilter::calcNewPixelColor(const QImage& img, int x, int y) const {
	QColor color = img.pixelColor(x, y);
	int intensity = static_cast<int>(0.299 * color.red() + 0.587 * color.green() + 0.114 * color.blue());
	color.setRgb(intensity, intensity, intensity);
	return color;
}
void PerfectReflector::maxColors(const QImage& img) {
	const int height = img.height();
	const int width = img.width();
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			QColor color = img.pixelColor(h, w);
			maxR = std::max(maxR, color.red());
			maxG = std::max(maxG, color.green());
			maxB = std::max(maxB, color.blue());
		}
	}
	if (maxR == 0) maxR = 1;
	if (maxG == 0) maxG = 1;
	if (maxB == 0) maxB = 1;
}

QColor PerfectReflector::calcNewPixelColor(const QImage& img, int x, int y) const {
	double kr = 255.0 / maxR;
	double kg = 255.0 / maxG;
	double kb = 255.0 / maxB;
	QColor color = img.pixelColor(x, y);
	int r = clamp(static_cast<int>(kr * color.red()), 255, 0);
	int g = clamp(static_cast<int>(kg * color.green()), 255, 0);
	int b = clamp(static_cast<int>(kb * color.blue()), 255, 0);
	color.setRgb(r, g, b);
	return color;
}