#pragma once


template<typename T>
T Min(const T& a, const T& b)
{
    return a <= b ? a : b;
}

template<typename T>
T Max(const T& a, const T& b)
{
    return a >= b ? a : b;
}

template<typename T>
T Clamp(const T& n, const T& min, const T& max)
{
    return Max(Min(n, max), min);
}