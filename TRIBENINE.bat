@echo off
set LOADER_PATH=%~dp0
set ZERO_DLL_PATH=%LOADER_PATH%\libzero.dll
set TRIBENINE_PATH=E:\SteamLibrary\steamapps\common\TRIBENINE

cd /D "%LOADER_PATH%"
.\loader.exe "%TRIBENINE_PATH%\tribenine.exe" "%ZERO_DLL_PATH%"