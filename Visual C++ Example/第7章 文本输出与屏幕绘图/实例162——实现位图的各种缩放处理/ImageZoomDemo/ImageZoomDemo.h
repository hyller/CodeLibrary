// ImageZoomDemo.h : main header file for the IMAGEZOOMDEMO application
//

#if !defined(AFX_IMAGEZOOMDEMO_H__18D4C715_32CA_4CA8_86CF_FE6C7AC4B79A__INCLUDED_)
#define AFX_IMAGEZOOMDEMO_H__18D4C715_32CA_4CA8_86CF_FE6C7AC4B79A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CImageZoomDemoApp:
// See ImageZoomDemo.cpp for the implementation of this class
//

class CImageZoomDemoApp : public CWinApp
{
public:
	CImageZoomDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageZoomDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CImageZoomDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEZOOMDEMO_H__18D4C715_32CA_4CA8_86CF_FE6C7AC4B79A__INCLUDED_)
