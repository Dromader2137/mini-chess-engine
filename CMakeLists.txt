cmake_minimum_required(VERSION 4.2)

project(MyProjectName)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 23)

add_subdirectory(engine)
add_subdirectory(gui)
