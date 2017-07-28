// PtrList.h : main header file for the PtrList application
//

#if !defined(AFX_PtrList_H__BCC007E6_FF98_444C_8EE3_FB04389A94A4__INCLUDED_)
#define AFX_PtrList_H__BCC007E6_FF98_444C_8EE3_FB04389A94A4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPtrListApp:
// See PtrList.cpp for the implementation of this class
//

class CPtrListApp : public CWinApp
{
public:
	CPtrListApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPtrListApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPtrListApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PtrList_H__BCC007E6_FF98_444C_8EE3_FB04389A94A4__INCLUDED_)
