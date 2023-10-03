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

		src/ray.h
		src/ray.cpp	

		src/camera.h
		src/camera.cpp

		src/renderer.h
		src/renderer.cpp	

		src/resource_manager.h
		src/resource_manager.cpp
)

include_directories(src)
include_directories(external/glm)
include_directories(external/glfw/include)

add_subdirectory(external/glfw)

target_link_libraries(Chotra_RT glfw)
