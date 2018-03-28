// TextButtonTool.h : main header file for the TextButtonTool application
//

#if !defined(AFX_TextButtonTool_H__1F261D45_ABCB_11D5_8C1B_CC1A6D330B6E__INCLUDED_)
#define AFX_TextButtonTool_H__1F261D45_ABCB_11D5_8C1B_CC1A6D330B6E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTextButtonToolApp:
// See TextButtonTool.cpp for the implementation of this class
//

class CTextButtonToolApp : public CWinApp
{
public:
	CTextButtonToolApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTextButtonToolApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTextButtonToolApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TextButtonTool_H__1F261D45_ABCB_11D5_8C1B_CC1A6D330B6E__INCLUDED_)
