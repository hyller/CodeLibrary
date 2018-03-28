// OperateFile.h : main header file for the OPERATEFILE application
//

#if !defined(AFX_OPERATEFILE_H__0C6B2438_0306_4B72_A49F_D53826AC3253__INCLUDED_)
#define AFX_OPERATEFILE_H__0C6B2438_0306_4B72_A49F_D53826AC3253__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COperateFileApp:
// See OperateFile.cpp for the implementation of this class
//

class COperateFileApp : public CWinApp
{
public:
	COperateFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperateFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COperateFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATEFILE_H__0C6B2438_0306_4B72_A49F_D53826AC3253__INCLUDED_)
