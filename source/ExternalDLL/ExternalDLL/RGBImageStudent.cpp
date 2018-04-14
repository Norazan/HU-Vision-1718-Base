#include "RGBImageStudent.h"
#include <cmath>

RGBImageStudent::RGBImageStudent() : RGBImage() {

}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	//pixelStorage.reserve(other.getWidth() * other.getHeight());
	pixelStorage.resize(other.getWidth() * other.getHeight());
	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

RGBImageStudent::RGBImageStudent(const int width, const int height) : RGBImage(width, height) {
	pixelStorage.resize(width * height);
}

RGBImageStudent::~RGBImageStudent() {
	pixelStorage.clear();
	pixelStorage.shrink_to_fit();
}

void RGBImageStudent::set(const int width, const int height) {
	pixelStorage.clear();
	pixelStorage.shrink_to_fit();

	pixelStorage.resize(width * height);

	RGBImage::set(width, height);
}

void RGBImageStudent::set(const RGBImageStudent &other) {
	pixelStorage.clear();
	pixelStorage.shrink_to_fit();

	pixelStorage.resize(other.getHeight() * other.getWidth());

	RGBImage::set(other.getWidth(), other.getHeight());

	for (int i = 0; i < (getHeight() * getWidth()); ++i) {
		setPixel(i, other.getPixel(i));
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	int pixelIndex = (y * getWidth()) + x;
	pixelStorage.at(pixelIndex) = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	pixelStorage.at(i) = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	int pixelIndex = (y * getWidth()) + x;
	return pixelStorage.at(pixelIndex);
}

RGB RGBImageStudent::getPixel(int i) const {
	return pixelStorage.at(i);
}