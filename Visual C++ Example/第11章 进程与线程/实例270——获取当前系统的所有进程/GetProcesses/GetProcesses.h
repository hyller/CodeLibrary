// GetProcesses.h : main header file for the GETPROCESSES application
//

#if !defined(AFX_GETPROCESSES_H__281AF957_844A_4117_B84C_5E2A7C57D6E0__INCLUDED_)
#define AFX_GETPROCESSES_H__281AF957_844A_4117_B84C_5E2A7C57D6E0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetProcessesApp:
// See GetProcesses.cpp for the implementation of this class
//

class CGetProcessesApp : public CWinApp
{
public:
	CGetProcessesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetProcessesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetProcessesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETPROCESSES_H__281AF957_844A_4117_B84C_5E2A7C57D6E0__INCLUDED_)
