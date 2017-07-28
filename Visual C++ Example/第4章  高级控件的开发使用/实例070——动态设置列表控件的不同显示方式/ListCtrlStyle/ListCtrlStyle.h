// ListCtrlStyle.h : main header file for the ListCtrlStyle application
//

#if !defined(AFX_ListCtrlStyle_H__440FD8D9_95E2_48C3_9048_13387BCE4306__INCLUDED_)
#define AFX_ListCtrlStyle_H__440FD8D9_95E2_48C3_9048_13387BCE4306__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CListCtrlStyleApp:
// See ListCtrlStyle.cpp for the implementation of this class
//

class CListCtrlStyleApp : public CWinApp
{
public:
	CListCtrlStyleApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListCtrlStyleApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CListCtrlStyleApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ListCtrlStyle_H__440FD8D9_95E2_48C3_9048_13387BCE4306__INCLUDED_)
