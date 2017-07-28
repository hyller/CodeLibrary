// MyMediaPlay.h : main header file for the MYMEDIAPLAY application
//

#if !defined(AFX_MYMEDIAPLAY_H__AB5589B3_167F_4041_985C_E82A1947FBCE__INCLUDED_)
#define AFX_MYMEDIAPLAY_H__AB5589B3_167F_4041_985C_E82A1947FBCE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMyMediaPlayApp:
// See MyMediaPlay.cpp for the implementation of this class
//

class CMyMediaPlayApp : public CWinApp
{
public:
	CMyMediaPlayApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMediaPlayApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMyMediaPlayApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMEDIAPLAY_H__AB5589B3_167F_4041_985C_E82A1947FBCE__INCLUDED_)
