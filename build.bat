@echo off

IF NOT EXIST ..\build mkdir ..\build
pushd ..\build

del *.pdb > NUL 2> NUL

echo Building debug .lib:
cl.exe -c -MD -Zi -EHsc -W2 -WX -nologo -Febpng.obj ..\code\bpng.cpp /IC:\LIBPNG\ /link /INCREMENTAL:NO
lib.exe /NOLOGO /OUT:bpng_d.lib bpng.obj
echo.

echo Building release .lib:
cl.exe -c -MT -EHsc -W2 -WX -nologo -Febpng.obj ..\code\bpng.cpp /IC:\LIBPNG\ /link /INCREMENTAL:NO
lib.exe /NOLOGO /OUT:bpng.lib bpng.obj
echo.

echo Building .exe:
cl.exe -MD -Zi -EHsc -W2 -WX -nologo -Febobling_png.exe ..\code\main.cpp /link /IGNORE:4098 /INCREMENTAL:NO /LIBPATH:C:\LIBPNG\bin /LIBPATH:C:\ZLIB\bin user32.lib gdi32.lib bpng_d.lib libpng_d.lib zlib_d.lib

REM Delete .obj files
del *.obj

popd
