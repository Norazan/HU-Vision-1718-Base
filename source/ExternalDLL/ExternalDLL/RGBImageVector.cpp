#include "RGBImageVector.h"
#include "RGBImageVector.h"
#include <cmath>

RGBImageVector::RGBImageVector() : RGBImage() {

}

RGBImageVector::RGBImageVector(const RGBImageVector &other) : RGBImage(other.getWidth(), other.getHeight()) {
	//pixelStorage.reserve(other.getWidth() * other.getHeight());
	pixelStorage.resize(other.getWidth() * other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

RGBImageVector::RGBImageVector(const int width, const int height) : RGBImage(width, height) {
	pixelStorage.resize(width * height);
}

RGBImageVector::~RGBImageVector() {
}

void RGBImageVector::set(const int width, const int height) {
	pixelStorage.resize(width * height);

	RGBImage::set(width, height);
}

void RGBImageVector::set(const RGBImageVector &other) {
	pixelStorage.resize(other.getHeight() * other.getWidth());
	pixelStorage.shrink_to_fit();
	RGBImage::set(other.getWidth(), other.getHeight());
	pixelStorage = other.pixelStorage;
}

void RGBImageVector::setPixel(int x, int y, RGB pixel) {
	int pixelIndex = (y * getWidth()) + x;
	pixelStorage.at(pixelIndex) = pixel;
}

void RGBImageVector::setPixel(int i, RGB pixel) {
	pixelStorage.at(i) = pixel;
}

RGB RGBImageVector::getPixel(int x, int y) const {
	int pixelIndex = (y * getWidth()) + x;
	return pixelStorage.at(pixelIndex);
}

RGB RGBImageVector::getPixel(int i) const {
	return pixelStorage.at(i);
}