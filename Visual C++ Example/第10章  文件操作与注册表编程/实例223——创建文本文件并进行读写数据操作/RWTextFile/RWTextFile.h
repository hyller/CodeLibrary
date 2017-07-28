// RWTextFile.h : main header file for the RWTEXTFILE application
//

#if !defined(AFX_RWTEXTFILE_H__2DB2F9AF_D663_4FEA_ACC8_96A59D1AB485__INCLUDED_)
#define AFX_RWTEXTFILE_H__2DB2F9AF_D663_4FEA_ACC8_96A59D1AB485__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CRWTextFileApp:
// See RWTextFile.cpp for the implementation of this class
//

class CRWTextFileApp : public CWinApp
{
public:
	CRWTextFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRWTextFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CRWTextFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RWTEXTFILE_H__2DB2F9AF_D663_4FEA_ACC8_96A59D1AB485__INCLUDED_)
