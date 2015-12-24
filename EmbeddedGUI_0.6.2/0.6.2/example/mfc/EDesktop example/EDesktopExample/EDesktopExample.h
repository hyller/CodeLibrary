// EDesktopExample.h : main header file for the EDesktopExample application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols
#include <gdiplus.h>
using namespace Gdiplus;


// CEDesktopExampleApp:
// See EDesktopExample.cpp for the implementation of this class
//

class CEDesktopExampleApp : public CWinApp
{
public:
	CEDesktopExampleApp();
	~CEDesktopExampleApp(){
		GdiplusShutdown(gdiplusToken);			
	}

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()

	GdiplusStartupInput gps;
	ULONG_PTR           gdiplusToken;
};

extern CEDesktopExampleApp theApp;