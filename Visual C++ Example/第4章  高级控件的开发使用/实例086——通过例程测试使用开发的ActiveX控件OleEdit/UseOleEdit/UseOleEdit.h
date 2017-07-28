// UseOleEdit.h : main header file for the USEOLEEDIT application
//

#if !defined(AFX_USEOLEEDIT_H__ED31171E_06EF_4A26_BCA8_51FD602EED9D__INCLUDED_)
#define AFX_USEOLEEDIT_H__ED31171E_06EF_4A26_BCA8_51FD602EED9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseOleEditApp:
// See UseOleEdit.cpp for the implementation of this class
//

class CUseOleEditApp : public CWinApp
{
public:
	CUseOleEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseOleEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseOleEditApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEOLEEDIT_H__ED31171E_06EF_4A26_BCA8_51FD602EED9D__INCLUDED_)
