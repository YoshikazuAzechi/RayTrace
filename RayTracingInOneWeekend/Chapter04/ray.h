#pragma once

#include "vector3.h"

class Ray
{
public:
    Ray(){}
    Ray(const Vector3& inOrigin, const Vector3& inDirection)
        : origin(inOrigin)
        , direction(inDirection)
    {}
    
    Vector3 PointAt(float t) const { return origin + (direction * t); }
    
public:
    Vector3 origin;
    Vector3 direction;
};