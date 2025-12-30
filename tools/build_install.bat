@echo off
setlocal ENABLEDELAYEDEXPANSION

echo Where should the library be installed?
echo 1^) C:\msys64\usr\lib (for sdl2 and raylib builds)
echo 2^) C:\devkitPro\portlibs\wii\lib (for wii builds)
echo.
set /p choice=Choose [1]: 

if "%choice%"=="" set choice=1

cd ..

if "%choice%"=="2" (
    set PREFIX=C:\devkitPro\portlibs\wii
) else if "%choice%"=="1" (
    set PREFIX=C:\msys64\usr
) else (
    echo Invalid option
    exit /b 1
)

echo.
echo Installing to: %PREFIX%
echo.

REM

if "%choice%"=="2" (
    echo Cleaning...
    make clean
    if errorlevel 1 (
        echo Build clean failed
        exit /b 1
    )

    echo Building...
    make -j
    if errorlevel 1 (
        echo Build failed
        exit /b 1
    )

    echo Installing library...
    copy build\libBeloveEngine.a "%PREFIX%\lib\" >nul
    if errorlevel 1 (
        echo Failed to copy library
        exit /b 1
    )

    copy include\BeloveEngine.hpp "%PREFIX%\include\" >nul
    if errorlevel 1 (
        echo Failed to copy headers
        exit /b 1
    )

    echo All set, thanks for using Belove!
    exit /b 0
)

REM

if not exist build (
    mkdir build
)

cd build

echo Configuring with CMake...
cmake .. -DCMAKE_INSTALL_PREFIX="%PREFIX%"
if errorlevel 1 (
    echo CMake configuration failed
    exit /b 1
)

echo Building...
make -j
if errorlevel 1 (
    echo Build failed
    exit /b 1
)

echo Installing library...
make install
if errorlevel 1 (
    echo Installation failed
    exit /b 1
)

echo All set, thanks for using Belove!
exit /b 0
