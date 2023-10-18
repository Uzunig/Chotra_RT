#include "hittable_list.h"

namespace Chotra_RT {

    void HittableList::Add(std::shared_ptr<Hittable> object) {
        objects.push_back(object);
    }

    bool HittableList::Hit(const Ray& ray, double ray_tmin, double ray_tmax, HitData& hit_data) const {

        HitData temp_hit_data;
        bool hit_anything = false;
        auto closest_so_far = ray_tmax;

        for (const auto& object : objects) {
            if (object->Hit(ray, ray_tmin, closest_so_far, temp_hit_data)) {
                hit_anything = true;
                closest_so_far = temp_hit_data.t;
                hit_data = temp_hit_data;
            }
        }
        return hit_anything;
    }

} //namespace Chotra_RT