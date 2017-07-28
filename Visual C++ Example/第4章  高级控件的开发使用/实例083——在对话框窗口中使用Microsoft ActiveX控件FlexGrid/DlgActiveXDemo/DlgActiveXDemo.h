// DlgActiveXDemo.h : main header file for the DLGACTIVEXDEMO application
//

#if !defined(AFX_DLGACTIVEXDEMO_H__BA53794E_FEA8_485F_B080_59E6792AD724__INCLUDED_)
#define AFX_DLGACTIVEXDEMO_H__BA53794E_FEA8_485F_B080_59E6792AD724__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgActiveXDemoApp:
// See DlgActiveXDemo.cpp for the implementation of this class
//

class CDlgActiveXDemoApp : public CWinApp
{
public:
	CDlgActiveXDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgActiveXDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgActiveXDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGACTIVEXDEMO_H__BA53794E_FEA8_485F_B080_59E6792AD724__INCLUDED_)
