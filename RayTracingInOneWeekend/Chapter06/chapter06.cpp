/**
 * Chapter03: Rays, a simple camera, and background
 */
#include <iostream>
#include <cstdint>
#include <random>

#include "camera.h"
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
    int nx = 400;
    int ny = 200;
    int components = 3;// RGB
    
    uint8_t* buffer = new uint8_t[nx * ny * components];
    Camera camera;
    
    World world;
    world.Add(new Sphere(Vector3(0.0f, 0.0f, 1.0f), 0.5f));
    world.Add(new Sphere(Vector3(0.0f, 200.5f, 1.0f), -200.0f));
    
    // random
    std::random_device randomDevice;
    std::mt19937 mt(randomDevice());
    std::uniform_real_distribution<float> random(0.0f, 1.0f);
    
    int ns = 10;
    
    // 各ピクセルに色を付ける
    for(int j = 0; j < ny; ++j)
    {
        for(int i = 0; i < nx; ++i)
        {
            Vector3 color = Vector3(0.0f, 0.0f, 0.0f); 
            for(int s = 0;s < ns;++s)
            // sampling
            {
                // UV値
                float u = (float(i) + random(mt)) / float(nx - 1);
                float v = (float(j) + random(mt)) / float(ny - 1);
                
                // Ray(camera)
                Ray ray = camera.GetRay(u, v);
                color += Color(ray, world);                
            }
            color /= float(ns);
            
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
    
    stbi_write_jpg("Chapter06/chapter06.jpg", nx, ny, components, buffer, 0);
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
