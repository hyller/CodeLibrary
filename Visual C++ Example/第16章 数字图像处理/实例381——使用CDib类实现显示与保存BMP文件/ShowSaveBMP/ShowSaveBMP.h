// ShowSaveBMP.h : main header file for the ShowSaveBMP application
//

#if !defined(AFX_ShowSaveBMP_H__CBE1504A_451D_4E4C_8EE1_6B10499C5E39__INCLUDED_)
#define AFX_ShowSaveBMP_H__CBE1504A_451D_4E4C_8EE1_6B10499C5E39__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowSaveBMPApp:
// See ShowSaveBMP.cpp for the implementation of this class
//

class CShowSaveBMPApp : public CWinApp
{
public:
	CShowSaveBMPApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowSaveBMPApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowSaveBMPApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ShowSaveBMP_H__CBE1504A_451D_4E4C_8EE1_6B10499C5E39__INCLUDED_)
