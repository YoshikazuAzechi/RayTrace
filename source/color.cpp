#include "Color.h"
#include <math.h>
#include <sstream>

const Color Color::BLACK(0.0f, 0.0f, 0.0f);
const Color Color::WHITE(1.0f, 1.0f, 1.0f);
const Color Color::GRAY(0.5f, 0.5f, 0.5f);
const Color Color::RED(1.0f, 0.0f, 0.0f);
const Color Color::GREEN(0.0f, 1.0f, 0.0f);
const Color Color::BLUE(0.0f, 0.0f, 1.0f);
const Color Color::CYAN(0.0f, 1.0f, 1.0f);
const Color Color::MAGENTA(1.0f, 1.0f, 0.0f);
const Color Color::YELLOW(1.0f, 0.0f, 1.0f);

Color::Color()
    : Color(Color::WHITE)
{

}

Color::Color(const Color& obj)
    : Color(obj.r, obj.g, obj.b)
{

}

Color::Color(float inR, float inG, float inB)
    : r(inR)
    , g(inG)
    , b(inB)
{

}

Color& Color::operator=(const Color& obj)
{
    r = obj.r;
    g = obj.g;
    b = obj.b;
    return *this;
}

Color& Color::operator+=(const Color& c)
{
    r += c.r;
    g += c.g;
    b += c.b;
    return *this;
}

Color& Color::operator-=(const Color& c)
{
    r -= c.r;
    g -= c.g;
    b -= c.b;
    return *this;
}

Color& Color::operator*=(const float t)
{
    r *= t;
    g *= t;
    b *= t;
    return *this;
}

Color& Color::operator/=(const float t)
{
    r /= t;
    g /= t;
    b /= t;
    return *this;
}

Color Color::operator+(const Color& c) const
{
    return Color(r + c.r, g + c.g, b + c.b);
}

Color Color::operator-(const Color& c) const
{
    return Color(r - c.r, g - c.g, b - c.b);
}

Color Color::operator/(float t) const
{
    return Color(r / t, g / t, b / t);
}

Color Color::operator*(float t) const
{
    return Color(r * t, g * t, b * t);    
}

std::string Color::ToString() const
{
    std::stringstream ss;
    ss << "(" << r << "," << g << "," << b <<  ")";
    return ss.str();
}
