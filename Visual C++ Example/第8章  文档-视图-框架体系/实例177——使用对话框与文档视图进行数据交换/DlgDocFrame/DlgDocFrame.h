// DlgDocFrame.h : main header file for the DlgDocFrame application
//

#if !defined(AFX_DlgDocFrame_H__7AA151ED_F787_41A7_9D7A_3F6D50CA3BA9__INCLUDED_)
#define AFX_DlgDocFrame_H__7AA151ED_F787_41A7_9D7A_3F6D50CA3BA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgDocFrameApp:
// See DlgDocFrame.cpp for the implementation of this class
//

class CDlgDocFrameApp : public CWinApp
{
public:
	CDlgDocFrameApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDocFrameApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDlgDocFrameApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDocFrame_H__7AA151ED_F787_41A7_9D7A_3F6D50CA3BA9__INCLUDED_)
