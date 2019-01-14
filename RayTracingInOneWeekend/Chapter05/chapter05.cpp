/**
 * Chapter03: Rays, a simple camera, and background
 */
#include <iostream>
#include <cstdint>

#include "ray.h"
#include "world.h"
#include "sphere.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../stb_image_write.h"

Vector3 Color(const Ray& ray, World& world);
Vector3 SkyColor(const Ray& ray);

void main()
{
    // ピクセルサイズ（nx x ny）
    int nx = 200;
    int ny = 100;
    int components = 3;// RGB
    
    uint8_t* buffer = new uint8_t[nx * ny * components];
    
    // スクリーンサイズ
    Vector3 screenWidth(4.0f, 0.0f, 0.0f);
    Vector3 screenHeight(0.0f, 2.0f, 0.0f);
    Vector3 screenLowerLeft = -(screenWidth / 2.0f + screenHeight / 2.0f);
    screenLowerLeft.e[2] = 1.0f;
    // カメラ位置
    Vector3 cameraPosition(0.0f, 0.0f, 0.0f);
    
    World world;
    world.Add(new Sphere(Vector3(0.0f, 0.0f, 1.0f), 0.5f));
    world.Add(new Sphere(Vector3(0.0f, 100.5f, 1.0f), -100.0f));
        
    // 各ピクセルに色を付ける
    for(int j = 0; j < ny; ++j)
    {
        for(int i = 0; i < nx; ++i)
        {
            // UV値
            float u = float(i) / float(nx - 1);
            float v = float(j) / float(ny - 1);
            
            // Ray(camera)
            Vector3 cameraForward = screenLowerLeft + screenWidth * u + screenHeight * v;
            Ray ray(cameraPosition, cameraForward);
            
            // SkyColor
            Vector3 color = Color(ray, world);
            
            int ir = int(255.99f * color.R());
            int ig = int(255.99f * color.G());
            int ib = int(255.99f * color.B());
            
            // 色を出力
            int index = i * components + j * (nx * components);
            buffer[index] = ir;
            buffer[index+1] = ig;
            buffer[index+2] = ib;
        }
    }
    
    stbi_write_jpg("Chapter05/chapter05.jpg", nx, ny, components, buffer, 0);
    delete[] buffer;
}

Vector3 Color(const Ray& ray, World& world)
{
    HitRecord hitRecord;
    if(world.Hit(ray, 0.0f, 99999.0f, hitRecord))
    {
        return (hitRecord.normal + Vector3(1.0f, 1.0f, 1.0f)) * 0.5f;
    }
    return SkyColor(ray);
}

Vector3 SkyColor(const Ray& ray)
{
    float t = 0.5f * (1.0f + ray.direction.Normalized().Y());
    return Vector3(1.0f, 1.0f, 1.0f) * t + Vector3(0.5f, 0.7f, 1.0f) * (1.0f - t);
}
