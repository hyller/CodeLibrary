// SelectMunu.h : main header file for the SELECTMUNU application
//

#if !defined(AFX_SELECTMUNU_H__12131DC3_FDB5_4257_A2EA_1C2780B93EB5__INCLUDED_)
#define AFX_SELECTMUNU_H__12131DC3_FDB5_4257_A2EA_1C2780B93EB5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSelectMunuApp:
// See SelectMunu.cpp for the implementation of this class
//

class CSelectMunuApp : public CWinApp
{
public:
	CSelectMunuApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectMunuApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSelectMunuApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTMUNU_H__12131DC3_FDB5_4257_A2EA_1C2780B93EB5__INCLUDED_)
