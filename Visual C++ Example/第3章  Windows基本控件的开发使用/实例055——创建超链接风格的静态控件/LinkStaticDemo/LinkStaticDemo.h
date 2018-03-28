// LinkStaticDemo.h : main header file for the LINKSTATICDEMO application
//

#if !defined(AFX_LINKSTATICDEMO_H__0A1E737D_1812_4CCD_8F4C_5BCCF64CCA0B__INCLUDED_)
#define AFX_LINKSTATICDEMO_H__0A1E737D_1812_4CCD_8F4C_5BCCF64CCA0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLinkStaticDemoApp:
// See LinkStaticDemo.cpp for the implementation of this class
//

class CLinkStaticDemoApp : public CWinApp
{
public:
	CLinkStaticDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLinkStaticDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLinkStaticDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINKSTATICDEMO_H__0A1E737D_1812_4CCD_8F4C_5BCCF64CCA0B__INCLUDED_)
