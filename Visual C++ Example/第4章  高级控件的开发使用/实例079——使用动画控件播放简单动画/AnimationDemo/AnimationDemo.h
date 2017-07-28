// AnimationDemo.h : main header file for the ANIMATIONDEMO application
//

#if !defined(AFX_ANIMATIONDEMO_H__819A208C_2A26_45E5_B769_BD8602437F87__INCLUDED_)
#define AFX_ANIMATIONDEMO_H__819A208C_2A26_45E5_B769_BD8602437F87__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAnimationDemoApp:
// See AnimationDemo.cpp for the implementation of this class
//

class CAnimationDemoApp : public CWinApp
{
public:
	CAnimationDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAnimationDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAnimationDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ANIMATIONDEMO_H__819A208C_2A26_45E5_B769_BD8602437F87__INCLUDED_)
