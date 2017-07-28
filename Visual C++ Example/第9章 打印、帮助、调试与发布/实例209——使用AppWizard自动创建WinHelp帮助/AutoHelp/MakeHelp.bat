@echo off
REM -- First make map file from Microsoft Visual C++ generated resource.h
echo // MAKEHELP.BAT generated Help Map file.  Used by AUTOHELP.HPJ. >"hlp\AutoHelp.hm"
echo. >>"hlp\AutoHelp.hm"
echo // Commands (ID_* and IDM_*) >>"hlp\AutoHelp.hm"
makehm ID_,HID_,0x10000 IDM_,HIDM_,0x10000 resource.h >>"hlp\AutoHelp.hm"
echo. >>"hlp\AutoHelp.hm"
echo // Prompts (IDP_*) >>"hlp\AutoHelp.hm"
makehm IDP_,HIDP_,0x30000 resource.h >>"hlp\AutoHelp.hm"
echo. >>"hlp\AutoHelp.hm"
echo // Resources (IDR_*) >>"hlp\AutoHelp.hm"
makehm IDR_,HIDR_,0x20000 resource.h >>"hlp\AutoHelp.hm"
echo. >>"hlp\AutoHelp.hm"
echo // Dialogs (IDD_*) >>"hlp\AutoHelp.hm"
makehm IDD_,HIDD_,0x20000 resource.h >>"hlp\AutoHelp.hm"
echo. >>"hlp\AutoHelp.hm"
echo // Frame Controls (IDW_*) >>"hlp\AutoHelp.hm"
makehm IDW_,HIDW_,0x50000 resource.h >>"hlp\AutoHelp.hm"
REM -- Make help for Project AUTOHELP


echo Building Win32 Help files
start /wait hcw /C /E /M "hlp\AutoHelp.hpj"
if errorlevel 1 goto :Error
if not exist "hlp\AutoHelp.hlp" goto :Error
if not exist "hlp\AutoHelp.cnt" goto :Error
echo.
if exist Debug\nul copy "hlp\AutoHelp.hlp" Debug
if exist Debug\nul copy "hlp\AutoHelp.cnt" Debug
if exist Release\nul copy "hlp\AutoHelp.hlp" Release
if exist Release\nul copy "hlp\AutoHelp.cnt" Release
echo.
goto :done

:Error
echo hlp\AutoHelp.hpj(1) : error: Problem encountered creating help file

:done
echo.
