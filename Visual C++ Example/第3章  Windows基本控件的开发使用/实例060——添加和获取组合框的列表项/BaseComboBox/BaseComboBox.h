// BaseComboBox.h : main header file for the BASECOMBOBOX application
//

#if !defined(AFX_BASECOMBOBOX_H__741E067E_D3B6_404F_BF69_072A98012305__INCLUDED_)
#define AFX_BASECOMBOBOX_H__741E067E_D3B6_404F_BF69_072A98012305__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBaseComboBoxApp:
// See BaseComboBox.cpp for the implementation of this class
//

class CBaseComboBoxApp : public CWinApp
{
public:
	CBaseComboBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseComboBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBaseComboBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASECOMBOBOX_H__741E067E_D3B6_404F_BF69_072A98012305__INCLUDED_)
