# Microsoft Developer Studio Project File - Name="MedicAdmin" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=MedicAdmin - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MedicAdmin.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MedicAdmin.mak" CFG="MedicAdmin - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MedicAdmin - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "MedicAdmin - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MedicAdmin - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "MedicAdmin - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MedicAdmin - Win32 Release"
# Name "MedicAdmin - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ChangePasswordDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\CleanUpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DeleteUserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\LogInDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\MainFrm.cpp
# End Source File
# Begin Source File

SOURCE=.\ManageMedic.cpp
# End Source File
# Begin Source File

SOURCE=.\Medic.cpp
# End Source File
# Begin Source File

SOURCE=.\MedicAdmin.cpp
# End Source File
# Begin Source File

SOURCE=.\MedicAdmin.rc
# End Source File
# Begin Source File

SOURCE=.\MedicAdminDoc.cpp
# End Source File
# Begin Source File

SOURCE=.\MedicAdminView.cpp
# End Source File
# Begin Source File

SOURCE=.\MedicListView.cpp
# End Source File
# Begin Source File

SOURCE=.\MedicSearch.cpp
# End Source File
# Begin Source File

SOURCE=.\MedicSet.cpp
# End Source File
# Begin Source File

SOURCE=.\RegisterUserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Sale.cpp
# End Source File
# Begin Source File

SOURCE=.\SaleDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SaleSet.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchIDDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchNameDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchTypeDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\SeekUserDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\StoreDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\User.cpp
# End Source File
# Begin Source File

SOURCE=.\UserChangDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\UserSet.cpp
# End Source File
# Begin Source File

SOURCE=.\UserTreeView.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ChangePasswordDlg.h
# End Source File
# Begin Source File

SOURCE=.\CleanUpDlg.h
# End Source File
# Begin Source File

SOURCE=.\DeleteUserDlg.h
# End Source File
# Begin Source File

SOURCE=.\LogInDlg.h
# End Source File
# Begin Source File

SOURCE=.\MainFrm.h
# End Source File
# Begin Source File

SOURCE=.\ManageMedic.h
# End Source File
# Begin Source File

SOURCE=.\Medic.h
# End Source File
# Begin Source File

SOURCE=.\MedicAdmin.h
# End Source File
# Begin Source File

SOURCE=.\MedicAdminDoc.h
# End Source File
# Begin Source File

SOURCE=.\MedicAdminView.h
# End Source File
# Begin Source File

SOURCE=.\MedicListView.h
# End Source File
# Begin Source File

SOURCE=.\MedicSearch.h
# End Source File
# Begin Source File

SOURCE=.\MedicSet.h
# End Source File
# Begin Source File

SOURCE=.\RegisterUserDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Sale.h
# End Source File
# Begin Source File

SOURCE=.\SaleDlg.h
# End Source File
# Begin Source File

SOURCE=.\SaleSet.h
# End Source File
# Begin Source File

SOURCE=.\SearchIDDlg.h
# End Source File
# Begin Source File

SOURCE=.\SearchNameDlg.h
# End Source File
# Begin Source File

SOURCE=.\SearchTypeDlg.h
# End Source File
# Begin Source File

SOURCE=.\SeekUserDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\StoreDlg.h
# End Source File
# Begin Source File

SOURCE=.\User.h
# End Source File
# Begin Source File

SOURCE=.\UserChangDlg.h
# End Source File
# Begin Source File

SOURCE=.\UserSet.h
# End Source File
# Begin Source File

SOURCE=.\UserTreeView.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\bmp\bitmap5.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\clear.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\doctor1.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\fool1.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\fool2.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\in.BMP
# End Source File
# Begin Source File

SOURCE=".\bmp\MA_SMILE 51.BMP"
# End Source File
# Begin Source File

SOURCE=.\res\MedicAdmin.ico
# End Source File
# Begin Source File

SOURCE=.\res\MedicAdmin.rc2
# End Source File
# Begin Source File

SOURCE=.\res\MedicAdminDoc.ico
# End Source File
# Begin Source File

SOURCE=.\bmp\PASS.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\password1.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\sale.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\salesman1.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\selected1.BMP
# End Source File
# Begin Source File

SOURCE=.\bmp\tool1.BMP
# End Source File
# Begin Source File

SOURCE=.\res\Toolbar.bmp
# End Source File
# Begin Source File

SOURCE=.\bmp\unselected1.BMP
# End Source File
# End Group
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
