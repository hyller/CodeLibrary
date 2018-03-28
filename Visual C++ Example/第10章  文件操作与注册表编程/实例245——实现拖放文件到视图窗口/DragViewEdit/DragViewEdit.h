// DragViewEdit.h : main header file for the DRAGVIEWEDIT application
//

#if !defined(AFX_DRAGVIEWEDIT_H__CBC097D7_68FF_41A8_B9A1_3922E263BE14__INCLUDED_)
#define AFX_DRAGVIEWEDIT_H__CBC097D7_68FF_41A8_B9A1_3922E263BE14__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDragViewEditApp:
// See DragViewEdit.cpp for the implementation of this class
//

class CDragViewEditApp : public CWinApp
{
public:
	CDragViewEditApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragViewEditApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDragViewEditApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGVIEWEDIT_H__CBC097D7_68FF_41A8_B9A1_3922E263BE14__INCLUDED_)
