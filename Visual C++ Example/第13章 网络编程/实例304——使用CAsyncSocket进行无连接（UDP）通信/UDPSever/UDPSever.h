// UDPSever.h : main header file for the UDPSever application
//

#if !defined(AFX_UDPSever_H__9C572329_D8BF_4BE6_A5F1_975E611E2902__INCLUDED_)
#define AFX_UDPSever_H__9C572329_D8BF_4BE6_A5F1_975E611E2902__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUDPSeverApp:
// See UDPSever.cpp for the implementation of this class
//

class CUDPSeverApp : public CWinApp
{
public:
	CUDPSeverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUDPSeverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUDPSeverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_UDPSever_H__9C572329_D8BF_4BE6_A5F1_975E611E2902__INCLUDED_)
