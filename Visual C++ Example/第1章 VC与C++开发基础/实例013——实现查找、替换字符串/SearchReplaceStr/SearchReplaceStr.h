// SearchReplaceStr.h : main header file for the SEARCHREPLACESTR application
//

#if !defined(AFX_SEARCHREPLACESTR_H__BFE53C46_733A_4C8A_A514_CFA8B2F83022__INCLUDED_)
#define AFX_SEARCHREPLACESTR_H__BFE53C46_733A_4C8A_A514_CFA8B2F83022__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSearchReplaceStrApp:
// See SearchReplaceStr.cpp for the implementation of this class
//

class CSearchReplaceStrApp : public CWinApp
{
public:
	CSearchReplaceStrApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchReplaceStrApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSearchReplaceStrApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHREPLACESTR_H__BFE53C46_733A_4C8A_A514_CFA8B2F83022__INCLUDED_)
