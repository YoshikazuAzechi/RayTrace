#pragma once

class Image;

namespace ppm
{
    bool Save(const char* filename, const Image& image);
    bool Load(const char* filename, Image& image);
};