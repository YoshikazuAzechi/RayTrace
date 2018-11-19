#pragma once

#include <string>

class Vector3
{
public:
    Vector3();
    Vector3(float inX, float inY, float inZ);

    Vector3(const Vector3& obj);
    Vector3& operator=(const Vector3& obj);

    float operator[](int idx) const { return elem[idx]; }
    float& operator[](int idx) { return elem[idx]; }

    Vector3& operator+=(const Vector3& v);
    Vector3& operator-=(const Vector3& v);
    Vector3& operator*=(const float t);
    Vector3& operator/=(const float t);

    Vector3 operator+(const Vector3& v) const;
    Vector3 operator-(const Vector3& v) const;
    Vector3 operator/(float t) const;
    Vector3 operator*(float t) const;

    float Dot(const Vector3& v) const;
    Vector3 Cross(const Vector3& v) const;

    float Length() const;
    float SqrLength() const;

    void Normalize();
    Vector3 Normalized() const;

    std::string ToString() const;

public:
    union
    {
        float elem[3];
        struct
        {
            float x, y, z;
        };
    };

    static const Vector3 ZERO;
    static const Vector3 ONE;
    static const Vector3 FRONT;
    static const Vector3 UP;
    static const Vector3 RIGHT;
};
