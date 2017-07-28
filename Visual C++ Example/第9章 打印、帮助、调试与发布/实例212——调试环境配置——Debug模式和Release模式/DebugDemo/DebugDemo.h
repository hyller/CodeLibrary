// DebugDemo.h : main header file for the DEBUGDEMO application
//

#if !defined(AFX_DEBUGDEMO_H__59EB91FF_5247_4F84_B0EA_2ECCB0949842__INCLUDED_)
#define AFX_DEBUGDEMO_H__59EB91FF_5247_4F84_B0EA_2ECCB0949842__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDebugDemoApp:
// See DebugDemo.cpp for the implementation of this class
//

class CDebugDemoApp : public CWinApp
{
public:
	CDebugDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDebugDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDebugDemoApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DEBUGDEMO_H__59EB91FF_5247_4F84_B0EA_2ECCB0949842__INCLUDED_)
