// PPClient.h : main header file for the PPClient application
//

#if !defined(AFX_PPClient_H__C7F65849_3E59_4B02_B9D5_79F85C7CD88D__INCLUDED_)
#define AFX_PPClient_H__C7F65849_3E59_4B02_B9D5_79F85C7CD88D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPPClientApp:
// See PPClient.cpp for the implementation of this class
//

class CPPClientApp : public CWinApp
{
public:
	CPPClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPPClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPPClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PPClient_H__C7F65849_3E59_4B02_B9D5_79F85C7CD88D__INCLUDED_)
