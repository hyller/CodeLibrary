// BaseDocViewDemo4.h : main header file for the BaseDocViewDemo4 application
//

#if !defined(AFX_BaseDocViewDemo4_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_)
#define AFX_BaseDocViewDemo4_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo4App:
// See BaseDocViewDemo4.cpp for the implementation of this class
//

class CBaseDocViewDemo4App : public CWinApp
{
public:
	CBaseDocViewDemo4App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDocViewDemo4App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaseDocViewDemo4App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDocViewDemo4_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_)
