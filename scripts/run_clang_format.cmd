@ECHO OFF

@REM Formatting Script
@REM Only For Windows

forfiles /P ..\src\ /S /M *.cpp /C "clang-format --style=file --verbose -i @file"
forfiles /P ..\src\ /S /M *.h /C "clang-format --style=file --verbose -i @file"
PAUSE

@REM This file will format every .cpp & .h files in the src directory(Rimp\src\). 
@REM After running this file the whole project should be formatted based on the options
@REM specified in "Rimp\.clang-format" file.
@REM For formatting this project, first, make sure you have clang-format installed.
@REM Then open a terminal(CMD, PowerShell, etc.) and go to the scripts directory(Rimp\scripts\) 
@REM and run this script by typing:
@REM run_clang_format.cmd