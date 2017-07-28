// CreateDeletePath.h : main header file for the CREATEDELETEPATH application
//

#if !defined(AFX_CREATEDELETEPATH_H__C5817186_2CAD_4075_91B0_31E396436EB4__INCLUDED_)
#define AFX_CREATEDELETEPATH_H__C5817186_2CAD_4075_91B0_31E396436EB4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCreateDeletePathApp:
// See CreateDeletePath.cpp for the implementation of this class
//

class CCreateDeletePathApp : public CWinApp
{
public:
	CCreateDeletePathApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCreateDeletePathApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCreateDeletePathApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CREATEDELETEPATH_H__C5817186_2CAD_4075_91B0_31E396436EB4__INCLUDED_)
