// DySplitterWnd.h : main header file for the DYSPLITTERWND application
//

#if !defined(AFX_DYSPLITTERWND_H__630E908F_F754_4663_8001_9D70B1AD5A23__INCLUDED_)
#define AFX_DYSPLITTERWND_H__630E908F_F754_4663_8001_9D70B1AD5A23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDySplitterWndApp:
// See DySplitterWnd.cpp for the implementation of this class
//

class CDySplitterWndApp : public CWinApp
{
public:
	CDySplitterWndApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDySplitterWndApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDySplitterWndApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYSPLITTERWND_H__630E908F_F754_4663_8001_9D70B1AD5A23__INCLUDED_)
