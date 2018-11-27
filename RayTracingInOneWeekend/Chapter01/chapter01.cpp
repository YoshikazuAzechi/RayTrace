/**
 * Chapter01: Output an image
 */
#include <iostream>
#include <cstdint>

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
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2f;
            
            // float -> int
            int ir = int(255.99f * r);
            int ig = int(255.99f * g);
            int ib = int(255.99f * b);
            // 色を出力
            int index = i * components + j * (nx * components);
            buffer[index] = ir;
            buffer[index+1] = ig;
            buffer[index+2] = ib;
        }
    }
    
    stbi_write_jpg("Chapter01/chapter01.jpg", nx, ny, components, buffer, 0);
    delete[] buffer;
}