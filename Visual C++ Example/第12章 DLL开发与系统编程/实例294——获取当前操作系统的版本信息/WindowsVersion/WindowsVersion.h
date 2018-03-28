// WindowsVersion.h : main header file for the WINDOWSVERSION application
//

#if !defined(AFX_WINDOWSVERSION_H__2B931772_4508_473A_A8E5_749575A97472__INCLUDED_)
#define AFX_WINDOWSVERSION_H__2B931772_4508_473A_A8E5_749575A97472__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWindowsVersionApp:
// See WindowsVersion.cpp for the implementation of this class
//

class CWindowsVersionApp : public CWinApp
{
public:
	CWindowsVersionApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWindowsVersionApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWindowsVersionApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WINDOWSVERSION_H__2B931772_4508_473A_A8E5_749575A97472__INCLUDED_)
