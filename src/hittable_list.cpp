#include "hittable_list.h"

#include "interval.h"

#include "lambertian.h"
#include "metal.h"
#include "dielectric.h"
#include "diffuse_light.h"
#include "quad.h"
#include "sphere.h"

namespace Chotra_RT {

    HittableList::HittableList() {
        CreateScene();
    }

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

    void HittableList::DownloadFromFile() {
    }

    void HittableList::CreateScene() {
 
        // Materials
        std::shared_ptr<Material> black = std::make_shared<Lambertian>(glm::dvec3(0.0, 0.0, 0.0));
        std::shared_ptr<Material> white = std::make_shared<Lambertian>(glm::dvec3(1.0, 1.0, 1.0));
        std::shared_ptr<Material> red = std::make_shared<Lambertian>(glm::dvec3(1.0, 0.0, 0.0));
        std::shared_ptr<Material> green = std::make_shared<Lambertian>(glm::dvec3(0.0, 1.0, 0.0));
        std::shared_ptr<Material> blue = std::make_shared<Lambertian>(glm::dvec3(0.0, 0.0, 1.0));
        std::shared_ptr<Material> gray = std::make_shared<Lambertian>(glm::dvec3(0.7, 0.7, 0.7));

        std::shared_ptr<Material> glass = std::make_shared<Dielectric>(1.5);
        std::shared_ptr<Material> bronze = std::make_shared<Metal>(glm::dvec3(0.8, 0.5, 0.2), 0.0);

        std::shared_ptr<Material> material_light = std::make_shared<DiffuseLight>(glm::dvec3(5.0, 5.0, 5.0));



        // Quads
        Add(std::make_shared<Quad>(glm::dvec3(-3, -3, 3), glm::dvec3(0, 0, -6), glm::dvec3(0, 6, 0), red));
        Add(std::make_shared<Quad>(glm::dvec3(-3, -3, -3), glm::dvec3(6, 0, 0), glm::dvec3(0, 6, 0), green));
        Add(std::make_shared<Quad>(glm::dvec3(3, -3, -3), glm::dvec3(0, 0, 6), glm::dvec3(0, 6, 0), blue));
        Add(std::make_shared<Quad>(glm::dvec3(3, 3, -3), glm::dvec3(0, 0, 6), glm::dvec3(-6, 0, 0), white));
        Add(std::make_shared<Quad>(glm::dvec3(-3, -3, -3), glm::dvec3(0, 0, 6), glm::dvec3(6, 0, 0), gray));


        Add(std::make_shared<Quad>(glm::dvec3(-3, -3, -2), glm::dvec3(1, 0, 0), glm::dvec3(0, 1, 0), black));
        Add(std::make_shared<Quad>(glm::dvec3(-2, -3, -2), glm::dvec3(0, 0, -1), glm::dvec3(0, 1, 0), black));
        Add(std::make_shared<Quad>(glm::dvec3(-3, -2, -2), glm::dvec3(1, 0, 0), glm::dvec3(0, 0, -1), black));


        // Spheres
        Add(std::make_shared<Sphere>(glm::dvec3(-2.2, -2.5, 2.5), 0.5, glass));
        Add(std::make_shared<Sphere>(glm::dvec3(2.1, -2.5, 2.0), 0.5, glass));
        Add(std::make_shared<Sphere>(glm::dvec3(0.4, -2.5, 1.5), 0.5, bronze));
        Add(std::make_shared<Sphere>(glm::dvec3(-1.2, -2.5, 1.5), 0.5, black));
        Add(std::make_shared<Sphere>(glm::dvec3(0.0, -2.5, 0.0), 0.5, blue));
        Add(std::make_shared<Sphere>(glm::dvec3(1.1, -2.5, 0.0), 0.5, red));
        Add(std::make_shared<Sphere>(glm::dvec3(-1.3, -2.5, -1.5), 0.5, bronze));
        Add(std::make_shared<Sphere>(glm::dvec3(1.5, -2.5, -2.0), 0.5, glass));
        Add(std::make_shared<Sphere>(glm::dvec3(-2.5, -1.5, -2.5), 0.5, white));

        // Lights
        //world.Add(std::make_shared<Sphere>(glm::dvec3(0.0, 3.0, 0.0), 1.0, material_light));
        Add(std::make_shared<Quad>(glm::dvec3(-1, -3, -3), glm::dvec3(2, 0, 0), glm::dvec3(0, 5, 0), material_light));

        /*
        // Rendering
        renderer_.Render(image, camera, world);


        float current_time = GetTime();
        float delta_time = current_time - last_time_;
        last_time_ = current_time;
        std::clog << "\nTime spent on rendering: " << delta_time << '\n' << std::flush;

        const char* filename = "image.ppm";
        FilePPM file(filename);
        file.SaveFile(image);

        current_time = GetTime();
        delta_time = current_time - last_time_;
        last_time_ = current_time;
        std::clog << "\nTime spent on saving: " << delta_time << '\n' << std::flush;
        */
    }

} //namespace Chotra_RT