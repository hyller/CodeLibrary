// CreateDestroyProcess.h : main header file for the CreateDestroyProcess application
//

#if !defined(AFX_CreateDestroyProcess_H__E9E53888_6F62_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_CreateDestroyProcess_H__E9E53888_6F62_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateDestroyProcessApp:
// See CreateDestroyProcess.cpp for the implementation of this class
//

class CCreateDestroyProcessApp : public CWinApp
{
public:
	CCreateDestroyProcessApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDestroyProcessApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateDestroyProcessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CreateDestroyProcess_H__E9E53888_6F62_11D6_8F32_00E04CE76240__INCLUDED_)
