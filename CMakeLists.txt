cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(Chotra_RT)

add_executable(Chotra_RT 
		src/main.cpp

		src/application.h
		src/application.cpp

		src/image.h
		src/image.cpp
		
		src/image_file.h
		src/image_file.cpp

		src/interval.h
		src/interval.cpp

		src/ray.h
		src/ray.cpp	

		src/camera.h
		src/camera.cpp

		src/lambertian.h
		src/lambertian.cpp

		src/material.h
		src/material.cpp

		src/metal.h
		src/metal.cpp

		src/renderer.h
		src/renderer.cpp	

		src/ray_tracer.h
		src/ray_tracer.cpp	

		src/resource_manager.h
		src/resource_manager.cpp

		src/file.h
		src/file.cpp

		src/hittable.h
		src/hittable.cpp

		src/hittable_list.h
		src/hittable_list.cpp

		src/sphere.h
		src/sphere.cpp
)

include_directories(src)
include_directories(external/glm)
include_directories(external/glfw/include)

add_subdirectory(external/glfw)

target_link_libraries(Chotra_RT glfw)
