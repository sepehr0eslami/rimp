# Find sqlite3
# Find the native SQLITE3 headers and libraries.
#
# SQLITE3_INCLUDE_DIRS	- where to find sqlite3.h, etc.
# SQLITE3_LIBRARIES	- List of libraries when using sqlite.
# SQLITE3_FOUND	- True if sqlite found.

include("${PROJECT_SOURCE_DIR}/cmake/folders.cmake")

# If on Windows.
if(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    # If Windows is 64-bit.
    if(CMAKE_SIZEOF_VOID_P STREQUAL "8")
        # Look for the header file.
        find_path(SQLITE3_INCLUDE_DIR NAMES sqlite3.h HINTS "${external_dir}/sqlite3")
        # Look for the library.
        find_library(SQLITE3_LIBRARY NAMES sqlite3 HINTS "${external_dir}/sqlite3/win64")

    # If Windows is 32-bit
    elseif(CMAKE_SIZEOF_VOID_P STREQUAL "4")
        message(STATUS "System: x86")
        # Look for the header file.
        find_path(SQLITE3_INCLUDE_DIR NAMES sqlite3.h HINTS "${external_dir}/sqlite3")
        # Look for the library.
        find_library(SQLITE3_LIBRARY NAMES sqlite3 HINTS "${external_dir}/sqlite3/win32")

    endif()

# If on Linux/MacOS
else()
    # Look for the header file.
    find_path(SQLITE3_INCLUDE_DIR NAMES sqlite3.h)
    # Look for the library.
    find_library(SQLITE3_LIBRARY NAMES sqlite3)

endif()

# Handle the QUIETLY and REQUIRED arguments and set SQLITE3_FOUND to TRUE if all listed variables are TRUE.
include(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(SQLite3 DEFAULT_MSG SQLITE3_LIBRARY SQLITE3_INCLUDE_DIR)

# Copy the results to the output variables.
if(SQLITE3_FOUND)
    set(SQLITE3_LIBRARIES ${SQLITE3_LIBRARY})
    set(SQLITE3_INCLUDE_DIRS ${SQLITE3_INCLUDE_DIR})
else(SQLITE3_FOUND)
    set(SQLITE3_LIBRARIES)
    set(SQLITE3_INCLUDE_DIRS)
endif(SQLITE3_FOUND)

mark_as_advanced(SQLITE3_INCLUDE_DIRS SQLITE3_LIBRARIES)
