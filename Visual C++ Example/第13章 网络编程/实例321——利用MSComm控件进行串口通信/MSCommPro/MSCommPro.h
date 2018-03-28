// MSCommPro.h : main header file for the MSCOMMPRO application
//

#if !defined(AFX_MSCOMMPRO_H__5268FD8B_8507_4717_BDCD_3C99E2212725__INCLUDED_)
#define AFX_MSCOMMPRO_H__5268FD8B_8507_4717_BDCD_3C99E2212725__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMSCommProApp:
// See MSCommPro.cpp for the implementation of this class
//

class CMSCommProApp : public CWinApp
{
public:
	CMSCommProApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMSCommProApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMSCommProApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MSCOMMPRO_H__5268FD8B_8507_4717_BDCD_3C99E2212725__INCLUDED_)
