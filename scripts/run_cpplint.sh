#! /bin/sh

# Linting Script
# Only For Linux/OS X

python2 cpplint.py `find ../src \( -name \*.cpp -o -name \*.h \)`

# This file will check for style issues in every .cpp & .h file in 
# the src directory (Rimp/src/) using google's cpplint.py.
# visit https://google.github.io/styleguide/cppguide.html#cpplint 
# for more information.
# After running this script, cpplint.py will calculate the total 
# number of style errors in the whole project.
# For running this script, first, make sure you have python2 installed.
# Then open a terminal and navigate to the scripts folder(Rimp/scripts/) 
# and give it execute permission by running:
# chmod +x run_cpplint.sh
# then simply run this script by typing:
# ./run_cpplint.sh