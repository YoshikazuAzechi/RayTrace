#include "ppm.h"

#include <iomanip>
#include <sstream>
#include <fstream>
#include "image.h"
#include "color.h"

using namespace std;

namespace ppm
{
    bool Save(const char* filename, const Image& image)
    {
        if(!image.IsValid())
        {
            return false;
        }
        if(filename == nullptr)
        {
            return false;
        }

        std::stringstream ss;

        // Header
        ss << "P3" << endl;
        // Comment
        //ss << "# Ray trace example." << endl;
        // Width x Height
        ss << image.GetWidth() << " " << image.GetHeight() << endl;
        // Max bit
        ss << "255" << endl;

        // Color data
        for(int py = 0;py < image.GetHeight();++py)
        {
            for(int px = 0;px < image.GetWidth();++px)
            {
                Color* color = image(px, py);
                if(color == nullptr)
                {
                    return false;
                }
                // [0 .. 1] to [0 ... 255]
                int r = int(color->r * 255.0f);
                int g = int(color->g * 255.0f);
                int b = int(color->b * 255.0f);

                ss << std::setw(3) << r << " ";
                ss << std::setw(3) << g << " ";
                ss << std::setw(3) << b;
                bool isEndLine = px == image.GetWidth() - 1;
                if(isEndLine)
                {
                    ss << endl;
                }
                else
                {
                    ss << " ";
                }
            }
        }

        fstream fs;
        fs.open(filename, ios::out);

        fs.write(ss.str().c_str(), ss.str().length());

        return true;
    }

    bool Load(const char* filename, Image& image)
    {
        if(filename == nullptr)
        {
            return false;
        }
        return true;
    }
};