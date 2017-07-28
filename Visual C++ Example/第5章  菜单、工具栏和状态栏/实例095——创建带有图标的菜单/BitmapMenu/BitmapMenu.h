// BitmapMenu.h : main header file for the BITMAPMENU application
//

#if !defined(AFX_BITMAPMENU_H__EFAB44A8_91CA_4A7A_A022_6ECD48376583__INCLUDED_)
#define AFX_BITMAPMENU_H__EFAB44A8_91CA_4A7A_A022_6ECD48376583__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitmapMenuApp:
// See BitmapMenu.cpp for the implementation of this class
//

class CBitmapMenuApp : public CWinApp
{
public:
	CBitmapMenuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapMenuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBitmapMenuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPMENU_H__EFAB44A8_91CA_4A7A_A022_6ECD48376583__INCLUDED_)
