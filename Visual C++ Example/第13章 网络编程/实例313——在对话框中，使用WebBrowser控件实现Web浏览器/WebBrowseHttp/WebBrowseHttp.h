// WebBrowseHttp.h : main header file for the WebBrowseHttp application
//

#if !defined(AFX_WebBrowseHttp_H__6FE99649_8A6C_4E17_8198_3CA6B0751208__INCLUDED_)
#define AFX_WebBrowseHttp_H__6FE99649_8A6C_4E17_8198_3CA6B0751208__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CWebBrowseHttpApp:
// See WebBrowseHttp.cpp for the implementation of this class
//

class CWebBrowseHttpApp : public CWinApp
{
public:
	CWebBrowseHttpApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWebBrowseHttpApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CWebBrowseHttpApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WebBrowseHttp_H__6FE99649_8A6C_4E17_8198_3CA6B0751208__INCLUDED_)
