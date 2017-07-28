// ADODataBase3.h : main header file for the ADODataBase3 application
//

#if !defined(AFX_ADODataBase3_H__FC4928AC_5816_43DC_A676_773E3CCD20DD__INCLUDED_)
#define AFX_ADODataBase3_H__FC4928AC_5816_43DC_A676_773E3CCD20DD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADODataBase3App:
// See ADODataBase3.cpp for the implementation of this class
//

class CADODataBase3App : public CWinApp
{
public:
	CADODataBase3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataBase3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADODataBase3App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODataBase3_H__FC4928AC_5816_43DC_A676_773E3CCD20DD__INCLUDED_)
