#include "RGBImageArray.h"
RGBImageArray::RGBImageArray() : RGBImage() {
}


RGBImageArray::RGBImageArray(const RGBImageArray &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new RGB[other.getWidth() * other.getHeight()];
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

RGBImageArray::RGBImageArray(const int width, const int height) : RGBImage(width, height) {
	pixelStorage = new RGB[width * height];
}

RGBImageArray::~RGBImageArray() {
	delete[] pixelStorage;
}

void RGBImageArray::set(const int width, const int height) {
	delete[] pixelStorage;

	pixelStorage = new RGB[width * height];

	RGBImage::set(width, height);
}

void RGBImageArray::set(const RGBImageArray &other) {
	delete[] pixelStorage;

	pixelStorage = new RGB[other.getWidth() * other.getHeight()];
	RGBImage::set(other.getWidth(), other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

void RGBImageArray::setPixel(int x, int y, RGB pixel) {
	int pixelIndex = (y * getWidth()) + x;
	pixelStorage[pixelIndex] = pixel;
}

void RGBImageArray::setPixel(int i, RGB pixel) {
	pixelStorage[i] = pixel;
}

RGB RGBImageArray::getPixel(int x, int y) const {
	int pixelIndex = (y * getWidth()) + x;
	return pixelStorage[pixelIndex];
}

RGB RGBImageArray::getPixel(int i) const {
	return pixelStorage[i];
}