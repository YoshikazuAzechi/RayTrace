#include "world.h"

#include "object.h"
#include "image.h"
#include "color.h"
#include "ray.h"

World::World()
    : image(nullptr)
    , screenSize(Vector3::ZERO)
{
    objectList.clear();
}

World::~World()
{
    for(Object* object : objectList)
    {
        delete object;
    }
    objectList.clear();
    image = nullptr;
}

void World::AddObject(Object* newObject)
{
    if(!newObject)
    {
        return;
    }
    
    objectList.push_back(newObject);
}

void World::Render(Image* srcImage, const Vector3& inScreenSize)
{
    image = srcImage;
    if(!image)
    {
        return;
    }

    screenSize = inScreenSize;
    
    const int resX = image->GetWidth();
    const int resY = image->GetHeight();
    
    Color color = Color::BLACK;
    Vector3 uv = Vector3::ZERO;
    for (int px = 0; px < resX; ++px)
    {
        uv.x = static_cast<float>(px) / static_cast<float>(resX);
        for (int py = 0; py < resY; ++py)
        {
            uv.y = static_cast<float>(py) / static_cast<float>(resY);
        
            color = RenderPixel(px, py, uv);
            image->Write(px, py, color);
        }
    }    
}

Color World::RenderPixel(int px, int py, const Vector3& uv)
{
    Vector3 p = (uv * 2.0f - Vector3::ONE);
    p.x *= (screenSize.x / 2.0f);
    p.y *= (screenSize.y / 2.0f);
    p.z = 1.0f;

    Ray ray = Ray(Vector3::ZERO, p);
    
    for(Object* object : objectList)
    {
        if(object->Intersect(ray))
        {
            return object->GetColor();
        }
    }
    return Color::GRAY;
}