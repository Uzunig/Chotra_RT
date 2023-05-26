cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(CMAKE_CXX_STANDARD 17)

project(Chotra_RT)

add_executable(Chotra_RT 
		src/main.cpp
)

include_directories(src)
include_directories(external/glm)
include_directories(external/glfw/include)

add_subdirectory(external/glfw)

target_link_libraries(Chotra_RT glfw)
