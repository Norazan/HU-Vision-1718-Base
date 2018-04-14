#include "IntensityImageStudent.h"
#include <cmath>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage.resize(other.getWidth() * other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage.resize(width * height);
}

IntensityImageStudent::~IntensityImageStudent() {
	pixelStorage.clear();
	pixelStorage.shrink_to_fit();
}

void IntensityImageStudent::set(const int width, const int height) {
	pixelStorage.clear();
	pixelStorage.shrink_to_fit();

	pixelStorage.resize(width * height);

	IntensityImage::set(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	pixelStorage.clear();
	pixelStorage.shrink_to_fit();

	pixelStorage.resize(other.getHeight() * other.getWidth());

	IntensityImage::set(other.getWidth(), other.getHeight());

	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int pixelIndex = (y * getWidth()) + x;
	pixelStorage.at(pixelIndex) = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixelStorage.at(i) = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int pixelIndex = (y * getWidth()) + x;
	return pixelStorage.at(pixelIndex);
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixelStorage.at(i);
}