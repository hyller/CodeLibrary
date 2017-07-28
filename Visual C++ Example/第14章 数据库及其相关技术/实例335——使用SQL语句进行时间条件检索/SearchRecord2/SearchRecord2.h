// SearchRecord2.h : main header file for the SearchRecord2 application
//

#if !defined(AFX_SearchRecord2_H__FBB8BA71_85A1_429C_83D5_28DCF2C1F4CC__INCLUDED_)
#define AFX_SearchRecord2_H__FBB8BA71_85A1_429C_83D5_28DCF2C1F4CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSearchRecord2App:
// See SearchRecord2.cpp for the implementation of this class
//

class CSearchRecord2App : public CWinApp
{
public:
	CSearchRecord2App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchRecord2App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSearchRecord2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SearchRecord2_H__FBB8BA71_85A1_429C_83D5_28DCF2C1F4CC__INCLUDED_)
