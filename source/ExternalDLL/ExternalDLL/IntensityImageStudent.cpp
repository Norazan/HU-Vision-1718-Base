#include "IntensityImageStudent.h"
#include <cmath>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new Intensity[other.getWidth() * other.getHeight()];
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage = new Intensity[width * height];
}

IntensityImageStudent::~IntensityImageStudent() {
	delete[] pixelStorage;
}

void IntensityImageStudent::set(const int width, const int height) {
	delete[] pixelStorage;

	pixelStorage = new Intensity[width * height];

	IntensityImage::set(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	delete[] pixelStorage;

	pixelStorage = new Intensity[other.getWidth() * other.getHeight()];
	IntensityImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	int pixelIndex = (y * getWidth()) + x;
	pixelStorage[pixelIndex] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	pixelStorage[i] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	int pixelIndex = (y * getWidth()) + x;
	return pixelStorage[pixelIndex];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	return pixelStorage[i];
}