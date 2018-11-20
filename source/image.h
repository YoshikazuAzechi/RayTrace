#pragma once

class Color;

class Image
{
public:
    Image();
    ~Image();

    void CreateBuffer(int inWidth, int inHeight, const Color& fillColor);

    Color* operator()(int px, int py) const;

    Color* Read(int px, int py) const;
    bool Write(int px, int py, const Color& color);
    void Fill(const Color& fillColor);

    int GetWidth() const { return width; }
    int GetHeight() const { return height; }  


    bool IsValid() const
    {
        return (buffer != nullptr && width > 0 && height > 0);
    }

    void Dump() const;


private:
    int width;
    int height;

     Color* buffer;
};