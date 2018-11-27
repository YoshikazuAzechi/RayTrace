#pragma once

#include "vector3.h"

class Ray
{
public:
    Ray();
    Ray(const Vector3& inOrigin, const Vector3& inDirection);

    const Vector3& GetOrigin() const { return origin; }
    const Vector3& GetDirection() const { return direction; }
    Vector3 PointAt(float t) const;

public:
    Vector3 origin;
    Vector3 direction;
};