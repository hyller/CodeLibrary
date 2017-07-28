// CreateShortCut.h : main header file for the CREATESHORTCUT application
//

#if !defined(AFX_CREATESHORTCUT_H__B135C1A7_6FC2_4424_81BF_A20A4268A6CB__INCLUDED_)
#define AFX_CREATESHORTCUT_H__B135C1A7_6FC2_4424_81BF_A20A4268A6CB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateShortCutApp:
// See CreateShortCut.cpp for the implementation of this class
//

class CCreateShortCutApp : public CWinApp
{
public:
	CCreateShortCutApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateShortCutApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateShortCutApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATESHORTCUT_H__B135C1A7_6FC2_4424_81BF_A20A4268A6CB__INCLUDED_)
