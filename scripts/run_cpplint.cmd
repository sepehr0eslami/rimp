@ECHO OFF

@REM Linting Script
@REM Only For Windows

forfiles /P ..\src\ /S /M *.cpp /C "python2 cpplint.py @file"
forfiles /P ..\src\ /S /M *.h /C "python2 cpplint.py @file"
PAUSE

@REM This file will check for style issues in every .cpp & .h file in 
@REM the src directory (Rimp\src\) using google's cpplint.py.
@REM visit https://google.github.io/styleguide/cppguide.html#cpplint 
@REM for more information.
@REM After running this script, cpplint.py will calculate the total 
@REM number of style errors in the whole project.
@REM For running this script, first, make sure you have python2 installed.
@REM Then open File Explorer and navigate to the scripts direcotry(Rimp\scripts\)
@REM and run the script by double-clicking on "run_cpplint.cmd",
@REM or open a terminal(CMD, PowerShell, etc.) and navigate to the scripts directory(Rimp\scripts\) 
@REM and run this script by typing:
@REM run_cpplint.cmd