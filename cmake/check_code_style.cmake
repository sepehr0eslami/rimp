# Code-style checking automation with CMake.

# If in Linux or OSX, use .sh scripts.
if((CMAKE_SYSTEM_NAME STREQUAL "Linux") OR (CMAKE_SYSTEM_NAME STREQUAL "Darwin"))
    set(FORMATTER "./run_clang_format.sh")
    set(LINTER "./run_cpplint.sh")
# If in windows, use .cmd scripts.
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    set(FORMATTER "run_clang_format.cmd")
    set(LINTER "run_cpplint.cmd")
# Skip style checking if none of the above conditions were true.
else()
    message(WARNING "Unknown Operating System. Skipping Code style checking")
    return()
endif()

# Find the clang-tidy executable and use it in compile time.
find_program(CLANG_TIDY_EXEC NAMES "clang-tidy")
if(NOT CLANG_TIDY_EXEC)
    message(WARNING "Check for clang-tidy: Not found, clang-tidy will not be executed")
else()
    message(STATUS "Check for clang-tidy: Found")
    set(CMAKE_CXX_CLANG_TIDY "clang-tidy")
endif()

# Find the clang-format executable.
find_program(CLANG_FORMAT_EXEC NAMES "clang-format")
# If it wasn't found, skip formatting.
if(NOT CLANG_FORMAT_EXEC)
    message(WARNING "Check for clang-format: Not found, clang-format will not be executed")
# If it was found, run the formatting script.
else()
    message(STATUS "Check for clang-format: Found")
    execute_process(
    COMMAND "${FORMATTER}"
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/scripts/"
    )
endif()

# Find the python2 executable
find_program(PYTHON_EXEC NAMES "python2")
# If it wasn't found, skip linting
if(NOT PYTHON_EXEC)
    message(WARNING "Check for python2: Not found, cpplint.py will not be executed")
# If it was found, run the linting script.
else()
    message(STATUS "Check for python2: Found")
    execute_process(
    COMMAND "${LINTER}"
    WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}/scripts/"
    RESULT_VARIABLE status
    )
    # Stop the compilation in case of any style issues.
    if(NOT status EQUAL 0)
        message(FATAL_ERROR "Code Style issues found (cpplint.py)")
    endif()
endif()
