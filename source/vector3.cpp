#include "vector3.h"
#include <math.h>
#include <sstream>

const Vector3 Vector3::ZERO(0.0f, 0.0f, 0.0f);
const Vector3 Vector3::ONE(1.0f, 1.0f, 1.0f);
const Vector3 Vector3::FRONT(0.0f, 0.0f, 1.0f);
const Vector3 Vector3::UP(0.0f, 1.0f, 0.0f);
const Vector3 Vector3::RIGHT(1.0f, 0.0f, 0.0f);

Vector3::Vector3()
    : Vector3(Vector3::ZERO)
{

}

Vector3::Vector3(const Vector3& obj)
    : Vector3(obj.x, obj.y, obj.z)
{

}

Vector3::Vector3(float inX, float inY, float inZ)
    : x(inX)
    , y(inY)
    , z(inZ)
{

}

Vector3& Vector3::operator=(const Vector3& obj)
{
    x = obj.x;
    y = obj.y;
    z = obj.z;
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& v)
{
    x += x;
    y += y;
    z += z;
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& v)
{
    x -= x;
    y -= y;
    z -= z;
    return *this;
}

Vector3& Vector3::operator*=(const float t)
{
    x *= t;
    y *= t;
    z *= t;
    return *this;
}

Vector3& Vector3::operator/=(const float t)
{
    x /= t;
    y /= t;
    z /= t;
    return *this;
}

Vector3 Vector3::operator+(const Vector3& v) const
{
    return Vector3(x + v.x, y + v.y, z + v.z);
}

Vector3 Vector3::operator-(const Vector3& v) const
{
    return Vector3(x - v.x, y - v.y, z - v.z);    
}

Vector3 Vector3::operator/(float t) const
{
    return Vector3(x / t, y / t, z / t);
}

Vector3 Vector3::operator*(float t) const
{
    return Vector3(x * t, y * t, z * t);    
}

float Vector3::Dot(const Vector3& v) const
{
    return (x * v.x, y * v.y, z * v.z);
}

Vector3 Vector3::Cross(const Vector3& v) const
{
    Vector3 retVector;
    retVector.x = (y * v.z - z * v.y);
    retVector.y = (z * v.x - x * v.z);
    retVector.z = (x * v.y - y * v.x);
    return retVector;
}

float Vector3::Length() const
{
    return std::sqrtf(SqrLength());
}

float Vector3::SqrLength() const
{
    return x * x + y * y + z * z;    
}

void Vector3::Normalize()
{
    float perLength = 1.0f / Length();
    x = x / perLength;
    y = y / perLength;
    z = z / perLength;
}

Vector3 Vector3::Normalized() const
{
    Vector3 normalized(*this);
    normalized.Normalize();
    return normalized;
}

std::string Vector3::ToString() const
{
    std::stringstream ss;
    ss << "(" << x << "," << y << "," << z << ")";
    return ss.str();
}
