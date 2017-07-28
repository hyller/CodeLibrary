// CriticalSecitonThreadSyn.h : main header file for the CriticalSecitonThreadSyn application
//

#if !defined(AFX_CriticalSecitonThreadSyn_H__D2BF913C_FD16_4E82_A87E_541D437EDA05__INCLUDED_)
#define AFX_CriticalSecitonThreadSyn_H__D2BF913C_FD16_4E82_A87E_541D437EDA05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCriticalSecitonThreadSynApp:
// See CriticalSecitonThreadSyn.cpp for the implementation of this class
//

class CCriticalSecitonThreadSynApp : public CWinApp
{
public:
	CCriticalSecitonThreadSynApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCriticalSecitonThreadSynApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCriticalSecitonThreadSynApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CriticalSecitonThreadSyn_H__D2BF913C_FD16_4E82_A87E_541D437EDA05__INCLUDED_)
