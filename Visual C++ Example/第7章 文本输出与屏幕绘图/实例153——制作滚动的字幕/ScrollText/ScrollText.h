// ScrollText.h : main header file for the SCROLLTEXT application
//

#if !defined(AFX_SCROLLTEXT_H__BC808995_2586_4720_BC2E_0516675E65C5__INCLUDED_)
#define AFX_SCROLLTEXT_H__BC808995_2586_4720_BC2E_0516675E65C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CScrollTextApp:
// See ScrollText.cpp for the implementation of this class
//

class CScrollTextApp : public CWinApp
{
public:
	CScrollTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CScrollTextApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLTEXT_H__BC808995_2586_4720_BC2E_0516675E65C5__INCLUDED_)
