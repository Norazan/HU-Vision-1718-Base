#include "IntensityImageStudent.h"
#include <cmath>

IntensityImageStudent::IntensityImageStudent() : IntensityImage() {
	
}

IntensityImageStudent::IntensityImageStudent(const IntensityImageStudent &other) : IntensityImage(other.getWidth(), other.getHeight()) {
	pixelStorage = new Intensity*[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new Intensity[other.getWidth()];
	}
	for (int h = 0; h < getHeight(); ++h) {
		for (int w = 0; w < getWidth(); ++w) {
			pixelStorage[h][w] = other.getPixel(w, h);
		}
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
	//TODO: delete allocated objects
}

void IntensityImageStudent::set(const int width, const int height) {
	//TODO: resize or create a new pixel storage (Don't forget to delete the old storage)
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
	//TODO: resize or create a new pixel storage and copy the object (Don't forget to delete the old storage)
	for (int i = 0; i < getHeight(); ++i) {
		delete[] pixelStorage[i];
	}
	delete[] pixelStorage;

	pixelStorage = new Intensity *[other.getHeight()];
	for (int i = 0; i < other.getHeight(); ++i) {
		pixelStorage[i] = new Intensity[other.getWidth()];
	}
	IntensityImage::set(other.getWidth(), other.getHeight());
	for (int h = 0; h < getHeight(); ++h) {
		for (int w = 0; w < getWidth(); ++w) {
			pixelStorage[h][w] = other.getPixel(w, h);
		}
	}
}

void IntensityImageStudent::setPixel(int x, int y, Intensity pixel) {
	pixelStorage[y][x] = pixel;
}

void IntensityImageStudent::setPixel(int i, Intensity pixel) {
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

Intensity IntensityImageStudent::getPixel(int x, int y) const {
	return pixelStorage[y][x];
}

Intensity IntensityImageStudent::getPixel(int i) const {
	int pixelHeight = floor(i / getHeight());
	int pixelWidth = i % getHeight();
	return pixelStorage[pixelHeight][pixelWidth];
}