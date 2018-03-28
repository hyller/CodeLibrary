// SysMenuItem.h : main header file for the SYSMENUITEM application
//

#if !defined(AFX_SYSMENUITEM_H__2E17C63A_08B4_470F_83C3_F8ACD8821EB9__INCLUDED_)
#define AFX_SYSMENUITEM_H__2E17C63A_08B4_470F_83C3_F8ACD8821EB9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CSysMenuItemApp:
// See SysMenuItem.cpp for the implementation of this class
//

class CSysMenuItemApp : public CWinApp
{
public:
	CSysMenuItemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysMenuItemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CSysMenuItemApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSMENUITEM_H__2E17C63A_08B4_470F_83C3_F8ACD8821EB9__INCLUDED_)
