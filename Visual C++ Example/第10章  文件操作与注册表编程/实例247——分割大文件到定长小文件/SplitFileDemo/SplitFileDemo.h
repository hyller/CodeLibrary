// SplitFileDemo.h : main header file for the SPLITFILEDEMO application
//

#if !defined(AFX_SPLITFILEDEMO_H__A3CA09F4_5832_4913_927A_2C446620402B__INCLUDED_)
#define AFX_SPLITFILEDEMO_H__A3CA09F4_5832_4913_927A_2C446620402B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSplitFileDemoApp:
// See SplitFileDemo.cpp for the implementation of this class
//

class CSplitFileDemoApp : public CWinApp
{
public:
	CSplitFileDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSplitFileDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSplitFileDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPLITFILEDEMO_H__A3CA09F4_5832_4913_927A_2C446620402B__INCLUDED_)
