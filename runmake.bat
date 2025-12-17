@echo off
REM ========================================
REM  PASSWORD GENERATOR - Windows Batch File
REM  Kompajlira i pokreće program
REM ========================================

echo.
echo ========================================
echo   PASSWORD GENERATOR - Build and Run
echo ========================================
echo.

REM Provera da li je gcc instaliran
where gcc >nul 2>nul
if %ERRORLEVEL% NEQ 0 (
    echo [ERROR] GCC nije instaliran!
    echo Preuzmi MinGW ili instaliraj GCC sa: https://www.mingw-w64.org/
    pause
    exit /b 1
)

REM Kreiraj bin direktorijum ako ne postoji
if not exist "bin" (
    mkdir bin
    echo [INFO] Kreiran bin direktorijum
)

REM Direktna kompilacija
echo.
echo Kompajliranje programa...
gcc src/main.c src/password_gen.c src/utils.c -o bin/password_generator -Wall -Wextra -std=c99 -g

if %ERRORLEVEL% NEQ 0 (
    echo.
    echo [ERROR] Greska pri kompajliranju!
    pause
    exit /b 1
)

echo [OK] Kompajliranje uspesno!
echo.
echo Pokretanje programa...
echo ========================================
echo.

REM Pokreni program
bin\password_generator

echo.
echo ========================================
echo [OK] Program je zavrsio rad
echo ========================================
pause
