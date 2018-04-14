/*
* Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
* Unauthorized copying of this file, via any medium is strictly prohibited
* Proprietary and confidential
*/

#pragma once
#include "IntensityImage.h"
#include <vector>
class IntensityImageStudent : public IntensityImage {
private:
	std::vector<Intensity> pixelStorage;
public:
	// Empty constructor
	IntensityImageStudent();

	// Clones another IntensityImageStudent. Sets the width, height and pixels equal to the other IntensityImageStudent.
	IntensityImageStudent(const IntensityImageStudent &other);

	// Creates a IntensityImageStudent with given width and height.
	IntensityImageStudent(const int width, const int height);

	// Clears pixelStorage allocated memory and shrinks it to fit the curren size (0).
	~IntensityImageStudent();


	// Set the width and height of the image shell to the given width and height.
	void set(const int width, const int height);

	// Set the width, height and pixels equal toanother IntensityImageStudent.
	void set(const IntensityImageStudent &other);


	// Set a specific pixel on coordinate x y equal to the given pixel.
	void setPixel(int x, int y, Intensity pixel);

	// Set a specific pixel in row-major order i equal tothe given pixel.
	void setPixel(int i, Intensity pixel);


	// Get a specific pixel on coordinate x y.
	Intensity getPixel(int x, int y) const;

	// Get a specific pixel in row-major order i. 
	Intensity getPixel(int i) const;
};