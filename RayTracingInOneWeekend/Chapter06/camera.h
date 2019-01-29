#pragma once

#include "ray.h"

class Camera
{
public:
    Camera()
        : position(0.0f, 0.0f, -1.0f)
        , horizontal(0.0f, 2.0f, 0.0f)
        , vertical(4.0f, 0.0f, 0.0f)
    {
        
    }
    
    Ray GetRay(float u, float v) const
    { 
        Vector3 dir = Vector3(vertical.X() * u, horizontal.Y() * v, 0.0f);
        dir.e[2] = 1.0f;
        Ray ray(position, GetLowerLeft()  + dir);
        return ray;
    }
    
    Vector3 GetLowerLeft() const 
    {
        return -(horizontal / 2.0f + vertical / 2.0f);
    }
    
public:
    Vector3 position;
    Vector3 horizontal;
    Vector3 vertical;
};
