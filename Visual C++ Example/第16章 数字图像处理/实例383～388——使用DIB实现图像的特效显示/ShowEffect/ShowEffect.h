// ShowEffect.h : main header file for the SHOWEFFECT application
//

#if !defined(AFX_SHOWEFFECT_H__B2911070_E34B_49A8_833B_8B47E5FCABCF__INCLUDED_)
#define AFX_SHOWEFFECT_H__B2911070_E34B_49A8_833B_8B47E5FCABCF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShowEffectApp:
// See ShowEffect.cpp for the implementation of this class
//

class CShowEffectApp : public CWinApp
{
public:
	CShowEffectApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowEffectApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CShowEffectApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWEFFECT_H__B2911070_E34B_49A8_833B_8B47E5FCABCF__INCLUDED_)
