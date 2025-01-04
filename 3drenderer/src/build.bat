@echo off
mkdir ..\build

set INCLUDE_PATH=C:\Program Files (x86)\Windows Kits\10\Include\10.0.22621.0\ucrt
set SDL2_PATH=C:\SDL2\include
set SDL2_LIB=C:\SDL2\lib\x64
set LIBRARIES=SDL2.lib SDL2main.lib
set LINKER_OPTIONS=/SUBSYSTEM:WINDOWS shell32.lib

::set LIB_PATH=C:\Program Files (x86)\Windows Kits\10\Lib\10.0.22621.0\ucrt\x64
call "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Auxiliary\Build\vcvars64"

::cl -Zi /Fe: ..\build\render.exe .\*.c /I %INCLUDE_PATH% /I %SDL2_PATH% /link /LIBPATH:%SDL2_LIB% %LIBRARIES% %LINKER_OPTIONS%

cl -Zi /Fe:..\build\render.exe .\*.c /I "%INCLUDE_PATH%" /I "%SDL2_PATH%" /link /LIBPATH:"%SDL2_LIB%" %LIBRARIES% %LINKER_OPTIONS%