// LineDDADemo.h : main header file for the LINEDDADEMO application
//

#if !defined(AFX_LINEDDADEMO_H__731850A3_16FB_4C54_8614_CD1DA74D7B52__INCLUDED_)
#define AFX_LINEDDADEMO_H__731850A3_16FB_4C54_8614_CD1DA74D7B52__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CLineDDADemoApp:
// See LineDDADemo.cpp for the implementation of this class
//

class CLineDDADemoApp : public CWinApp
{
public:
	CLineDDADemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineDDADemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CLineDDADemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEDDADEMO_H__731850A3_16FB_4C54_8614_CD1DA74D7B52__INCLUDED_)
