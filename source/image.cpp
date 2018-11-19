#include "image.h"

#include <iostream>

using namespace std;

Image::Image(int inWidth, int inHeight)
    : width(inWidth)
    , height(inHeight)
{
    // buffer = new Color[width * height];
}

Image::~Image()
{
    // delete[] buffer;
    // buffer = nullptr;
}

void Image::Dump() const
{
    cout << "(" << width << ", " << height << ")" << endl;
}