/**
 * Chapter03: Rays, a simple camera, and background
 */
#include <iostream>
#include <cstdint>

#include "vector3.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb_image_write.h"

void main()
{
    // ピクセルサイズ（nx x ny）
    int nx = 200;
    int ny = 100;
    int components = 3;// RGB
    
    uint8_t* buffer = new uint8_t[nx * ny * components];
    
    // 各ピクセルに色を付ける
    for(int j = ny - 1;j >= 0;--j)
    {
        for(int i = 0;i < nx;++i)
        {
        }
    }
    
    //stbi_write_jpg("Chapter03/chapter03.jpg", nx, ny, components, buffer, 0);
    delete[] buffer;
}