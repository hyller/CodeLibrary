// MultiFileDlgDemo.h : main header file for the MULTIFILEDLGDEMO application
//

#if !defined(AFX_MULTIFILEDLGDEMO_H__E787A235_5740_4C00_84D6_90821327B710__INCLUDED_)
#define AFX_MULTIFILEDLGDEMO_H__E787A235_5740_4C00_84D6_90821327B710__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMultiFileDlgDemoApp:
// See MultiFileDlgDemo.cpp for the implementation of this class
//

class CMultiFileDlgDemoApp : public CWinApp
{
public:
	CMultiFileDlgDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiFileDlgDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMultiFileDlgDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTIFILEDLGDEMO_H__E787A235_5740_4C00_84D6_90821327B710__INCLUDED_)
