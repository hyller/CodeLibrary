// PPServer.h : main header file for the PPServer application
//

#if !defined(AFX_PPServer_H__147F359A_BD74_4498_AE22_968234CF2D50__INCLUDED_)
#define AFX_PPServer_H__147F359A_BD74_4498_AE22_968234CF2D50__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPPServerApp:
// See PPServer.cpp for the implementation of this class
//

class CPPServerApp : public CWinApp
{
public:
	CPPServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPPServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPServer_H__147F359A_BD74_4498_AE22_968234CF2D50__INCLUDED_)
