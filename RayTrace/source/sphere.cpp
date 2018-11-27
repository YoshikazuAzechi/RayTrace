#include "sphere.h"
#include "ray.h"

Sphere::Sphere()
    : Object()
    , radius(1.0f)
{
}

Sphere::Sphere(const Vector3 &inPosition, float inRadius, const Color& inColor)
    : Object(inPosition, inColor)
    , radius(inRadius)
{
}

bool Sphere::Intersect(const Ray &ray) const
{
    Vector3 o2c = ray.origin - position;
    float a = Vector3::Dot(ray.direction, ray.direction);
    float b = 2.0f * Vector3::Dot(o2c, ray.direction);
    float c = Vector3::Dot(o2c, o2c) - radius * radius;
    
    float discriminant = b * b - 4.0f * a * c;
    return discriminant > 0.0f;
}