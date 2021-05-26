cmake_minimum_required(VERSION 3.0.0)

project(Rimp VERSION 0.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

set(cmake_folder "${PROJECT_SOURCE_DIR}/cmake")

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    include("${cmake_folder}/check_code_style.cmake")
endif()

set(source_dir "${PROJECT_SOURCE_DIR}/src")
file(GLOB_RECURSE source_files "${source_dir}/*.cpp")

add_executable(${PROJECT_NAME} ${source_files})