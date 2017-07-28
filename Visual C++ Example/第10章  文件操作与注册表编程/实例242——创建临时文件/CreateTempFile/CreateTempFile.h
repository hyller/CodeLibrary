// CreateTempFile.h : main header file for the CREATETEMPFILE application
//

#if !defined(AFX_CREATETEMPFILE_H__00813534_529E_4BE9_B40E_D8880D516E91__INCLUDED_)
#define AFX_CREATETEMPFILE_H__00813534_529E_4BE9_B40E_D8880D516E91__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateTempFileApp:
// See CreateTempFile.cpp for the implementation of this class
//

class CCreateTempFileApp : public CWinApp
{
public:
	CCreateTempFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateTempFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateTempFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATETEMPFILE_H__00813534_529E_4BE9_B40E_D8880D516E91__INCLUDED_)
