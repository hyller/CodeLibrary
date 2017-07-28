// StarOtherPro.h : main header file for the STAROTHERPRO application
//

#if !defined(AFX_STAROTHERPRO_H__5222D7DC_6BF1_480B_B4D2_B9DE978F480A__INCLUDED_)
#define AFX_STAROTHERPRO_H__5222D7DC_6BF1_480B_B4D2_B9DE978F480A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStarOtherProApp:
// See StarOtherPro.cpp for the implementation of this class
//

class CStarOtherProApp : public CWinApp
{
public:
	CStarOtherProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarOtherProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStarOtherProApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STAROTHERPRO_H__5222D7DC_6BF1_480B_B4D2_B9DE978F480A__INCLUDED_)
