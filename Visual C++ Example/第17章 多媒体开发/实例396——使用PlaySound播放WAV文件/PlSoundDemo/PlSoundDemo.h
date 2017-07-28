// PlSoundDemo.h : main header file for the PLSOUNDDEMO application
//

#if !defined(AFX_PLSOUNDDEMO_H__78137008_5373_4006_810C_2D132133A062__INCLUDED_)
#define AFX_PLSOUNDDEMO_H__78137008_5373_4006_810C_2D132133A062__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPlSoundDemoApp:
// See PlSoundDemo.cpp for the implementation of this class
//

class CPlSoundDemoApp : public CWinApp
{
public:
	CPlSoundDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPlSoundDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPlSoundDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PLSOUNDDEMO_H__78137008_5373_4006_810C_2D132133A062__INCLUDED_)
