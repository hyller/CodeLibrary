// DeleteUnEmptyFold.h : main header file for the DELETEUNEMPTYFOLD application
//

#if !defined(AFX_DELETEUNEMPTYFOLD_H__34E844B4_DF76_46BC_95E2_F1C965CE49F8__INCLUDED_)
#define AFX_DELETEUNEMPTYFOLD_H__34E844B4_DF76_46BC_95E2_F1C965CE49F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDeleteUnEmptyFoldApp:
// See DeleteUnEmptyFold.cpp for the implementation of this class
//

class CDeleteUnEmptyFoldApp : public CWinApp
{
public:
	CDeleteUnEmptyFoldApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDeleteUnEmptyFoldApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDeleteUnEmptyFoldApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DELETEUNEMPTYFOLD_H__34E844B4_DF76_46BC_95E2_F1C965CE49F8__INCLUDED_)
