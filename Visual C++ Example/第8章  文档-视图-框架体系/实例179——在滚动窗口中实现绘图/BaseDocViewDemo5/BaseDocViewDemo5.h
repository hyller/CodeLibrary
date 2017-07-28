// BaseDocViewDemo5.h : main header file for the BaseDocViewDemo5 application
//

#if !defined(AFX_BaseDocViewDemo5_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_)
#define AFX_BaseDocViewDemo5_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseDocViewDemo5App:
// See BaseDocViewDemo5.cpp for the implementation of this class
//

class CBaseDocViewDemo5App : public CWinApp
{
public:
	CBaseDocViewDemo5App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDocViewDemo5App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CBaseDocViewDemo5App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDocViewDemo5_H__8BCD74E8_7FEC_4225_9361_BA8934EB7106__INCLUDED_)
