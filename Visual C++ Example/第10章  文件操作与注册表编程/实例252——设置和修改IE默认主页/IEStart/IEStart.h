// IEStart.h : main header file for the IESTART application
//

#if !defined(AFX_IESTART_H__3524F89D_F9EA_4870_946E_046DF516ED94__INCLUDED_)
#define AFX_IESTART_H__3524F89D_F9EA_4870_946E_046DF516ED94__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CIEStartApp:
// See IEStart.cpp for the implementation of this class
//

class CIEStartApp : public CWinApp
{
public:
	CIEStartApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CIEStartApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CIEStartApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IESTART_H__3524F89D_F9EA_4870_946E_046DF516ED94__INCLUDED_)
