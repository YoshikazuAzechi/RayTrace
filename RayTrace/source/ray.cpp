#include "ray.h"

Ray::Ray()
    : origin(Vector3::ZERO)
    , direction(Vector3::FRONT)
{

}

Ray::Ray(const Vector3& inOrigin, const Vector3& inDirection)
    : origin(inOrigin)
    , direction(inDirection)
{

}

Vector3 Ray::PointAt(float t) const
{
    return origin + direction * t;
}