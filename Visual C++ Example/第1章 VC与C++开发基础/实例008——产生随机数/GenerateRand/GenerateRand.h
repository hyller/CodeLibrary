// GenerateRand.h : main header file for the GENERATERAND application
//

#if !defined(AFX_GENERATERAND_H__87E69622_D291_46F4_BB7F_FB89E8B47D6C__INCLUDED_)
#define AFX_GENERATERAND_H__87E69622_D291_46F4_BB7F_FB89E8B47D6C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGenerateRandApp:
// See GenerateRand.cpp for the implementation of this class
//

class CGenerateRandApp : public CWinApp
{
public:
	CGenerateRandApp();
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGenerateRandApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGenerateRandApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GENERATERAND_H__87E69622_D291_46F4_BB7F_FB89E8B47D6C__INCLUDED_)
