// NoFileSizedMDI.h : main header file for the NOFILESIZEDMDI application
//

#if !defined(AFX_NOFILESIZEDMDI_H__55B9A6C8_9A7F_4DF3_BC70_8B9598328CCE__INCLUDED_)
#define AFX_NOFILESIZEDMDI_H__55B9A6C8_9A7F_4DF3_BC70_8B9598328CCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CNoFileSizedMDIApp:
// See NoFileSizedMDI.cpp for the implementation of this class
//

class CNoFileSizedMDIApp : public CWinApp
{
public:
	CNoFileSizedMDIApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoFileSizedMDIApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CNoFileSizedMDIApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOFILESIZEDMDI_H__55B9A6C8_9A7F_4DF3_BC70_8B9598328CCE__INCLUDED_)
