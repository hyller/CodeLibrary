// DyScrollRect.h : main header file for the DYSCROLLRECT application
//

#if !defined(AFX_DYSCROLLRECT_H__DFFB5A53_68A6_4008_9710_CDED17FFE769__INCLUDED_)
#define AFX_DYSCROLLRECT_H__DFFB5A53_68A6_4008_9710_CDED17FFE769__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDyScrollRectApp:
// See DyScrollRect.cpp for the implementation of this class
//

class CDyScrollRectApp : public CWinApp
{
public:
	CDyScrollRectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyScrollRectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDyScrollRectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYSCROLLRECT_H__DFFB5A53_68A6_4008_9710_CDED17FFE769__INCLUDED_)
