#include "RGBImageStudent.h"
#include <cmath>

RGBImageStudent::RGBImageStudent() : RGBImage() {
}

RGBImageStudent::RGBImageStudent(const RGBImageStudent &other) : RGBImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new RGB*[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new RGB[other.getWidth()];
	}
	for (int h = 0; h < getHeight(); ++h) {
		for (int w = 0; w < getWidth(); ++w) {
			pixelStorage[h][w] = other.getPixel(w, h);
		}
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
	//TODO: delete allocated objects
}

void RGBImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
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
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;

	pixelStorage = new RGB *[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new RGB[other.getWidth()];
	}
	RGBImage::set(other.getWidth(), other.getHeight());
	for (int h = 0; h < getHeight(); ++h) {
		for (int w = 0; w < getWidth(); ++w) {
			pixelStorage[h][w] = other.getPixel(w, h);
		}
	}
}

void RGBImageStudent::setPixel(int x, int y, RGB pixel) {
	pixelStorage[y][x] = pixel;
}

void RGBImageStudent::setPixel(int i, RGB pixel) {
	/*
	* TODO: set pixel i in "Row-Major Order"
	*
	*
	* Original 2d image (values):
	* 9 1 2
	* 4 3 5
	* 8 7 8
	*
	* 1d representation (i, value):
	* i		value
	* 0		9
	* 1		1
	* 2		2
	* 3		4
	* 4		3
	* 5		5
	* 6		8
	* 7		7
	* 8		8
	*/
	int pixelHeight = floor(i / getHeight());
	int pixelWidth = i % getHeight();
	pixelStorage[pixelHeight][pixelWidth] = pixel;
}

RGB RGBImageStudent::getPixel(int x, int y) const {
	return pixelStorage[y][x];
}

RGB RGBImageStudent::getPixel(int i) const {
	int pixelHeight = floor(i / getHeight());
	int pixelWidth = i % getHeight();
	return pixelStorage[pixelHeight][pixelWidth];
}