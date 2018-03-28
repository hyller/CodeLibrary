// ClipTextTrans.h : main header file for the CLIPTEXTTRANS application
//

#if !defined(AFX_CLIPTEXTTRANS_H__26F76761_EC49_4032_B1CA_9B0153E942DB__INCLUDED_)
#define AFX_CLIPTEXTTRANS_H__26F76761_EC49_4032_B1CA_9B0153E942DB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CClipTextTransApp:
// See ClipTextTrans.cpp for the implementation of this class
//

class CClipTextTransApp : public CWinApp
{
public:
	CClipTextTransApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipTextTransApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CClipTextTransApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPTEXTTRANS_H__26F76761_EC49_4032_B1CA_9B0153E942DB__INCLUDED_)
