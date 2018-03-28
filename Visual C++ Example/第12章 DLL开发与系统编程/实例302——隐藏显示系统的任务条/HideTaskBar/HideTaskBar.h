// HideTaskBar.h : main header file for the HIDETASKBAR application
//

#if !defined(AFX_HIDETASKBAR_H__E69890F1_42AF_4F59_B7CA_618B45FBB0AE__INCLUDED_)
#define AFX_HIDETASKBAR_H__E69890F1_42AF_4F59_B7CA_618B45FBB0AE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHideTaskBarApp:
// See HideTaskBar.cpp for the implementation of this class
//

class CHideTaskBarApp : public CWinApp
{
public:
	CHideTaskBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHideTaskBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHideTaskBarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HIDETASKBAR_H__E69890F1_42AF_4F59_B7CA_618B45FBB0AE__INCLUDED_)
