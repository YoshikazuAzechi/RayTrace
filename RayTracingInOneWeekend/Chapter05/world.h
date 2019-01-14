#pragma once

#include <vector>
#include "hitable.h"

class World
{
public:
    World()
    {
        hitableList.clear();
    }
    
    ~World()
    {
        for(const Hitable* hitable : hitableList)
        {
            if(hitable)
            {
                delete hitable;
            }
        }
        hitableList.clear();
    }
    
    bool Hit(const Ray& ray, float t_min, float t_max, HitRecord& outRecord) const
    {
        float t_closest = t_max;
        bool hitAny = false;
        for(const Hitable* hitable : hitableList)
        {
            if(!hitable)
            {
                continue;
            }
            
            HitRecord recordWork;
            if(hitable->Hit(ray, t_min, t_closest, recordWork))
            {
                hitAny = true;
                t_closest = recordWork.t;
                outRecord = recordWork;
            }
        }
        
        return hitAny;
    }
    
    void Add(const Hitable* object)
    {
        hitableList.push_back(object);
    }
    
private:
    std::vector<const Hitable*> hitableList;
};
