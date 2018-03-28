// DyOpenClose.h : main header file for the DYOPENCLOSE application
//

#if !defined(AFX_DYOPENCLOSE_H__D20480DE_0DCA_471A_97B2_957DBE4C5A0A__INCLUDED_)
#define AFX_DYOPENCLOSE_H__D20480DE_0DCA_471A_97B2_957DBE4C5A0A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDyOpenCloseApp:
// See DyOpenClose.cpp for the implementation of this class
//

class CDyOpenCloseApp : public CWinApp
{
public:
	CDyOpenCloseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyOpenCloseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDyOpenCloseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYOPENCLOSE_H__D20480DE_0DCA_471A_97B2_957DBE4C5A0A__INCLUDED_)
