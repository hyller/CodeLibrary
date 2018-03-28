// UseMagicBox.h : main header file for the USEMAGICBOX application
//

#if !defined(AFX_USEMAGICBOX_H__4212C80C_A84B_4DC4_B64E_3D18CB27C571__INCLUDED_)
#define AFX_USEMAGICBOX_H__4212C80C_A84B_4DC4_B64E_3D18CB27C571__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseMagicBoxApp:
// See UseMagicBox.cpp for the implementation of this class
//

class CUseMagicBoxApp : public CWinApp
{
public:
	CUseMagicBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseMagicBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseMagicBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEMAGICBOX_H__4212C80C_A84B_4DC4_B64E_3D18CB27C571__INCLUDED_)
