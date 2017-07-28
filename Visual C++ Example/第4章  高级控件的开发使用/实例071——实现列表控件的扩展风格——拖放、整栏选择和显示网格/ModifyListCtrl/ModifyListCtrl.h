// ModifyListCtrl.h : main header file for the ModifyListCtrl application
//

#if !defined(AFX_ModifyListCtrl_H__440FD8D9_95E2_48C3_9048_13387BCE4306__INCLUDED_)
#define AFX_ModifyListCtrl_H__440FD8D9_95E2_48C3_9048_13387BCE4306__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CModifyListCtrlApp:
// See ModifyListCtrl.cpp for the implementation of this class
//

class CModifyListCtrlApp : public CWinApp
{
public:
	CModifyListCtrlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CModifyListCtrlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CModifyListCtrlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ModifyListCtrl_H__440FD8D9_95E2_48C3_9048_13387BCE4306__INCLUDED_)
