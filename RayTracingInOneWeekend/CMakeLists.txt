# root CMakeLists
cmake_minimum_required(VERSION 3.0.0)
project(RayTracingInOneWeekend VERSION 0.1.0)

set(CMAKE_SUPPRESS_REGENERATION true)

enable_language(CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_subdirectory(Chapter01)
add_subdirectory(Chapter02)
add_subdirectory(Chapter03)
add_subdirectory(Chapter04)
add_subdirectory(Chapter05)
add_subdirectory(Chapter06)