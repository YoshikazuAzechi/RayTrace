#include "image.h"

#include <iostream>
#include "color.h"

using namespace std;

Image::Image()
    : width(0)
    , height(0)
    , buffer(nullptr)
{

}

Image::~Image()
{
    delete[] buffer;
    buffer = nullptr;
}

void Image::CreateBuffer(int inWidth, int inHeight, const Color& fillColor)
{
    if(IsValid())
    {
        delete[] buffer;
        buffer = nullptr;
    }
    width = inWidth;
    height = inHeight;
    buffer = new Color[width * height];

    Fill(fillColor);
}

Color* Image::operator()(int px, int py) const
{
    return Read(px, py);
}

Color* Image::Read(int px, int py) const
{
    if(!IsValid())
    {
        return nullptr;
    }
    int index = px + py * width;
    return &buffer[index];
}

bool Image::Write(int px, int py, const Color& color)
{
    if(!IsValid())
    {
        return false;
    }

    Color* pixel = Read(px, py);
    if(pixel == nullptr)
    {
        return false;
    }
    *pixel = color;

    return true;
}

void Image::Fill(const Color& fillColor)
{
    if(!IsValid())
    {
        return;
    }
    for(int px = 0;px < width;++px)
    {
        for(int py = 0;py < height;++py)
        {
            Write(px, py, fillColor);
        }
    }
}

void Image::Dump() const
{
    if(IsValid())
    {        
        cout << "(" << width << ", " << height << ")" << endl;
    }
    else
    {
        cout << "(Invalid)" << endl;
    }
        
}