// BaseDocViewDemo1.h : main header file for the BASEDOCVIEWDEMO1 application
//

#if !defined(AFX_BASEDOCVIEWDEMO1_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_)
#define AFX_BASEDOCVIEWDEMO1_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo1App:
// See BaseDocViewDemo1.cpp for the implementation of this class
//

class CBaseDocViewDemo1App : public CWinApp
{
public:
	CBaseDocViewDemo1App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDocViewDemo1App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaseDocViewDemo1App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEDOCVIEWDEMO1_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_)
