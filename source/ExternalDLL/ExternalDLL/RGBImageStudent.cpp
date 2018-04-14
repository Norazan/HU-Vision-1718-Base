#include "RGBImageStudent.h"
#include <cmath>

RGBImageStudent::RGBImageStudent() : RGBImage() {
}


RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new RGB*[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new RGB[other.getWidth()];
	}
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
		pixelStorage = new RGB*[height];
		for (int i = 0; i < height; ++i) {
			pixelStorage[i] = new RGB[width];
		}
}

RGBImageStudent::~RGBImageStudent() {
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;
}

void RGBImageStudent::set(const int width, const int height) {
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;
	pixelStorage = new RGB *[height];
	for (int i = 0; i < height; ++i) {
		pixelStorage[i] = new RGB[width];
	}
	RGBImage::set(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;

	pixelStorage = new RGB *[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new RGB[other.getWidth()];
	}
	RGBImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixelStorage[y][x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	int pixelHeight = (int)floor(i / getHeight());
	int pixelWidth = i % getHeight();
	pixelStorage[pixelHeight][pixelWidth] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixelStorage[y][x];
}

RGB RGBImageStudent::getPixel(int i) const {
	int pixelHeight = (int)floor(i / getHeight());
	int pixelWidth = i % getHeight();
	return pixelStorage[pixelHeight][pixelWidth];
}