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