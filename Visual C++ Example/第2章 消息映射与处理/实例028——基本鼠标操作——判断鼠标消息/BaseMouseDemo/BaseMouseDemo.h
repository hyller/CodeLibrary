// BaseMouseDemo.h : main header file for the BASEMOUSEDEMO application
//

#if !defined(AFX_BASEMOUSEDEMO_H__F813AAD5_CCEA_440A_8CDB_31B67AB6B979__INCLUDED_)
#define AFX_BASEMOUSEDEMO_H__F813AAD5_CCEA_440A_8CDB_31B67AB6B979__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseMouseDemoApp:
// See BaseMouseDemo.cpp for the implementation of this class
//

class CBaseMouseDemoApp : public CWinApp
{
public:
	CBaseMouseDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseMouseDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaseMouseDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEMOUSEDEMO_H__F813AAD5_CCEA_440A_8CDB_31B67AB6B979__INCLUDED_)
