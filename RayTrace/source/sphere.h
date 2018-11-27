#pragma once

#include "object.h"

class Sphere : public Object
{
public:
    Sphere();
    Sphere(const Vector3& inPosition, float inRadius, const Color& inColor);

    bool Intersect(const Ray& ray) const override;

protected:
    float radius;
};