// BitMapBKDlg.h : main header file for the BITMAPBKDLG application
//

#if !defined(AFX_BITMAPBKDLG_H__B59B14F9_6711_4B79_87B4_EFD6ED8E48D2__INCLUDED_)
#define AFX_BITMAPBKDLG_H__B59B14F9_6711_4B79_87B4_EFD6ED8E48D2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitMapBKDlgApp:
// See BitMapBKDlg.cpp for the implementation of this class
//

class CBitMapBKDlgApp : public CWinApp
{
public:
	CBitMapBKDlgApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitMapBKDlgApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBitMapBKDlgApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPBKDLG_H__B59B14F9_6711_4B79_87B4_EFD6ED8E48D2__INCLUDED_)
