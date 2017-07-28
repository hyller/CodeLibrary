// ColorTextProgressBar.h : main header file for the COLORTEXTPROGRESSBAR application
//

#if !defined(AFX_COLORTEXTPROGRESSBAR_H__0F94DC17_8266_4147_89AC_475CDCC81C18__INCLUDED_)
#define AFX_COLORTEXTPROGRESSBAR_H__0F94DC17_8266_4147_89AC_475CDCC81C18__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorTextProgressBarApp:
// See ColorTextProgressBar.cpp for the implementation of this class
//

class CColorTextProgressBarApp : public CWinApp
{
public:
	CColorTextProgressBarApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorTextProgressBarApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColorTextProgressBarApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORTEXTPROGRESSBAR_H__0F94DC17_8266_4147_89AC_475CDCC81C18__INCLUDED_)
