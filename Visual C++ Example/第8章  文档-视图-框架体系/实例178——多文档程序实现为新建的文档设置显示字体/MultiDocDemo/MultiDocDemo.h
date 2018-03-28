// MultiDocDemo.h : main header file for the MultiDocDemo application
//

#if !defined(AFX_MultiDocDemo_H__766FBBF2_C72B_4DB3_8BB2_1BA325FA943B__INCLUDED_)
#define AFX_MultiDocDemo_H__766FBBF2_C72B_4DB3_8BB2_1BA325FA943B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiDocDemoApp:
// See MultiDocDemo.cpp for the implementation of this class
//

class CMultiDocDemoApp : public CWinApp
{
public:
	CMultiDocDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiDocDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMultiDocDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiDocDemo_H__766FBBF2_C72B_4DB3_8BB2_1BA325FA943B__INCLUDED_)
