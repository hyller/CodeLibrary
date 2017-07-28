// MedicAdmin.h : main header file for the MEDICADMIN application
//

#if !defined(AFX_MEDICADMIN_H__6901C17A_5705_457A_907E_3EC513ABD59D__INCLUDED_)
#define AFX_MEDICADMIN_H__6901C17A_5705_457A_907E_3EC513ABD59D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMedicAdminApp:
// See MedicAdmin.cpp for the implementation of this class
//

class CMedicAdminApp : public CWinApp
{
public:
	CMedicAdminApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedicAdminApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMedicAdminApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDICADMIN_H__6901C17A_5705_457A_907E_3EC513ABD59D__INCLUDED_)
