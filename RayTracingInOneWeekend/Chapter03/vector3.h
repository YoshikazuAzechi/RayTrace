#pragma once

class Vector3
{
public:
    Vector3();
    Vector3(float e0, float e1, float e2);
    
    float X() const { return e[0]; }
    float Y() const { return e[1]; }
    float Z() const { return e[2]; }
    float R() const { return e[0]; }
    float G() const { return e[1]; }
    float B() const { return e[2]; }
    
    const Vector3& operator+() const { return *this; }
    Vector3 operator-() const { return Vector3(-e[0], -e[1], -e[2]); }
    float operator[](int idx) const { return e[idx]; }
    float& operator[](int idx) { return e[idx]; }

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator*(const Vector3& v) const;
    Vector3 operator/(const Vector3& v) const;
    Vector3 operator*(float t) const;
    Vector3 operator/(float t) const;
    
    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);
    Vector3& operator*=(const Vector3& v);
    Vector3& operator/=(const Vector3& v);
    Vector3& operator*=(float t);
    Vector3& operator/=(float t);
    
    float Length() const;
    float SqrLength() const;
    Vector3 Normalized() const;
    
    static float Dot(const Vector3& v1, const Vector3& v2);
    static Vector3 Cross(const Vector3& v1, const Vector3& v2);
    
public:
    float e[3];
};