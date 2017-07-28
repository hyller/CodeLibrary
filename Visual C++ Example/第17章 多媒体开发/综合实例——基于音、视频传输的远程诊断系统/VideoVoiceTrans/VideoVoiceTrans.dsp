# Microsoft Developer Studio Project File - Name="VideoVoiceTrans" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=VideoVoiceTrans - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "VideoVoiceTrans.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "VideoVoiceTrans.mak" CFG="VideoVoiceTrans - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "VideoVoiceTrans - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "VideoVoiceTrans - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "VideoVoiceTrans - Win32 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "VideoVoiceTrans - Win32 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "VideoVoiceTrans - Win32 Release"
# Name "VideoVoiceTrans - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ConnectDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\DSocket.cpp
# End Source File
# Begin Source File

SOURCE=.\Mixer.cpp
# End Source File
# Begin Source File

SOURCE=.\PlaySound.cpp
# End Source File
# Begin Source File

SOURCE=.\VideoVoiceTrans.cpp
# End Source File
# Begin Source File

SOURCE=.\VideoVoiceTrans.rc
# End Source File
# Begin Source File

SOURCE=.\VideoVoiceTransDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\reatReport.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordSound.cpp
# End Source File
# Begin Source File

SOURCE=.\REQUESTCON.cpp
# End Source File
# Begin Source File

SOURCE=.\RequestDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\VideoCapture.cpp

!IF  "$(CFG)" == "VideoVoiceTrans - Win32 Release"

!ELSEIF  "$(CFG)" == "VideoVoiceTrans - Win32 Debug"

# ADD CPP /Yu

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\Volume.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ConnectDlg.h
# End Source File
# Begin Source File

SOURCE=.\DSocket.h
# End Source File
# Begin Source File

SOURCE=.\Mixer.h
# End Source File
# Begin Source File

SOURCE=.\PlaySound.h
# End Source File
# Begin Source File

SOURCE=.\VideoVoiceTrans.h
# End Source File
# Begin Source File

SOURCE=.\VideoVoiceTransDlg.h
# End Source File
# Begin Source File

SOURCE=.\reatReport.h
# End Source File
# Begin Source File

SOURCE=.\RecordSound.h
# End Source File
# Begin Source File

SOURCE=.\REQUESTCON.h
# End Source File
# Begin Source File

SOURCE=.\RequestDlg.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\VideoCapture.h
# End Source File
# Begin Source File

SOURCE=.\Volume.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\14.ico
# End Source File
# Begin Source File

SOURCE=".\Help File HLP.ico"
# End Source File
# Begin Source File

SOURCE=.\VideoVoiceTrans.ico
# End Source File
# Begin Source File

SOURCE=.\res\VideoVoiceTrans.ico
# End Source File
# Begin Source File

SOURCE=.\res\VideoVoiceTrans.rc2
# End Source File
# Begin Source File

SOURCE=.\shoot03.ico
# End Source File
# Begin Source File

SOURCE=.\toolbar1.bmp
# End Source File
# Begin Source File

SOURCE=.\xpblue.bin
# End Source File
# End Group
# Begin Group "Encoder"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\encoder\coder.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\coder.h
# End Source File
# Begin Source File

SOURCE=.\encoder\config.h
# End Source File
# Begin Source File

SOURCE=.\encoder\countbit.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\countbit.h
# End Source File
# Begin Source File

SOURCE=.\encoder\ctables.h
# End Source File
# Begin Source File

SOURCE=.\encoder\dct.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\dct.h
# End Source File
# Begin Source File

SOURCE=.\encoder\def.h
# End Source File
# Begin Source File

SOURCE=.\encoder\Global.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\Global.h
# End Source File
# Begin Source File

SOURCE=.\encoder\huffman.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\huffman.h
# End Source File
# Begin Source File

SOURCE=.\encoder\libr263.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\libr263.h
# End Source File
# Begin Source File

SOURCE=.\encoder\mot_est.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\mot_est.h
# End Source File
# Begin Source File

SOURCE=.\encoder\owntypes.h
# End Source File
# Begin Source File

SOURCE=.\encoder\pred.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\pred.h
# End Source File
# Begin Source File

SOURCE=.\encoder\quant.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\quant.h
# End Source File
# Begin Source File

SOURCE=.\encoder\rlib.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\rlib.h
# End Source File
# Begin Source File

SOURCE=.\encoder\stream.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\encoder\stream.h
# End Source File
# Begin Source File

SOURCE=.\encoder\struct.h
# End Source File
# End Group
# Begin Group "Decoder"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\decoder\convert.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\convert.h
# End Source File
# Begin Source File

SOURCE=.\decoder\decdef.h
# End Source File
# Begin Source File

SOURCE=.\decoder\decstruct.h
# End Source File
# Begin Source File

SOURCE=.\decoder\DGlobal.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\DGlobal.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBits.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBits.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBlk.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\GetBlk.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetHdr.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\GetHdr.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetPic.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\GetPic.h
# End Source File
# Begin Source File

SOURCE=.\decoder\GetVlc.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\GetVlc.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Idct.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\Idct.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Idctref.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\Idctref.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Indices.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\Indices.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Recon.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\Recon.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Sac.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\Sac.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Sactbls.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\Sactbls.h
# End Source File
# Begin Source File

SOURCE=.\decoder\Tmndec.cpp
# ADD CPP /YX
# End Source File
# Begin Source File

SOURCE=.\decoder\Tmndec.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\bluepinna.urf
# End Source File
# Begin Source File

SOURCE=.\Debug\GtBase.urf
# End Source File
# Begin Source File

SOURCE=.\face\GtClassic.urf
# End Source File
# Begin Source File

SOURCE=.\GtClassic.urf
# End Source File
# End Target
# End Project
