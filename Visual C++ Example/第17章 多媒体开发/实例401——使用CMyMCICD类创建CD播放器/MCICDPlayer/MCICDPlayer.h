// MCICDPlayer.h : main header file for the MCICDPlayer application
//

#if !defined(AFX_MCICDPlayer_H__F72E7865_6A64_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_MCICDPlayer_H__F72E7865_6A64_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMCICDPlayerApp:
// See MCICDPlayer.cpp for the implementation of this class
//

class CMCICDPlayerApp : public CWinApp
{
public:
	CMCICDPlayerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMCICDPlayerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMCICDPlayerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCICDPlayer_H__F72E7865_6A64_11D6_8F32_00E04CE76240__INCLUDED_)
