// ProgressbarStatus.h : main header file for the PROGRESSBARSTATUS application
//

#if !defined(AFX_PROGRESSBARSTATUS_H__D645E8CF_1A92_4744_8C59_B53E197CB6AD__INCLUDED_)
#define AFX_PROGRESSBARSTATUS_H__D645E8CF_1A92_4744_8C59_B53E197CB6AD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CProgressbarStatusApp:
// See ProgressbarStatus.cpp for the implementation of this class
//

class CProgressbarStatusApp : public CWinApp
{
public:
	CProgressbarStatusApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CProgressbarStatusApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CProgressbarStatusApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROGRESSBARSTATUS_H__D645E8CF_1A92_4744_8C59_B53E197CB6AD__INCLUDED_)
