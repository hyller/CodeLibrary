// CheckFileDemo.h : main header file for the CheckFileDemo application
//

#if !defined(AFX_CheckFileDemo_H__CE1E580D_E6F8_428F_861D_DECDE94F7990__INCLUDED_)
#define AFX_CheckFileDemo_H__CE1E580D_E6F8_428F_861D_DECDE94F7990__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCheckFileDemoApp:
// See CheckFileDemo.cpp for the implementation of this class
//

class CCheckFileDemoApp : public CWinApp
{
public:
	CCheckFileDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckFileDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCheckFileDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CheckFileDemo_H__CE1E580D_E6F8_428F_861D_DECDE94F7990__INCLUDED_)
