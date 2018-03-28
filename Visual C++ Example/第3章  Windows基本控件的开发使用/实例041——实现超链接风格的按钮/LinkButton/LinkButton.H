// LinkButton.h : main header file for the LinkButton application
//

#if !defined(AFX_LinkButton_H__869D2008_E3FB_4D98_ABBD_8E86962107D0__INCLUDED_)
#define AFX_LinkButton_H__869D2008_E3FB_4D98_ABBD_8E86962107D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLinkButtonApp:
// See LinkButton.cpp for the implementation of this class
//

class CLinkButtonApp : public CWinApp
{
public:
	CLinkButtonApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkButtonApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLinkButtonApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LinkButton_H__869D2008_E3FB_4D98_ABBD_8E86962107D0__INCLUDED_)
