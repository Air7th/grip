@echo off
cd /d %~dp0

cd..

if exist "build" (
    rmdir /s /q build
)

mkdir build

if %PLATFORM%=="x86" ( 
  set GENERATE_TYPE="Visual Studio 15 2017"
) else if %PLATFORM%=="x64" ( 
  set GENERATE_TYPE="Visual Studio 15 2017 Win64"
)

cmake -H. -Bbuild -DCMAKE_BUILD_TYPE=%CONFIGURATION% -G %GENERATE_TYPE%
cmake --build build --config %CONFIGURATION% 
