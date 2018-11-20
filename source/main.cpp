#include <iostream>

#include "image.h"
#include "color.h"
#include "ppm.h"

using namespace std;

int main()
{
    const int WIDTH = 100;
    const int HEIGHT = 100;

    Image image;
    image.CreateBuffer(WIDTH, HEIGHT, Color::BLACK);

    Color color = Color::BLACK;
    for(int px = 0;px < WIDTH;++px)
    {
        color.g = (float)px / (float)(WIDTH - 1);
        for(int py = 0;py < HEIGHT;++py)
        {
            color.r = 1.0f - ((float)py / (float)(HEIGHT - 1));
            image.Write(px, py, color);
        }
    }
    
    ppm::Save("image.ppm", image);

    getchar();
    return 0;
}