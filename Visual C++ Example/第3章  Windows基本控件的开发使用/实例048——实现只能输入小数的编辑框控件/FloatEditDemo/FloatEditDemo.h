// FloatEditDemo.h : main header file for the FLOATEDITDEMO application
//

#if !defined(AFX_FLOATEDITDEMO_H__3894E558_01A3_4B2B_860A_4C1B51591C78__INCLUDED_)
#define AFX_FLOATEDITDEMO_H__3894E558_01A3_4B2B_860A_4C1B51591C78__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFloatEditDemoApp:
// See FloatEditDemo.cpp for the implementation of this class
//

class CFloatEditDemoApp : public CWinApp
{
public:
	CFloatEditDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFloatEditDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFloatEditDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FLOATEDITDEMO_H__3894E558_01A3_4B2B_860A_4C1B51591C78__INCLUDED_)
