// EventThread.h : main header file for the EventThread application
//

#if !defined(AFX_EventThread_H__F05BA935_D271_4E83_B850_B92CF826E070__INCLUDED_)
#define AFX_EventThread_H__F05BA935_D271_4E83_B850_B92CF826E070__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEventThreadApp:
// See EventThread.cpp for the implementation of this class
//

class CEventThreadApp : public CWinApp
{
public:
	CEventThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEventThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEventThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EventThread_H__F05BA935_D271_4E83_B850_B92CF826E070__INCLUDED_)
