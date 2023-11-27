cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(Chotra_RT)
find_package(Vulkan REQUIRED FATAL_ERROR)

add_executable(Chotra_RT 
    src/main.cpp
)

target_sources(Chotra_RT PRIVATE
    src/api/glfw_context.h
    src/api/glfw_context.cpp

    src/api/vulkan_context.h
    src/api/vulkan_context.cpp

    src/core/application.h
    src/core/application.cpp

    src/core/renderer.h
    src/core/renderer.cpp

    src/gui/window.h
    src/gui/window.cpp

    src/materials/material.h
    src/materials/material.cpp

    src/materials/lambertian.h
    src/materials/lambertian.cpp

    src/materials/metal.h
    src/materials/metal.cpp

    src/materials/dielectric.h
    src/materials/dielectric.cpp

    src/materials/diffuse_light.h
    src/materials/diffuse_light.cpp

    src/ray_tracing/ray_tracer.h
    src/ray_tracing/ray_tracer.cpp

    src/ray_tracing/ray.h
    src/ray_tracing/ray.cpp

    src/ray_tracing/camera.h
    src/ray_tracing/camera.cpp

    src/ray_tracing/hittable.h
    src/ray_tracing/hittable.cpp

    src/ray_tracing/hittable_list.h
    src/ray_tracing/hittable_list.cpp

    src/resource_manager/resource_manager.h
    src/resource_manager/resource_manager.cpp

    src/resource_manager/sphere.h
    src/resource_manager/sphere.cpp

    src/resource_manager/plane.h
    src/resource_manager/plane.cpp

    src/resource_manager/quad.h
    src/resource_manager/quad.cpp

    src/utils/image.h
    src/utils/image.cpp

    src/utils/image_file.h
    src/utils/image_file.cpp

    src/utils/interval.h
    src/utils/interval.cpp

    src/utils/file.h
    src/utils/file.cpp

    src/utils/timer.h
    src/utils/timer.cpp
)

target_include_directories(Chotra_RT PRIVATE
    src
    external/glm
    external/glfw/include
)

add_subdirectory(external/glfw)

target_link_libraries(Chotra_RT glfw Vulkan::Vulkan)
