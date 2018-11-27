#pragma once

#include <vector>
#include "vector3.h"
#include "color.h"

class Object;
class Image;
class Vector3;

class World
{
public:
    World();
    ~World();
    
    void AddObject(Object* newObject);
    
    void Render(Image* srcImage, const Vector3& screenSize);
    
private:
    Color RenderPixel(int px, int py, const Vector3& uv);

private:
    Image* image;
    Vector3 screenSize;
    
    std::vector<Object*> objectList;
};