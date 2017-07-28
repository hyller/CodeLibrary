// ShowChangeFBL.h : main header file for the SHOWCHANGEFBL application
//

#if !defined(AFX_SHOWCHANGEFBL_H__07424ED3_CD1B_4460_BB71_A9E2E9156BD3__INCLUDED_)
#define AFX_SHOWCHANGEFBL_H__07424ED3_CD1B_4460_BB71_A9E2E9156BD3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowChangeFBLApp:
// See ShowChangeFBL.cpp for the implementation of this class
//

class CShowChangeFBLApp : public CWinApp
{
public:
	CShowChangeFBLApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowChangeFBLApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowChangeFBLApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWCHANGEFBL_H__07424ED3_CD1B_4460_BB71_A9E2E9156BD3__INCLUDED_)
