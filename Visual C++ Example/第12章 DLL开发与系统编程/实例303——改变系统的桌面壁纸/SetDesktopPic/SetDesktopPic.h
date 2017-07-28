// SetDesktopPic.h : main header file for the SETDESKTOPPIC application
//

#if !defined(AFX_SETDESKTOPPIC_H__904DB301_26E1_423F_B460_B5CD013EBC2D__INCLUDED_)
#define AFX_SETDESKTOPPIC_H__904DB301_26E1_423F_B460_B5CD013EBC2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSetDesktopPicApp:
// See SetDesktopPic.cpp for the implementation of this class
//

class CSetDesktopPicApp : public CWinApp
{
public:
	CSetDesktopPicApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetDesktopPicApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSetDesktopPicApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETDESKTOPPIC_H__904DB301_26E1_423F_B460_B5CD013EBC2D__INCLUDED_)
