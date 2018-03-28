// FaceControl1.h : main header file for the FACECONTROL1 application
//

#if !defined(AFX_FACECONTROL1_H__9FE7AB75_4018_4C5E_82D9_409459BD1C37__INCLUDED_)
#define AFX_FACECONTROL1_H__9FE7AB75_4018_4C5E_82D9_409459BD1C37__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CFaceControl1App:
// See FaceControl1.cpp for the implementation of this class
//

class CFaceControl1App : public CWinApp
{
public:
	CFaceControl1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceControl1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CFaceControl1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FACECONTROL1_H__9FE7AB75_4018_4C5E_82D9_409459BD1C37__INCLUDED_)
