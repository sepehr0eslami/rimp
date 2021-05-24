cmake_minimum_required(VERSION 3.0.0)

project(Rimp VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(source_dir "${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE source_files "${source_dir}/*.cpp")

add_executable(${PROJECT_NAME} ${source_files})