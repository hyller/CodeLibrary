// DlgKeyMessage.h : main header file for the DLGKEYMESSAGE application
//

#if !defined(AFX_DLGKEYMESSAGE_H__A1DC9C71_3230_47B2_8205_B3B94BE5DC3E__INCLUDED_)
#define AFX_DLGKEYMESSAGE_H__A1DC9C71_3230_47B2_8205_B3B94BE5DC3E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgKeyMessageApp:
// See DlgKeyMessage.cpp for the implementation of this class
//

class CDlgKeyMessageApp : public CWinApp
{
public:
	CDlgKeyMessageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgKeyMessageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgKeyMessageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGKEYMESSAGE_H__A1DC9C71_3230_47B2_8205_B3B94BE5DC3E__INCLUDED_)
