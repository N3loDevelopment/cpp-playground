@echo off
g++ -o main.exe main.cpp receiver.cpp -lstdc++ -lws2_32
if %ERRORLEVEL% EQU 0 (
    echo Build erfolgreich!
    echo.
    echo Starte Programm...
    main.exe
) else (
    echo Build fehlgeschlagen!
)
pause
