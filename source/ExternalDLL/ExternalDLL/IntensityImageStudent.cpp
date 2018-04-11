#include "IntensityImageStudent.h"
#include <cmath>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new Intensity*[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new Intensity[other.getWidth()];
	}
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

IntensityImageStudent::IntensityImageStudent(const int width, const int height) : IntensityImage(width, height) {
	pixelStorage = new Intensity*[height];
	for (int i = 0; i < height; ++i) {
		pixelStorage[i] = new Intensity[width];
	}
}

IntensityImageStudent::~IntensityImageStudent() {
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;
}

void IntensityImageStudent::set(const int width, const int height) {
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;

	pixelStorage = new Intensity *[height];
	for (int i = 0; i < height; ++i) {
		pixelStorage[i] = new Intensity[width];
	}
	IntensityImage::set(width, height);
}

void IntensityImageStudent::set(const IntensityImageStudent &other) {
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;

	pixelStorage = new Intensity *[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new Intensity[other.getWidth()];
	}
	IntensityImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelStorage[y][x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
	int pixelHeight = (int)floor(i / getHeight());
	int pixelWidth = i % getHeight();
	pixelStorage[pixelHeight][pixelWidth] = pixel;
}

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelStorage[y][x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int pixelHeight = (int)floor(i / getHeight());
	int pixelWidth = i % getHeight();
	return pixelStorage[pixelHeight][pixelWidth];
}