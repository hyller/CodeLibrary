// SearchFile.h : main header file for the SearchFile application
//

#if !defined(AFX_SearchFile_H__166409DA_9051_4D70_A0DD_B0F78E454E49__INCLUDED_)
#define AFX_SearchFile_H__166409DA_9051_4D70_A0DD_B0F78E454E49__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSearchFileApp:
// See SearchFile.cpp for the implementation of this class
//

class CSearchFileApp : public CWinApp
{
public:
	CSearchFileApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchFileApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSearchFileApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SearchFile_H__166409DA_9051_4D70_A0DD_B0F78E454E49__INCLUDED_)
