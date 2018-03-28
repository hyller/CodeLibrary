// MilliSecondDemo.h : main header file for the MILLISECONDDEMO application
//

#if !defined(AFX_MILLISECONDDEMO_H__622FE386_0D2C_403E_BF89_2F13E7F0C662__INCLUDED_)
#define AFX_MILLISECONDDEMO_H__622FE386_0D2C_403E_BF89_2F13E7F0C662__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMilliSecondDemoApp:
// See MilliSecondDemo.cpp for the implementation of this class
//

class CMilliSecondDemoApp : public CWinApp
{
public:
	CMilliSecondDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMilliSecondDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMilliSecondDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MILLISECONDDEMO_H__622FE386_0D2C_403E_BF89_2F13E7F0C662__INCLUDED_)
