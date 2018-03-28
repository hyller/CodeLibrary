// ColorEditBox.h : main header file for the COLOREDITBOX application
//

#if !defined(AFX_COLOREDITBOX_H__5FCEB93F_1930_464C_B5F5_9DB2BD3C32C7__INCLUDED_)
#define AFX_COLOREDITBOX_H__5FCEB93F_1930_464C_B5F5_9DB2BD3C32C7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorEditBoxApp:
// See ColorEditBox.cpp for the implementation of this class
//

class CColorEditBoxApp : public CWinApp
{
public:
	CColorEditBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorEditBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColorEditBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLOREDITBOX_H__5FCEB93F_1930_464C_B5F5_9DB2BD3C32C7__INCLUDED_)
