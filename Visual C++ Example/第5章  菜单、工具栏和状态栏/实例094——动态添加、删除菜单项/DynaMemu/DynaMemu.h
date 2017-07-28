// DynaMemu.h : main header file for the DYNAMEMU application
//

#if !defined(AFX_DYNAMEMU_H__C8754A33_9033_41C6_992F_2C6A7D0A5926__INCLUDED_)
#define AFX_DYNAMEMU_H__C8754A33_9033_41C6_992F_2C6A7D0A5926__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDynaMemuApp:
// See DynaMemu.cpp for the implementation of this class
//

class CDynaMemuApp : public CWinApp
{
public:
	CDynaMemuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynaMemuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDynaMemuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMEMU_H__C8754A33_9033_41C6_992F_2C6A7D0A5926__INCLUDED_)
