// CursorMouseDemo.h : main header file for the CURSORMOUSEDEMO application
//

#if !defined(AFX_CURSORMOUSEDEMO_H__FD4572A3_5F67_4B28_A5CC_999D771C322C__INCLUDED_)
#define AFX_CURSORMOUSEDEMO_H__FD4572A3_5F67_4B28_A5CC_999D771C322C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCursorMouseDemoApp:
// See CursorMouseDemo.cpp for the implementation of this class
//

class CCursorMouseDemoApp : public CWinApp
{
public:
	CCursorMouseDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCursorMouseDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CCursorMouseDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CURSORMOUSEDEMO_H__FD4572A3_5F67_4B28_A5CC_999D771C322C__INCLUDED_)
