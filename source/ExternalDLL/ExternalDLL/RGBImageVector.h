#pragma once
#include "RGBImage.h"
#include <vector>

class RGBImageVector : public RGBImage {
public:
	RGBImageVector();
	RGBImageVector(const RGBImageVector& other);
	RGBImageVector(int, int);
	~RGBImageVector();
	void set(int, int) override;
	void set(const RGBImageVector& other);
	void setPixel(int x, int y, RGB pixel) override;
	void setPixel(int i, RGB pixel) override;
	RGB getPixel(int x, int y) const override;
	RGB getPixel(int i) const override;
private:
	std::vector<RGB> pixelStorage;
};
