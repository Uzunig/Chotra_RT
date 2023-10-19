#include "hittable.h"

#include "interval.h"

namespace Chotra_RT {

    void HitData::SetFaceNormal(const Ray& ray, const glm::dvec3& outward_normal) {

        front_face = dot(ray.GetDirection(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }

} //namespace Chotra_RT