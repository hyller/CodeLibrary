// ColorStaticDemo.h : main header file for the COLORSTATICDEMO application
//

#if !defined(AFX_COLORSTATICDEMO_H__67183CC5_F9AB_45F6_8226_1D18B73284D8__INCLUDED_)
#define AFX_COLORSTATICDEMO_H__67183CC5_F9AB_45F6_8226_1D18B73284D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorStaticDemoApp:
// See ColorStaticDemo.cpp for the implementation of this class
//

class CColorStaticDemoApp : public CWinApp
{
public:
	CColorStaticDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorStaticDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColorStaticDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORSTATICDEMO_H__67183CC5_F9AB_45F6_8226_1D18B73284D8__INCLUDED_)
