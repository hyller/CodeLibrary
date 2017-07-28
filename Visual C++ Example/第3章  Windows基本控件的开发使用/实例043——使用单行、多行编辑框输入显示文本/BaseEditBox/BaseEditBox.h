// BaseEditBox.h : main header file for the BASEEDITBOX application
//

#if !defined(AFX_BASEEDITBOX_H__A844DF6F_E873_4E2B_8B73_AF17E4FB4F9C__INCLUDED_)
#define AFX_BASEEDITBOX_H__A844DF6F_E873_4E2B_8B73_AF17E4FB4F9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseEditBoxApp:
// See BaseEditBox.cpp for the implementation of this class
//

class CBaseEditBoxApp : public CWinApp
{
public:
	CBaseEditBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseEditBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBaseEditBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEEDITBOX_H__A844DF6F_E873_4E2B_8B73_AF17E4FB4F9C__INCLUDED_)
