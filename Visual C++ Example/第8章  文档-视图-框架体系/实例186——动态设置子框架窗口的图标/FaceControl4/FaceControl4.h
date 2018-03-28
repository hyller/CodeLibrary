// FaceControl4.h : main header file for the FaceControl4 application
//

#if !defined(AFX_FaceControl4_H__9FE7AB75_4018_4C5E_82D9_409459BD1C37__INCLUDED_)
#define AFX_FaceControl4_H__9FE7AB75_4018_4C5E_82D9_409459BD1C37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFaceControl4App:
// See FaceControl4.cpp for the implementation of this class
//

class CFaceControl4App : public CWinApp
{
public:
	CFaceControl4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceControl4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFaceControl4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FaceControl4_H__9FE7AB75_4018_4C5E_82D9_409459BD1C37__INCLUDED_)
