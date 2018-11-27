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

float Vector3::Dot(const Vector3& v1, const Vector3& v2)
{
    return (v1.x * v2.x + v1.y * v2.y +  v1.z * v2.z);
}

Vector3 Vector3::Cross(const Vector3& v1, const Vector3& v2)
{
    Vector3 retVector;
    retVector.x = (v1.y * v2.z - v1.z * v2.y);
    retVector.y = (v1.z * v2.x - v1.x * v2.z);
    retVector.z = (v1.x * v2.y - v1.y * v2.x);
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
