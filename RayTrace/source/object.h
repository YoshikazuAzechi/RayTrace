#pragma once

#include "vector3.h"
#include "color.h"

class Ray;

class Object
{
protected:
    Object();
    Object(const Vector3& inPosition, const Color& inColor);

public:
    virtual ~Object() {}
    
    virtual bool Intersect(const Ray& ray) const = 0;
    const Vector3 &GetPosition() const { return position; }

    const Color& GetColor() const { return color; }
protected:
    Vector3 position;
    Color color;
};