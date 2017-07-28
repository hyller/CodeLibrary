// ListViewDemo.h : main header file for the LISTVIEWDEMO application
//

#if !defined(AFX_LISTVIEWDEMO_H__8C1B4A33_11A2_4F37_9EDF_BFA358953F2F__INCLUDED_)
#define AFX_LISTVIEWDEMO_H__8C1B4A33_11A2_4F37_9EDF_BFA358953F2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CListViewDemoApp:
// See ListViewDemo.cpp for the implementation of this class
//

class CListViewDemoApp : public CWinApp
{
public:
	CListViewDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListViewDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CListViewDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTVIEWDEMO_H__8C1B4A33_11A2_4F37_9EDF_BFA358953F2F__INCLUDED_)
