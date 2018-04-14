#pragma once
#include "RGBImage.h"

class RGBImageArray : public RGBImage{
public:
	RGBImageArray();
	RGBImageArray(const RGBImageArray& other);
	RGBImageArray(int, int);
	~RGBImageArray();
	void set(int, int) override;
	void set(const RGBImageArray& other);
	void setPixel(int x, int y, RGB pixel) override;
	void setPixel(int i, RGB pixel) override;
	RGB getPixel(int x, int y) const override;
	RGB getPixel(int i) const override;
private:
	RGB * pixelStorage;
};
