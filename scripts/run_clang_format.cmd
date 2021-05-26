@ECHO OFF

@REM Formatting Script
@REM Only For Windows

@REM This file will format every .cpp & .h files in the src directory(Rimp\src\) 
@REM After running this file the whole projct should be formatted based on the options
@REM mentioned in "Rimp\.clang-format" file.

@REM Note that by building this projct in Debug mode, CMake will automatically run 
@REM this script; But if you want to run it separately:
@REM First make sure you have clang-format installed.
@REM Then open File Explorer and navigate to the scripts direcotry(Rimp\scripts\)
@REM and run the script by double-clicking on "run_clang_format.cmd",
@REM or open a terminal(CMD, PowerShell, etc.) and navigate to the scripts directory(Rimp\scripts\) 
@REM and run this script by typing:
@REM run_clang_format.cmd

forfiles /P ..\src\ /S /M *.cpp /C "clang-format --style=file --verbose -i @file"
forfiles /P ..\src\ /S /M *.h /C "clang-format --style=file --verbose -i @file"
PAUSE