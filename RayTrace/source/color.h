#pragma once

#include <string>

class Color
{
public:
    Color();
    Color(float inR, float inG, float inB);

    Color(const Color& obj);
    Color& operator=(const Color& obj);

    float operator[](int idx) const { return elem[idx]; }
    float& operator[](int idx) { return elem[idx]; }

    Color& operator+=(const Color& c);
    Color& operator-=(const Color& c);
    Color& operator*=(const float t);
    Color& operator/=(const float t);

    Color operator+(const Color& c) const;
    Color operator-(const Color& c) const;
    Color operator/(float t) const;
    Color operator*(float t) const;

    std::string ToString() const;

public:
    union
    {
        float elem[3];
        struct
        {
            float r, g, b;
        };
    };

    static const Color BLACK;
    static const Color WHITE;
    static const Color GRAY;
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color CYAN;
    static const Color MAGENTA;
    static const Color YELLOW;
};
