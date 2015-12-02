# Microsoft Developer Studio Project File - Name="SimulationTrial" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=SimulationTrial - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "SimulationTrial.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "SimulationTrial.mak" CFG="SimulationTrial - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "SimulationTrial - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "SimulationTrial - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "SimulationTrial - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Output\Release"
# PROP Intermediate_Dir "Output\Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /G5 /MT /W3 /GX /O1 /I "GUI\Include" /I "Config" /D "NDEBUG" /D "TARGET_1375_C8_137X" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "NDEBUG"
# ADD RSC /l 0x407 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib shell32.lib winmm.lib libcmt.lib ws2_32.lib /nologo /subsystem:windows /pdb:none /map /machine:I386 /nodefaultlib /out:"Exe/GUISimulation.exe"
# SUBTRACT LINK32 /debug

!ELSEIF  "$(CFG)" == "SimulationTrial - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Output\Debug"
# PROP Intermediate_Dir "Output\Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /G5 /MTd /W3 /Gm /GX /ZI /Od /I "GUI\Include" /I "Config" /D "_DEBUG" /D "TARGET_1375_C8_137X" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /FD /GZ /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x407 /d "_DEBUG"
# ADD RSC /l 0x409
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib shell32.lib winmm.lib libcmt.lib ws2_32.lib /nologo /subsystem:windows /debug /machine:I386 /nodefaultlib /out:"Exe/GUISimulationDebug.exe" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "SimulationTrial - Win32 Release"
# Name "SimulationTrial - Win32 Debug"
# Begin Group "Application"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Application\GUIDEMO.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO.H
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_AntialiasedText.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Automotive.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_BarGraph.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Bitmap.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_ColorBar.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Conf.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Cursor.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Fading.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Graph.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_IconView.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_ImageFlow.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Intro.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Listview.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_RadialMenu.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Resource.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Skinning.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Speed.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Speedometer.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Start.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_TransparentDialog.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_Treeview.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_VScreen.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_WashingMachine.c
# End Source File
# Begin Source File

SOURCE=.\Application\GUIDEMO_ZoomAndRotate.c
# End Source File
# End Group
# Begin Group "Config"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Config\GUIConf.c
# End Source File
# Begin Source File

SOURCE=.\Config\GUIConf.h
# End Source File
# Begin Source File

SOURCE=.\Config\LCDConf.c
# End Source File
# Begin Source File

SOURCE=.\Config\LCDConf.h
# End Source File
# Begin Source File

SOURCE=.\Config\SIMConf.c
# End Source File
# End Group
# Begin Group "GUI"

# PROP Default_Filter ""
# Begin Group "Include"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\GUI\Include\BUTTON.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\CALENDAR.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\CHECKBOX.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\CHOOSECOLOR.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\CHOOSEFILE.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\DIALOG.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\DIALOG_Intern.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\DROPDOWN.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\EDIT.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\EDIT_Private.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\FRAMEWIN.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\Global.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GRAPH.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_ARRAY.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_ConfDefaults.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_Debug.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_FontIntern.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_HOOK.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_Private.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_SetOrientation.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_SetOrientationCX.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_SIM_Win32.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_Type.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_Version.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\GUI_VNC.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\HEADER.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\ICONVIEW.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\IMAGE.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\KNOB.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LCD.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LCD_ConfDefaults.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LCD_Private.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LCD_Protected.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LCD_SIM.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LISTBOX.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LISTVIEW.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\LISTWHEEL.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\MENU.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\MESSAGEBOX.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\MULTIEDIT.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\MULTIPAGE.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\PROGBAR.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\RADIO.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\SCROLLBAR.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\SIM.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\SIM_GetRegions.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\SLIDER.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\SPINBOX.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\TEXT.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\TREEVIEW.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\WIDGET.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\WM.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\WM_GUI.h
# End Source File
# Begin Source File

