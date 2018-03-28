// DlgRegularDll.h : main header file for the DLGREGULARDLL DLL
//

#if !defined(AFX_DLGREGULARDLL_H__B9A2FC12_89EF_49F9_B151_B1038B539578__INCLUDED_)
#define AFX_DLGREGULARDLL_H__B9A2FC12_89EF_49F9_B151_B1038B539578__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgRegularDllApp
// See DlgRegularDll.cpp for the implementation of this class
//

class CDlgRegularDllApp : public CWinApp
{
public:
	CDlgRegularDllApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgRegularDllApp)
	//}}AFX_VIRTUAL

	//{{AFX_MSG(CDlgRegularDllApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGREGULARDLL_H__B9A2FC12_89EF_49F9_B151_B1038B539578__INCLUDED_)
