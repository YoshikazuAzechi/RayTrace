#pragma once

#include "hitable.h"

class Sphere : public Hitable
{
public:
    Sphere();
    Sphere(const Vector3& inCenter, const float inRadius);

    virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& outRecord) const override;
    
protected:
    Vector3 center;
    float radius;
};


