// CheckDragListBox.h : main header file for the CHECKDRAGLISTBOX application
//

#if !defined(AFX_CHECKDRAGLISTBOX_H__88D028C5_85EC_4367_B91E_900035EA789D__INCLUDED_)
#define AFX_CHECKDRAGLISTBOX_H__88D028C5_85EC_4367_B91E_900035EA789D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCheckDragListBoxApp:
// See CheckDragListBox.cpp for the implementation of this class
//

class CCheckDragListBoxApp : public CWinApp
{
public:
	CCheckDragListBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCheckDragListBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCheckDragListBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHECKDRAGLISTBOX_H__88D028C5_85EC_4367_B91E_900035EA789D__INCLUDED_)
