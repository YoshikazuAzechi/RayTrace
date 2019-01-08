#include "vector3.h"
#include <math.h>

Vector3::Vector3()
    : Vector3(0.0f, 0.0f, 0.0f)
{
    
}

Vector3::Vector3(float e0, float e1, float e2)
{
    e[0] = e0;
    e[1] = e1;
    e[2] = e2;
}

Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(e[0] + v.e[0], e[1] + v.e[1], e[2] + v.e[2]);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(e[0] - v.e[0], e[1] - v.e[1], e[2] - v.e[2]);
}

Vector3 Vector3::operator*(const Vector3& v) const
{
    return Vector3(e[0] * v.e[0], e[1] * v.e[1], e[2] * v.e[2]);
}

Vector3 Vector3::operator/(const Vector3& v) const
{
    return Vector3(e[0] / v.e[0], e[1] / v.e[1], e[2] / v.e[2]);
}

Vector3 Vector3::operator*(float t) const
{
    return Vector3(e[0] * t, e[1] * t, e[2] * t);    
}

Vector3 Vector3::operator/(float t) const
{
    return Vector3(e[0] / t, e[1] / t, e[2] / t);
}

Vector3& Vector3::operator+=(const Vector3& v)
{
    for(int i = 0;i < 3;++i)
    {
        e[i] += v.e[i];
    }
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
    for(int i = 0;i < 3;++i)
    {
        e[i] -= v.e[i];
    }
    return *this;
}

Vector3& Vector3::operator*=(const Vector3& v)
{
    for(int i = 0;i < 3;++i)
    {
        e[i] *= v.e[i];
    }
    return *this;
}

Vector3& Vector3::operator/=(const Vector3& v)
{
    for(int i = 0;i < 3;++i)
    {
        e[i] /= v.e[i];
    }
    return *this;
}

Vector3& Vector3::operator*=(float t)
{
    for(int i = 0;i < 3;++i)
    {
        e[i] *= t;
    }
    return *this;
}

Vector3& Vector3::operator/=(float t)
{
    for(int i = 0;i < 3;++i)
    {
        e[i] /= t;
    }
    return *this;
}

float Vector3::Length() const
{
    return sqrtf(SqrLength());
}

float Vector3::SqrLength() const
{
    return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

Vector3 Vector3::Normalized() const
{
    return *this / Length();
}

float Vector3::Dot(const Vector3& v1, const Vector3& v2)
{
    return v1.e[0] * v2.e[0] + v1.e[1] * v2.e[1] + v1.e[2] * v2.e[2];
}

Vector3 Vector3::Cross(const Vector3& v1, const Vector3& v2)
{
    Vector3 result;
    result.e[0] = v1.e[1] * v2.e[2] - v1.e[2] * v2.e[1];
    result.e[1] = v1.e[0] * v2.e[2] - v1.e[2] * v2.e[0];
    result.e[2] = v1.e[0] * v2.e[1] - v1.e[1] * v2.e[0];
    return result;
}
