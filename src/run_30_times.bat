@echo off
echo Building and running dot product test 30 times with vector length 536870912...
echo.

echo Building the project...
nasm -f win64 kernel.asm
gcc -c main.c -o main.c.obj -m64
gcc -c dot_product_c.c -o dot_product_c.obj -m64
gcc main.c.obj dot_product_c.obj kernel.obj -o main.exe -m64

if %errorlevel% neq 0 (
    echo ERROR: Build failed!
    pause
    exit /b 1
)

echo Build successful! Starting 30 test runs...
echo.

for /L %%i in (1,1,30) do (
    echo ========== Run %%i of 30 ==========
    echo 16,777,216 | main.exe
    echo.
)

echo.
echo All 30 runs completed!
pause
