// MouseInfoTip.h : main header file for the MOUSEINFOTIP application
//

#if !defined(AFX_MOUSEINFOTIP_H__4181E374_06A9_4329_ABDE_E210002BBAA9__INCLUDED_)
#define AFX_MOUSEINFOTIP_H__4181E374_06A9_4329_ABDE_E210002BBAA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMouseInfoTipApp:
// See MouseInfoTip.cpp for the implementation of this class
//

class CMouseInfoTipApp : public CWinApp
{
public:
	CMouseInfoTipApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMouseInfoTipApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMouseInfoTipApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOUSEINFOTIP_H__4181E374_06A9_4329_ABDE_E210002BBAA9__INCLUDED_)
