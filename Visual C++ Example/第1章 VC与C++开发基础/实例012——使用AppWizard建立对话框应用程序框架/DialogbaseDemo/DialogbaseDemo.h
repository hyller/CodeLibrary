// DialogbaseDemo.h : main header file for the DIALOGBASEDEMO application
//

#if !defined(AFX_DIALOGBASEDEMO_H__79D20439_7D71_4329_B212_6A163326F6C9__INCLUDED_)
#define AFX_DIALOGBASEDEMO_H__79D20439_7D71_4329_B212_6A163326F6C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogbaseDemoApp:
// See DialogbaseDemo.cpp for the implementation of this class
//

class CDialogbaseDemoApp : public CWinApp
{
public:
	CDialogbaseDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogbaseDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogbaseDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DIALOGBASEDEMO_H__79D20439_7D71_4329_B212_6A163326F6C9__INCLUDED_)
