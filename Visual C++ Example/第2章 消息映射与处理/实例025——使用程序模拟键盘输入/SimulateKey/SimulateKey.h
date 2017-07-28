// SimulateKey.h : main header file for the SIMULATEKEY application
//

#if !defined(AFX_SIMULATEKEY_H__FE8208A9_F73A_4CB3_9592_5FBF1C14517D__INCLUDED_)
#define AFX_SIMULATEKEY_H__FE8208A9_F73A_4CB3_9592_5FBF1C14517D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSimulateKeyApp:
// See SimulateKey.cpp for the implementation of this class
//

class CSimulateKeyApp : public CWinApp
{
public:
	CSimulateKeyApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSimulateKeyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSimulateKeyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SIMULATEKEY_H__FE8208A9_F73A_4CB3_9592_5FBF1C14517D__INCLUDED_)
