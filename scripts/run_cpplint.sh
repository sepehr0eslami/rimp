#! /bin/sh

# Linting Script
# Only For Linux/OS X

# This file will check for style issues in every .cpp & .h file in 
# the src directory (Rimp/src/) using google's cpplint.py.
# visit https://google.github.io/styleguide/cppguide.html#cpplint 
# for more information.
# After running this script, cpplint.py will calculate the total 
# number of style errors in the whole project.

# Note that by building this projct in Debug mode, CMake will automatically run 
# this script; But if you want to run it separately:
# First, make sure you have python2 installed.
# Then open a terminal and navigate to the scripts folder(Rimp/scripts/) 
# and give this script execute permission by running:
# chmod +x run_cpplint.sh
# then simply run it by typing:
# ./run_cpplint.sh

python2 cpplint.py `find ../src \( -name \*.cpp -o -name \*.h \)`
