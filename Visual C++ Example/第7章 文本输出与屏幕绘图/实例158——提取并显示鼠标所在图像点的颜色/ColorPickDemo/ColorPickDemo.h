// ColorPickDemo.h : main header file for the COLORPICKDEMO application
//

#if !defined(AFX_COLORPICKDEMO_H__3D8BE894_F1E4_487B_BB97_918F38B2B38A__INCLUDED_)
#define AFX_COLORPICKDEMO_H__3D8BE894_F1E4_487B_BB97_918F38B2B38A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CColorPickDemoApp:
// See ColorPickDemo.cpp for the implementation of this class
//

class CColorPickDemoApp : public CWinApp
{
public:
	CColorPickDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CColorPickDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CColorPickDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COLORPICKDEMO_H__3D8BE894_F1E4_487B_BB97_918F38B2B38A__INCLUDED_)
