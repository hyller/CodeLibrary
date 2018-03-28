// StarFaceDemo.h : main header file for the STARFACEDEMO application
//

#if !defined(AFX_STARFACEDEMO_H__6A875B60_07C1_41C1_B850_F055A6F2604B__INCLUDED_)
#define AFX_STARFACEDEMO_H__6A875B60_07C1_41C1_B850_F055A6F2604B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CStarFaceDemoApp:
// See StarFaceDemo.cpp for the implementation of this class
//

class CStarFaceDemoApp : public CWinApp
{
public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	CStarFaceDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarFaceDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CStarFaceDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARFACEDEMO_H__6A875B60_07C1_41C1_B850_F055A6F2604B__INCLUDED_)
