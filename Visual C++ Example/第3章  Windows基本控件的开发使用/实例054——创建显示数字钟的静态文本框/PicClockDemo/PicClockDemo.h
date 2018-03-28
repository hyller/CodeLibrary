// PicClockDemo.h : main header file for the PICCLOCKDEMO application
//

#if !defined(AFX_PICCLOCKDEMO_H__DE0A5E18_47E1_4F51_841C_CA51C5B597CA__INCLUDED_)
#define AFX_PICCLOCKDEMO_H__DE0A5E18_47E1_4F51_841C_CA51C5B597CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPicClockDemoApp:
// See PicClockDemo.cpp for the implementation of this class
//

class CPicClockDemoApp : public CWinApp
{
public:
	CPicClockDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPicClockDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPicClockDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PICCLOCKDEMO_H__DE0A5E18_47E1_4F51_841C_CA51C5B597CA__INCLUDED_)
