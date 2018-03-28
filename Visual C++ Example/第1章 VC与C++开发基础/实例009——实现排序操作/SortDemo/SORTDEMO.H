// SortDemo.h : main header file for the SORTDEMO application
//

#if !defined(AFX_SORTDEMO_H__F11D8DA4_2FA8_4347_9BE6_56C20C234427__INCLUDED_)
#define AFX_SORTDEMO_H__F11D8DA4_2FA8_4347_9BE6_56C20C234427__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSortDemoApp:
// See SortDemo.cpp for the implementation of this class
//

class CSortDemoApp : public CWinApp
{
public:
	CSortDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSortDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSortDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SORTDEMO_H__F11D8DA4_2FA8_4347_9BE6_56C20C234427__INCLUDED_)