SOURCE=.\GUI\Include\WM_Intern.h
# End Source File
# End Group
# Begin Group "Library"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\GUI\Library\GUI.lib
# End Source File
# End Group
# End Group
# Begin Group "Sample"

# PROP Default_Filter ""
# Begin Group "Tutorial"

# PROP Default_Filter ""
# Begin Group "ALPHA_DawBitmapHWAlpha"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\ALPHA_DawBitmapHWAlpha\ALPHA_DrawBitmapHWAlpha.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\ALPHA_DawBitmapHWAlpha\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\ALPHA_DawBitmapHWAlpha\SIMConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "ALPHA_TransparentDialog"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\ALPHA_TransparentDialog\ALPHA_TransparentDialog.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\ALPHA_TransparentDialog\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "COLOR_DemoLUT"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\COLOR_DemoLUT\COLOR_DemoLUT.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\COLOR_DemoLUT\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "FONT_ShowXBF"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\FONT_ShowXBF\FONT_ShowXBF.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MEMDEV_ImageFlow"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_ImageFlow\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_ImageFlow\MEMDEV_ImageFlow.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MEMDEV_ListWheelEffects"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_ListWheelEffects\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_ListWheelEffects\MEMDEV_ListWheelEffects.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MEMDEV_WindowEffects"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\Desktop_320x240.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\FontConverter0_320x224.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\FontConverter1_320x224.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\FontOptions0_117x96.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\FontOptions1_117x96.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\FontSelection_174x138.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\GUIConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\Main.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WindowEffects\MEMDEV_WindowEffects.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MOTION_IconSlide"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MOTION_IconSlide\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MOTION_IconSlide\MOTION_IconSlide.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MOTION_SmartPhoneMenu"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MOTION_SmartPhoneMenu\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MOTION_SmartPhoneMenu\MOTION_SmartPhoneMenu.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MTOUCH_PictureViewer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MTOUCH_PictureViewer\GUIConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MTOUCH_PictureViewer\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MTOUCH_PictureViewer\MTOUCH_PictureViewer.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MULTILAYER_AlphaChromaMove"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_AlphaChromaMove\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_AlphaChromaMove\MULTILAYER_AlphaChromaMove.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_AlphaChromaMove\SIMConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MULTILAYER_IconSlide"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_IconSlide\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_IconSlide\MULTILAYER_IconSlide.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_IconSlide\SIMConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MULTILAYER_PictureViewer"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_PictureViewer\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_PictureViewer\MULTILAYER_PictureViewer.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_PictureViewer\SIMConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "MULTILAYER_WinterAnimation"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_WinterAnimation\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_WinterAnimation\MULTILAYER_WinterAnimation.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MULTILAYER_WinterAnimation\SIMConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "SIM_CustomBitmapView"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\SIM_CustomBitmapView\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SIM_CustomBitmapView\MainTask.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SIM_CustomBitmapView\MainTask.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SIM_CustomBitmapView\SIMConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "SIM_HardKey"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\SIM_HardKey\SIM_Hardkey.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SIM_HardKey\SIMConf.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "SKINNING_NestedModal"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\SKINNING_NestedModal\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SKINNING_NestedModal\SKINNING_NestedModal.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "SKINNING_Notepad"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\SKINNING_Notepad\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SKINNING_Notepad\SKINNING_Notepad.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "VSCREEN_MultiPage"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_MultiPage\About.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_MultiPage\Calibration.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_MultiPage\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_MultiPage\LogoBitmap.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_MultiPage\Main.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_MultiPage\Setup.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_MultiPage\VSCREEN_MultiPage.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "VSCREEN_RealTime"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_RealTime\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VSCREEN_RealTime\VSCREEN_RealTime.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_Amplifier"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Amplifier\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Amplifier\WIDGET_Amplifier.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_Checkbox"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Checkbox\BitmapBar.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Checkbox\BitmapCheckXL.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Checkbox\BitmapCheckXXL.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Checkbox\Main.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Checkbox\WIDGET_Checkbox.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_IconView"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_IconView\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_IconView\WIDGET_Iconview.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_ListWheel"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ListWheel\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ListWheel\WIDGET_ListWheel.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_SchemeLarge"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeLarge\GUIConf.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeLarge\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeLarge\WIDGET_SchemeLarge.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_SchemeMedium"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeMedium\GUIConf.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeMedium\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeMedium\WIDGET_SchemeMedium.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_SchemeSmall"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeSmall\GUIConf.h
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeSmall\LCDConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SchemeSmall\WIDGET_SchemeSmall.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Group "WIDGET_Treeview"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Treeview\GUIConf.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Treeview\WIDGET_Treeview.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_BMPExport.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_DrawBMP.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_DrawGIF.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_DrawJPEG.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_DrawJPEGScaled.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_DrawPNG.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_DrawPolygon.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\2DGL_DrawScale.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\AA_HiResAntialiasing.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\AA_HiResPixels.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\AA_Lines.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\AA_Text.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\ALPHA_Bargraph.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\ALPHA_TransWidgets.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\BASIC_DrawingRects.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\BASIC_DriverPerformance.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\BASIC_Hello1.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\BASIC_HelloWorld.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\BASIC_Performance.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\COLOR_ShowColorBar.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\CURSOR_Sample.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_All.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_Count.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_FS_ChooseFile.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_MenuStructure.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_MessageBox.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_MessageBoxUser.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_NestedModal.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_Radio.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\DIALOG_SliderColor.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\FONT_Arabic.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\FONT_ShiftJIS.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\FONT_ShowAllTTFs.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\FONT_ThaiText.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\LANG_UTF8_CSV_TXT.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\LANG_UTF8_Text.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_AttitudeIndicator.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_AutoDev.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_Banding.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_BitmapSpeedometer.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_BlurAndBlend.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_FadeIn.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_FadingPerformance.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_MemDev.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_Printing.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_Speedometer.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_UseDataPointer.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_WM_Ticker.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MEMDEV_ZoomAndRotate.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MOTION_MovingWindow.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MOTION_RadialMenu.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MOVIE_ShowFeatures.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MOVIE_ShowFromFS.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MT_MultiTasking.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\MTOUCH_ScratchAndGestures.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\ProblemReport.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SPRITE_MultiTaskingDolphins.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\SPRITE_SimpleDolphins.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\TOUCH_Calibrate.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\TOUCH_Sample.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\VNC.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ButtonPhone.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ButtonRound.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ButtonSimple.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_CustomEffect.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_CustomTreeview.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_CustomWidgetType.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Dropdown.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Edit.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_EditWinmode.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Effect.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_FrameWin.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_GraphXY.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_GraphYT.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Header.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ListBox.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ListBoxOwnerDraw.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ListView.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Menu.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Multiedit.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_MultieditTryIt.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Multipage.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_NumPad.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_PopupMenu.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Progbar.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_ScrollbarMove.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SimpleListBox.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SimpleProgbar.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_SortedListview.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Spinbox.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_TreeviewTryit.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WIDGET_Window.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WM_LateClipping.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WM_Redraw.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WM_Sample.c
# PROP Exclude_From_Build 1
# End Source File
# Begin Source File

SOURCE=.\Sample\Tutorial\WM_Video.c
# PROP Exclude_From_Build 1
# End Source File
# End Group
# End Group
# Begin Group "Simulation"

# PROP Default_Filter ""
# Begin Source File

SOURCE="..\..\..\Program Files\Microsoft Visual Studio\VC98\Include\BASETSD.H"
# End Source File
# Begin Source File

SOURCE=.\Simulation\Simulation.res
# End Source File
# Begin Source File

SOURCE=.\Simulation\WinMain.c
# End Source File
# Begin Source File

SOURCE=.\Simulation\GUISim.lib
# End Source File
# End Group
# End Target
# End Project
