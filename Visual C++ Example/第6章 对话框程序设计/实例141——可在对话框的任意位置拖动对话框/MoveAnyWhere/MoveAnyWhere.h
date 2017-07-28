// MoveAnyWhere.h : main header file for the MOVEANYWHERE application
//

#if !defined(AFX_MOVEANYWHERE_H__F9A60F55_12B7_48C0_B3AA_80D1A9FBE18A__INCLUDED_)
#define AFX_MOVEANYWHERE_H__F9A60F55_12B7_48C0_B3AA_80D1A9FBE18A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMoveAnyWhereApp:
// See MoveAnyWhere.cpp for the implementation of this class
//

class CMoveAnyWhereApp : public CWinApp
{
public:
	CMoveAnyWhereApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveAnyWhereApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMoveAnyWhereApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVEANYWHERE_H__F9A60F55_12B7_48C0_B3AA_80D1A9FBE18A__INCLUDED_)
