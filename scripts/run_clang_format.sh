#! /bin/sh

# Formatting Script
# Only For Linux/OS X

clang-format --style=file --verbose -i `find ../src/ \( -name \*.cpp -o -name \*.h \) -type f`

# This file will format every .cpp & .h file in the src directory(Rimp/src/). 
# After running this file the whole project should be formatted based on the options
# specified in "Rimp/.clang-format" file.
# For formatting this project, first, make sure you have clang-format installed.
# Then open a terminal and go to the scripts directory(Rimp/scripts/) 
# and run this script by typing:
# ./run_clang_format.sh