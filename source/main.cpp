#include <iostream>
#include <math.h>

#include "math.h"
#include "image.h"
#include "color.h"
#include "vector3.h"
#include "ppm.h"

using namespace std;

struct RenderData
{
    // Resolution
    int resX;
    int resY;
};

Color RenderPixel(const RenderData& renderData, const int& px, const int& py);

int main()
{
    RenderData renderData;
    renderData.resX = 100;
    renderData.resY = 100;

    Image image;
    image.CreateBuffer(renderData.resX, renderData.resY, Color::BLACK);

    Color color = Color::BLACK;
    for(int px = 0;px < renderData.resX;++px)
    {
        for(int py = 0;py < renderData.resY;++py)
        {
            image.Write(px, py, RenderPixel(renderData, px, py));
        }
    }
    
    bool succeeded = ppm::Save("image.ppm", image);

    if(succeeded)
    {
        cout << "Succeeded." << endl;
    }
    else
    {
        cout << "Failed." << endl;
    }

    getchar();
    return 0;
}

// 描画コア処理
Color RenderPixel(const RenderData& renderData, const int& px, const int& py)
{
    Color outColor = Color::BLACK;
    // Origin:lower_left
    Vector3 uv(
        static_cast<float>(px) / static_cast<float>(renderData.resX), 
        static_cast<float>(py) / static_cast<float>(renderData.resY),
        1.0f);
    // 中心を原点に
    Vector3 p = uv * 2.0f - Vector3::ONE;
    
    outColor.r = abs(uv.x);
    outColor.g = abs(uv.y);
    outColor.b = 0.0f;

    return outColor;
}
