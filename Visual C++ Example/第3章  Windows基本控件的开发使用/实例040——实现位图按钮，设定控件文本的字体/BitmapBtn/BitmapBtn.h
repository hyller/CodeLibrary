// BitmapBtn.h : main header file for the BITMAPBTN application
//

#if !defined(AFX_BITMAPBTN_H__1CFBE66C_43BF_4EC8_83A2_2C8F6582F98C__INCLUDED_)
#define AFX_BITMAPBTN_H__1CFBE66C_43BF_4EC8_83A2_2C8F6582F98C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitmapBtnApp:
// See BitmapBtn.cpp for the implementation of this class
//

class CBitmapBtnApp : public CWinApp
{
public:
	CBitmapBtnApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapBtnApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBitmapBtnApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBTN_H__1CFBE66C_43BF_4EC8_83A2_2C8F6582F98C__INCLUDED_)
