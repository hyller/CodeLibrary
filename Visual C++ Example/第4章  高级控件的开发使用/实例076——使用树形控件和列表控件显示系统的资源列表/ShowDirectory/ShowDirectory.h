// ShowDirectory.h : main header file for the SHOWDIRECTORY application
//

#if !defined(AFX_SHOWDIRECTORY_H__2F249643_BDC0_4102_BF19_9BDA406AB816__INCLUDED_)
#define AFX_SHOWDIRECTORY_H__2F249643_BDC0_4102_BF19_9BDA406AB816__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowDirectoryApp:
// See ShowDirectory.cpp for the implementation of this class
//

class CShowDirectoryApp : public CWinApp
{
public:
	CShowDirectoryApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowDirectoryApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CShowDirectoryApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWDIRECTORY_H__2F249643_BDC0_4102_BF19_9BDA406AB816__INCLUDED_)
