# This file will fetch the contents of "CLI11" Github repository into 
# this project so we can use the library for command-line parsing.
# For more information on "CLI11", please visit:
# https://github.com/CLIUtils/CLI11

# Include CMake's "FetchContent" module.
include(FetchContent)

# Declare "CLI11" module.
FetchContent_Declare(CLI11
    GIT_REPOSITORY  https://github.com/CLIUtils/CLI11.git
    GIT_TAG         master
    GIT_SHALLOW     True

    SOURCE_DIR      "${PROJECT_SOURCE_DIR}/external/CLI11"
    )

# Clone the "CLI11" repository.
FetchContent_Populate(CLI11)

# CMake by default will put this reposity in the "Rimp/build/_deps/" directory.
# But since we changed the value of SOURCE_DIR, now it will clone it in
# "Rimp/external/CLI11".