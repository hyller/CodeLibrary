// MutexProcessSyn.h : main header file for the MutexProcessSyn application
//

#if !defined(AFX_MutexProcessSyn_H__4F166E73_3ED0_4AE7_B9F0_7A76A4A79D47__INCLUDED_)
#define AFX_MutexProcessSyn_H__4F166E73_3ED0_4AE7_B9F0_7A76A4A79D47__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMutexProcessSynApp:
// See MutexProcessSyn.cpp for the implementation of this class
//

class CMutexProcessSynApp : public CWinApp
{
public:
	CMutexProcessSynApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMutexProcessSynApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMutexProcessSynApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MutexProcessSyn_H__4F166E73_3ED0_4AE7_B9F0_7A76A4A79D47__INCLUDED_)
