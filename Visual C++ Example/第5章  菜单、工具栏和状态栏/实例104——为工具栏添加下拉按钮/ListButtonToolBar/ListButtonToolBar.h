// ListButtonToolBar.h : main header file for the LISTBUTTONTOOLBAR application
//

#if !defined(AFX_LISTBUTTONTOOLBAR_H__7F4B67F8_DE2A_4B73_841B_76A0FBB3E108__INCLUDED_)
#define AFX_LISTBUTTONTOOLBAR_H__7F4B67F8_DE2A_4B73_841B_76A0FBB3E108__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CListButtonToolBarApp:
// See ListButtonToolBar.cpp for the implementation of this class
//

class CListButtonToolBarApp : public CWinApp
{
public:
	CListButtonToolBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CListButtonToolBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CListButtonToolBarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LISTBUTTONTOOLBAR_H__7F4B67F8_DE2A_4B73_841B_76A0FBB3E108__INCLUDED_)
