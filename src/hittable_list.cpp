#include "hittable_list.h"

#include "interval.h"

namespace Chotra_RT {

    void HittableList::Add(std::shared_ptr<Hittable> object) {
        objects.push_back(object);
    }

    bool HittableList::Hit(const Ray& ray, Interval interval_t, HitData& hit_data) const {

        HitData temp_hit_data;
        bool hit_anything = false;
        auto closest_so_far = interval_t.max;

        for (const auto& object : objects) {
            if (object->Hit(ray, Interval(interval_t.min, closest_so_far), temp_hit_data)) {
                hit_anything = true;
                closest_so_far = temp_hit_data.t;
                hit_data = temp_hit_data;
            }
        }
        return hit_anything;
    }

} //namespace Chotra_RT