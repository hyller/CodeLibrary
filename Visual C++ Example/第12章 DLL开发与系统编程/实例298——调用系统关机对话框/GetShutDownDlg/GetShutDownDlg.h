// GetShutDownDlg.h : main header file for the GETSHUTDOWNDLG application
//

#if !defined(AFX_GETSHUTDOWNDLG_H__6DE1BDF8_D4B2_40D3_81F5_0F533375B2B3__INCLUDED_)
#define AFX_GETSHUTDOWNDLG_H__6DE1BDF8_D4B2_40D3_81F5_0F533375B2B3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGetShutDownDlgApp:
// See GetShutDownDlg.cpp for the implementation of this class
//

class CGetShutDownDlgApp : public CWinApp
{
public:
	CGetShutDownDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGetShutDownDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGetShutDownDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GETSHUTDOWNDLG_H__6DE1BDF8_D4B2_40D3_81F5_0F533375B2B3__INCLUDED_)
