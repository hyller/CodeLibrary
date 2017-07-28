// BaseRichEdit.h : main header file for the BASERICHEDIT application
//

#if !defined(AFX_BASERICHEDIT_H__2FE996C4_E35E_4CA6_8CEA_8507CC164528__INCLUDED_)
#define AFX_BASERICHEDIT_H__2FE996C4_E35E_4CA6_8CEA_8507CC164528__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseRichEditApp:
// See BaseRichEdit.cpp for the implementation of this class
//

class CBaseRichEditApp : public CWinApp
{
public:
	CBaseRichEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseRichEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBaseRichEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASERICHEDIT_H__2FE996C4_E35E_4CA6_8CEA_8507CC164528__INCLUDED_)
