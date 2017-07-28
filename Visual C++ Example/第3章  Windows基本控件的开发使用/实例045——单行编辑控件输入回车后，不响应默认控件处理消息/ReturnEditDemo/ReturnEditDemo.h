// ReturnEditDemo.h : main header file for the RETURNEDITDEMO application
//

#if !defined(AFX_RETURNEDITDEMO_H__9611BDB1_F541_48B5_AB6E_3C251D9305A8__INCLUDED_)
#define AFX_RETURNEDITDEMO_H__9611BDB1_F541_48B5_AB6E_3C251D9305A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CReturnEditDemoApp:
// See ReturnEditDemo.cpp for the implementation of this class
//

class CReturnEditDemoApp : public CWinApp
{
public:
	CReturnEditDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReturnEditDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CReturnEditDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RETURNEDITDEMO_H__9611BDB1_F541_48B5_AB6E_3C251D9305A8__INCLUDED_)
