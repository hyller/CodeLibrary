// UseExternVarDll.h : main header file for the USEEXTERNVARDLL application
//

#if !defined(AFX_USEEXTERNVARDLL_H__9B93D725_3DC5_457E_954C_B307D6144AFC__INCLUDED_)
#define AFX_USEEXTERNVARDLL_H__9B93D725_3DC5_457E_954C_B307D6144AFC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CUseExternVarDllApp:
// See UseExternVarDll.cpp for the implementation of this class
//

class CUseExternVarDllApp : public CWinApp
{
public:
	CUseExternVarDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseExternVarDllApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CUseExternVarDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEEXTERNVARDLL_H__9B93D725_3DC5_457E_954C_B307D6144AFC__INCLUDED_)
