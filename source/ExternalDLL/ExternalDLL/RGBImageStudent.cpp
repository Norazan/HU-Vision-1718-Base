#include "RGBImageStudent.h"
#include <cmath>

RGBImageStudent::RGBImageStudent() : RGBImage() {
}


RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new RGB[other.getWidth() * other.getHeight()];
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixelStorage = new RGB[width * height];
}

RGBImageStudent::~RGBImageStudent() {
	delete[] pixelStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	delete[] pixelStorage;

	pixelStorage = new RGB[width * height];

	RGBImage::set(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	delete[] pixelStorage;

	pixelStorage = new RGB[other.getWidth() * other.getHeight()];
	RGBImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int pixelIndex = (y * getWidth()) + x;
	pixelStorage[pixelIndex] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixelStorage[i] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int pixelIndex = (y * getWidth()) + x;
	return pixelStorage[pixelIndex];
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixelStorage[i];
}