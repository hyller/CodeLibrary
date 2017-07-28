// ThreadPriority.h : main header file for the THREADPRIORITY application
//

#if !defined(AFX_THREADPRIORITY_H__7EDEDC6A_8930_413B_AE30_4B8EA92D9A85__INCLUDED_)
#define AFX_THREADPRIORITY_H__7EDEDC6A_8930_413B_AE30_4B8EA92D9A85__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CThreadPriorityApp:
// See ThreadPriority.cpp for the implementation of this class
//

class CThreadPriorityApp : public CWinApp
{
public:
	CThreadPriorityApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CThreadPriorityApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CThreadPriorityApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_THREADPRIORITY_H__7EDEDC6A_8930_413B_AE30_4B8EA92D9A85__INCLUDED_)
