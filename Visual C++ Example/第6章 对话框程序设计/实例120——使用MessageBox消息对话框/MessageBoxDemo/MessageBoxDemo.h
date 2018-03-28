// MessageBoxDemo.h : main header file for the MESSAGEBOXDEMO application
//

#if !defined(AFX_MESSAGEBOXDEMO_H__246FD3DE_7C8F_4CED_9A84_CE1D2550053C__INCLUDED_)
#define AFX_MESSAGEBOXDEMO_H__246FD3DE_7C8F_4CED_9A84_CE1D2550053C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMessageBoxDemoApp:
// See MessageBoxDemo.cpp for the implementation of this class
//

class CMessageBoxDemoApp : public CWinApp
{
public:
	CMessageBoxDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMessageBoxDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMessageBoxDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MESSAGEBOXDEMO_H__246FD3DE_7C8F_4CED_9A84_CE1D2550053C__INCLUDED_)
