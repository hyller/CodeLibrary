// EnumRegValue.h : main header file for the ENUMREGVALUE application
//

#if !defined(AFX_ENUMREGVALUE_H__2C47A12D_9F7F_486E_B390_0A7FB768E636__INCLUDED_)
#define AFX_ENUMREGVALUE_H__2C47A12D_9F7F_486E_B390_0A7FB768E636__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumRegValueApp:
// See EnumRegValue.cpp for the implementation of this class
//

class CEnumRegValueApp : public CWinApp
{
public:
	CEnumRegValueApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumRegValueApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnumRegValueApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMREGVALUE_H__2C47A12D_9F7F_486E_B390_0A7FB768E636__INCLUDED_)
