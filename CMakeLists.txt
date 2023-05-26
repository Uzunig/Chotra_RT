cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

project(Chotra_RT)

target_include_directories(Chotra_RT PRIVATE src)
target_include_directories(Chotra_RT PRIVATE external)

add_executable(Chotra_RT 
		src/main.cpp
)