// UseProcedure.h : main header file for the USEPROCEDURE application
//

#if !defined(AFX_USEPROCEDURE_H__DD0FD0AB_E244_464E_BEFA_F102F930BD2C__INCLUDED_)
#define AFX_USEPROCEDURE_H__DD0FD0AB_E244_464E_BEFA_F102F930BD2C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseProcedureApp:
// See UseProcedure.cpp for the implementation of this class
//

class CUseProcedureApp : public CWinApp
{
public:
	CUseProcedureApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseProcedureApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseProcedureApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEPROCEDURE_H__DD0FD0AB_E244_464E_BEFA_F102F930BD2C__INCLUDED_)
