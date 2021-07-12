#! /bin/sh

# Formatting Script
# Only For Linux/OS X

# This file will format every .cpp & .h file in the src directory(Rimp/src/). 
# After running this file the whole project should be formatted based on the options
# specified in "Rimp/.clang-format" file.

# Note that by building this projct in Debug mode, CMake will automatically run 
# this script; But if you want to run it separately:
# First, make sure you have clang-format installed.
# Then open a terminal and go to the scripts directory(Rimp/scripts/) 
# and give this script execute permission by running:
# chmod +x run_clang_format.sh
# then simply run it by typing:
# ./run_clang_format.sh

clang-format --style=file --verbose -i `find ../src/ \( -name \*.cpp -o -name \*.h \) -type f`
