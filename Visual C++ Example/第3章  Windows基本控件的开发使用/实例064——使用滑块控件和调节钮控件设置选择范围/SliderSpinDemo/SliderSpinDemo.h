// SliderSpinDemo.h : main header file for the SLIDERSPINDEMO application
//

#if !defined(AFX_SLIDERSPINDEMO_H__BBA5455B_8D0B_47C8_8757_6074461967F5__INCLUDED_)
#define AFX_SLIDERSPINDEMO_H__BBA5455B_8D0B_47C8_8757_6074461967F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSliderSpinDemoApp:
// See SliderSpinDemo.cpp for the implementation of this class
//

class CSliderSpinDemoApp : public CWinApp
{
public:
	CSliderSpinDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSliderSpinDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSliderSpinDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SLIDERSPINDEMO_H__BBA5455B_8D0B_47C8_8757_6074461967F5__INCLUDED_)
