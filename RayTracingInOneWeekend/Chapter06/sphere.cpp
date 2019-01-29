#include "sphere.h"
#include <math.h>

Sphere::Sphere()
    : center(0.0f, 0.0f, 0.0f)
    , radius(1.0f)
{

}

Sphere::Sphere(const Vector3& inCenter, const float inRadius)
    : center(inCenter)
    , radius(inRadius)
{

}

bool Sphere::Hit(const Ray& ray, float t_min, float t_max, HitRecord& outRecord) const
{
    Vector3 toCenter = ray.origin - center;
    float a = Vector3::Dot(ray.direction, ray.direction);
    float b = 2.0f * Vector3::Dot(toCenter, ray.direction);
    float c = Vector3::Dot(toCenter, toCenter) - (radius * radius);

    // ヒット自体のチェック
    float d = b * b - 4 * a * c;
    if(d < 0.0f)
    {
        return false;
    }
    // 指定の範囲内でヒットしているかのチェック
    float t = (-b - sqrtf(d)) / (2.0f * a);
    if(t < t_min || t_max < t)
    {
        return false;
    }
    
    outRecord.t = t;
    outRecord.point = ray.PointAt(t);
    outRecord.normal = (outRecord.point - center) / radius;
    
    return true;
}
