// RestoreWinPos.h : main header file for the RESTOREWINPOS application
//

#if !defined(AFX_RESTOREWINPOS_H__E51776AB_4FDE_4E86_8447_1FC946E2DB5A__INCLUDED_)
#define AFX_RESTOREWINPOS_H__E51776AB_4FDE_4E86_8447_1FC946E2DB5A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CRestoreWinPosApp:
// See RestoreWinPos.cpp for the implementation of this class
//

class CRestoreWinPosApp : public CWinApp
{
public:
	CRestoreWinPosApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRestoreWinPosApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CRestoreWinPosApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTOREWINPOS_H__E51776AB_4FDE_4E86_8447_1FC946E2DB5A__INCLUDED_)
