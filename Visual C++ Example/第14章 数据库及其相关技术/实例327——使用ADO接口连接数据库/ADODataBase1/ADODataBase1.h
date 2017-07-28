// ADODataBase1.h : main header file for the ADODATABASE1 application
//

#if !defined(AFX_ADODATABASE1_H__FC4928AC_5816_43DC_A676_773E3CCD20DD__INCLUDED_)
#define AFX_ADODATABASE1_H__FC4928AC_5816_43DC_A676_773E3CCD20DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADODataBase1App:
// See ADODataBase1.cpp for the implementation of this class
//

class CADODataBase1App : public CWinApp
{
public:
	CADODataBase1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataBase1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADODataBase1App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATABASE1_H__FC4928AC_5816_43DC_A676_773E3CCD20DD__INCLUDED_)
