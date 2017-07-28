// ShowGraphics.h : main header file for the SHOWGRAPHICS application
//

#if !defined(AFX_SHOWGRAPHICS_H__D4733330_8203_496D_92AD_1E8C34588976__INCLUDED_)
#define AFX_SHOWGRAPHICS_H__D4733330_8203_496D_92AD_1E8C34588976__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowGraphicsApp:
// See ShowGraphics.cpp for the implementation of this class
//

class CShowGraphicsApp : public CWinApp
{
public:
	CShowGraphicsApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowGraphicsApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowGraphicsApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWGRAPHICS_H__D4733330_8203_496D_92AD_1E8C34588976__INCLUDED_)
