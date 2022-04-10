# CMakeList.txt : CMake project for Graphics Test, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Include SDL2 package
find_package (SDL2 REQUIRED)
include_directories (${SDL2_INCLUDE_DIRS})

# Add source to this project's executable.
add_executable (CMakeTarget "Graphics Test.cpp" "Graphics/Graphics.cpp" "Graphics/CrawlingAnt.cpp" "Graphics/GaussianBump.cpp" "Graphics/Menu.cpp" "Graphics/GameOfLife.cpp" "Graphics/RayTracerMaze.cpp")

if (WIN32 AND CMAKE_BUILD_TYPE STREQUAL "Release")
	add_executable (CMakeTarget WIN32)
endif()

# Set the name of the output executable
set_target_properties(CMakeTarget PROPERTIES OUTPUT_NAME "Graphics Test")

target_link_libraries (CMakeTarget ${SDL2_LIBRARIES})