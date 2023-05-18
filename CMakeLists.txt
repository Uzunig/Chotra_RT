cmake_minimum_required(VERSION 3.5)

project(Chotra_RT)

add_executable(Chotra_RT
	src/main.cpp
)

target_include_directories(Chotra_RT PRIVATE src)

target_compile_features(Chotra_RT PUBLIC cxx_std_17)

add_subdirectory(../external/glfw ${CMAKE_CURRENT_BINARY_DIR}/glfw)
target_link_libraries(Chotra_RT PRIVATE glfw)

add_subdirectory(../external/glad ${CMAKE_CURRENT_BINARY_DIR}/glad)
target_link_libraries(Chotra_RT PRIVATE glad)


add_library(ImGui STATIC
			../external/imgui/imgui.h
			../external/imgui/imgui.cpp

			../external/imgui/backends/imgui_impl_glfw.h
			../external/imgui/backends/imgui_impl_glfw.cpp

			../external/imgui/backends/imgui_impl_opengl3.h
			../external/imgui/backends/imgui_impl_opengl3.cpp	

			../external/imgui/imgui_demo.cpp
			../external/imgui/imgui_draw.cpp
			../external/imgui/imgui_tables.cpp	
			../external/imgui/imgui_widgets.cpp
)

target_include_directories(ImGui PUBLIC ../external)
target_include_directories(ImGui PUBLIC ../external/imgui)
target_link_libraries(ImGui PRIVATE glad glfw)

target_link_libraries(Chotra_RT PRIVATE ImGui)
					
					