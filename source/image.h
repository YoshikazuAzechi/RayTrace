#pragma once

class Image
{
public:
    Image(int inWidth = 100, int inHeight = 100);
    ~Image();

    // Color* Read(int px, int py) const;
    // bool Write(const Color& color, int px, int py);

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }  

    void Dump() const;

    

private:
    int width;
    int height;

    // Color* buffer;
};