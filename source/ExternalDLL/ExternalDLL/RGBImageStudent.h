/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

/**
* RGBImageStudent
*
* This class serves as an image shell for RGB images. It allows other methodes to set pixels, retrieve pixels and scale the image.
*/

#pragma once
#include "RGBImage.h"

class RGBImageStudent : public RGBImage {
private:
	RGB ** pixelStorage;
public:
	// Empty constructor
	RGBImageStudent();

	// Clones another RGBImageStudent. Sets the width, height and pixels equal to the other RGBImageStudent.
	RGBImageStudent(const RGBImageStudent &other);

	// Creates a RGBImageStudent with given width and height.
	RGBImageStudent(const int width, const int height);

	// Destroys pixelStorage after deallocating it's memory.
	~RGBImageStudent();


	// Set the width and height of the image shell to the given width and height.
	void set(const int width, const int height);

	// Set the width, height and pixels equal toanother RGBImageStudent.
	void set(const RGBImageStudent &other);


	// Set a specific pixel on coordinate x y equal to the given pixel.
	void setPixel(int x, int y, RGB pixel);

	// Set a specific pixel in row-major order i equal tothe given pixel.
	void setPixel(int i, RGB pixel);


	// Get a specific pixel on coordinate x y.
	RGB getPixel(int x, int y) const;

	// Get a specific pixel in row-major order i. 
	RGB getPixel(int i) const;
};