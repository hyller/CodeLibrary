// DrawStaticDemo.h : main header file for the DRAWSTATICDEMO application
//

#if !defined(AFX_DRAWSTATICDEMO_H__9DB288E4_5CD5_4CEC_9149_0F262EB5D53E__INCLUDED_)
#define AFX_DRAWSTATICDEMO_H__9DB288E4_5CD5_4CEC_9149_0F262EB5D53E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDrawStaticDemoApp:
// See DrawStaticDemo.cpp for the implementation of this class
//

class CDrawStaticDemoApp : public CWinApp
{
public:
	CDrawStaticDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDrawStaticDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDrawStaticDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAWSTATICDEMO_H__9DB288E4_5CD5_4CEC_9149_0F262EB5D53E__INCLUDED_)
