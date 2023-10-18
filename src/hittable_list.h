#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include <memory>
#include <vector>

#include "hittable.h"

namespace Chotra_RT {
    
    class HittableList : public Hittable {
    public:

        std::vector<std::shared_ptr<Hittable>> objects;
        void Add(std::shared_ptr<Hittable> object);
        bool Hit(const Ray& ray, double ray_tmin, double ray_tmax, HitData& rec) const override;

    };

} //namespace Chatra_RT

#endif 

