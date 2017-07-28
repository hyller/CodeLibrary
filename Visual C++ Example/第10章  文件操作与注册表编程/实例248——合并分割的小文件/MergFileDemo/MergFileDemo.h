// MergFileDemo.h : main header file for the MERGFILEDEMO application
//

#if !defined(AFX_MERGFILEDEMO_H__CDDBEE63_D8DC_4C8E_8812_A9D29A07DAB2__INCLUDED_)
#define AFX_MERGFILEDEMO_H__CDDBEE63_D8DC_4C8E_8812_A9D29A07DAB2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMergFileDemoApp:
// See MergFileDemo.cpp for the implementation of this class
//

class CMergFileDemoApp : public CWinApp
{
public:
	CMergFileDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMergFileDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMergFileDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MERGFILEDEMO_H__CDDBEE63_D8DC_4C8E_8812_A9D29A07DAB2__INCLUDED_)
