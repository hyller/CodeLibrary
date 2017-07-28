// OnlyOneInst.h : main header file for the ONLYONEINST application
//

#if !defined(AFX_ONLYONEINST_H__C0A4EC85_66C6_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_ONLYONEINST_H__C0A4EC85_66C6_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COnlyOneInstApp:
// See OnlyOneInst.cpp for the implementation of this class
//

class COnlyOneInstApp : public CWinApp
{
protected:
	BOOL FirstInstance();
public:
	COnlyOneInstApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COnlyOneInstApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COnlyOneInstApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ONLYONEINST_H__C0A4EC85_66C6_11D6_8F32_00E04CE76240__INCLUDED_)
