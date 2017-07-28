// StaticImage.h : main header file for the STATICIMAGE application
//

#if !defined(AFX_STATICIMAGE_H__A17E1956_78A8_4DFA_9480_4D1ADC1AAC5E__INCLUDED_)
#define AFX_STATICIMAGE_H__A17E1956_78A8_4DFA_9480_4D1ADC1AAC5E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CStaticImageApp:
// See StaticImage.cpp for the implementation of this class
//

class CStaticImageApp : public CWinApp
{
public:
	CStaticImageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStaticImageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CStaticImageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATICIMAGE_H__A17E1956_78A8_4DFA_9480_4D1ADC1AAC5E__INCLUDED_)
