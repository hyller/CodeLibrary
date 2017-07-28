// DialogToolBar.h : main header file for the DialogToolBar application
//

#if !defined(AFX_DialogToolBar_H__54855478_6761_4821_924D_1060A33D65C2__INCLUDED_)
#define AFX_DialogToolBar_H__54855478_6761_4821_924D_1060A33D65C2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDialogToolBarApp:
// See DialogToolBar.cpp for the implementation of this class
//

class CDialogToolBarApp : public CWinApp
{
public:
	CDialogToolBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDialogToolBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDialogToolBarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DialogToolBar_H__54855478_6761_4821_924D_1060A33D65C2__INCLUDED_)
