// EnumFontsDemo.h : main header file for the ENUMFONTSDEMO application
//

#if !defined(AFX_ENUMFONTSDEMO_H__35F57578_97BC_4DCF_81C8_C3C890C2634F__INCLUDED_)
#define AFX_ENUMFONTSDEMO_H__35F57578_97BC_4DCF_81C8_C3C890C2634F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEnumFontsDemoApp:
// See EnumFontsDemo.cpp for the implementation of this class
//

class CEnumFontsDemoApp : public CWinApp
{
public:
	CEnumFontsDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEnumFontsDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEnumFontsDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ENUMFONTSDEMO_H__35F57578_97BC_4DCF_81C8_C3C890C2634F__INCLUDED_)
