#include "object.h"

Object::Object()
    : position(Vector3::ZERO)
    , color(Color::WHITE)
{
    
}

Object::Object(const Vector3& inPosition, const Color& inColor)
    : position(inPosition)
    , color(inColor)
{
    
}