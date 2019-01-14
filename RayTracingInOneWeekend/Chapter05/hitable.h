#pragma once

#include "ray.h"

struct HitRecord
{
    float t;
    Vector3 point;
    Vector3 normal;
};

class Hitable
{
public:
    virtual bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& outRecord) const = 0;
};
