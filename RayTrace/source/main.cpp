#include <iostream>
#include <math.h>

#include "image.h"
#include "color.h"
#include "sphere.h"
#include "vector3.h"
#include "ppm.h"
#include "world.h"

using namespace std;

int main()
{
    Image image;
    image.CreateBuffer(200, 150, Color::GRAY);

    World world;
    world.AddObject(new Sphere(Vector3(-3.0f, 0.0f, 3.0f), 1.0f, Color::RED));
    world.AddObject(new Sphere(Vector3(0.0f, 0.0f, 3.0f), 1.0f, Color::GREEN));
    world.AddObject(new Sphere(Vector3(3.0f, 0.0f, 3.0f), 1.0f, Color::BLUE));
    
    world.Render(&image, Vector3(8.0f, 6.0f, 0.0f));
    
    bool succeeded = ppm::Save("image.ppm", image);

    if (succeeded)
    {
        cout << "Succeeded." << endl;
    }
    else
    {
        cout << "Failed." << endl;
    }

    getchar();
    return 0;
}
