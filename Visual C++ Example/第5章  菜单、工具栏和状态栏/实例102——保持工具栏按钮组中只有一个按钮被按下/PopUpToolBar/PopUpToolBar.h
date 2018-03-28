// PopUpToolBar.h : main header file for the PopUpToolBar application
//

#if !defined(AFX_PopUpToolBar_H__E68E8ABE_FCA7_4AFB_A86D_40FEA1F025C9__INCLUDED_)
#define AFX_PopUpToolBar_H__E68E8ABE_FCA7_4AFB_A86D_40FEA1F025C9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPopUpToolBarApp:
// See PopUpToolBar.cpp for the implementation of this class
//

class CPopUpToolBarApp : public CWinApp
{
public:
	CPopUpToolBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopUpToolBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPopUpToolBarApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PopUpToolBar_H__E68E8ABE_FCA7_4AFB_A86D_40FEA1F025C9__INCLUDED_)
