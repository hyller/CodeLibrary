// ClipCursorMouse.h : main header file for the CLIPCURSORMOUSE application
//

#if !defined(AFX_CLIPCURSORMOUSE_H__CE15294B_9AC0_4848_B3D3_76F41A3FCC58__INCLUDED_)
#define AFX_CLIPCURSORMOUSE_H__CE15294B_9AC0_4848_B3D3_76F41A3FCC58__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CClipCursorMouseApp:
// See ClipCursorMouse.cpp for the implementation of this class
//

class CClipCursorMouseApp : public CWinApp
{
public:
	CClipCursorMouseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipCursorMouseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CClipCursorMouseApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPCURSORMOUSE_H__CE15294B_9AC0_4848_B3D3_76F41A3FCC58__INCLUDED_)
