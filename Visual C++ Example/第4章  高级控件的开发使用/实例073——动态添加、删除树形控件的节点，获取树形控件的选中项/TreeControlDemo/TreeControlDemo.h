// TreeControlDemo.h : main header file for the TreeControlDemo application
//

#if !defined(AFX_TreeControlDemo_H__8AE66387_3C56_4406_8671_F94D87A66CB8__INCLUDED_)
#define AFX_TreeControlDemo_H__8AE66387_3C56_4406_8671_F94D87A66CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTreeControlDemoApp:
// See TreeControlDemo.cpp for the implementation of this class
//

class CTreeControlDemoApp : public CWinApp
{
public:
	CTreeControlDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTreeControlDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTreeControlDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TreeControlDemo_H__8AE66387_3C56_4406_8671_F94D87A66CB8__INCLUDED_)
