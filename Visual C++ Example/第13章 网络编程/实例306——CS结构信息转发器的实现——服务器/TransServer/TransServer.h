// TransServer.h : main header file for the TransServer application
//

#if !defined(AFX_TransServer_H__61FF12CC_2510_4A3F_A8C3_516B993EE5F1__INCLUDED_)
#define AFX_TransServer_H__61FF12CC_2510_4A3F_A8C3_516B993EE5F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTransServerApp:
// See TransServer.cpp for the implementation of this class
//

class CTransServerApp : public CWinApp
{
public:
	CTransServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CTransServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TransServer_H__61FF12CC_2510_4A3F_A8C3_516B993EE5F1__INCLUDED_)
