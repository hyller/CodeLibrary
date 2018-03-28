// TransClient.h : main header file for the TransClient application
//

#if !defined(AFX_TransClient_H__DA38275E_81E9_458E_B28B_80E9B5CF1173__INCLUDED_)
#define AFX_TransClient_H__DA38275E_81E9_458E_B28B_80E9B5CF1173__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransClientApp:
// See TransClient.cpp for the implementation of this class
//

class CTransClientApp : public CWinApp
{
public:
	CTransClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTransClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TransClient_H__DA38275E_81E9_458E_B28B_80E9B5CF1173__INCLUDED_)
