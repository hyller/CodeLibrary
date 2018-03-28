// TrayIcon.h : main header file for the TRAYICON application
//

#if !defined(AFX_TRAYICON_H__8A7CC9AE_74DF_422F_B52C_DE9AB24F513B__INCLUDED_)
#define AFX_TRAYICON_H__8A7CC9AE_74DF_422F_B52C_DE9AB24F513B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTrayIconApp:
// See TrayIcon.cpp for the implementation of this class
//

class CTrayIconApp : public CWinApp
{
public:
	CTrayIconApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayIconApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTrayIconApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAYICON_H__8A7CC9AE_74DF_422F_B52C_DE9AB24F513B__INCLUDED_)
