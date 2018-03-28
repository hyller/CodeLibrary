// AutoComboDemo.h : main header file for the AUTOCOMBODEMO application
//

#if !defined(AFX_AUTOCOMBODEMO_H__DE7ADE72_87B1_4BF0_B678_9759B66820CA__INCLUDED_)
#define AFX_AUTOCOMBODEMO_H__DE7ADE72_87B1_4BF0_B678_9759B66820CA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutoComboDemoApp:
// See AutoComboDemo.cpp for the implementation of this class
//

class CAutoComboDemoApp : public CWinApp
{
public:
	CAutoComboDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutoComboDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAutoComboDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOCOMBODEMO_H__DE7ADE72_87B1_4BF0_B678_9759B66820CA__INCLUDED_)
