// PropertySheetDemo3.h : main header file for the PropertySheetDemo3 application
//

#if !defined(AFX_PropertySheetDemo3_H__39683043_CCE1_4BA7_918B_CB90E602308A__INCLUDED_)
#define AFX_PropertySheetDemo3_H__39683043_CCE1_4BA7_918B_CB90E602308A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CPropertySheetDemo3App:
// See PropertySheetDemo3.cpp for the implementation of this class
//

class CPropertySheetDemo3App : public CWinApp
{
public:
	CPropertySheetDemo3App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheetDemo3App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPropertySheetDemo3App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PropertySheetDemo3_H__39683043_CCE1_4BA7_918B_CB90E602308A__INCLUDED_)
