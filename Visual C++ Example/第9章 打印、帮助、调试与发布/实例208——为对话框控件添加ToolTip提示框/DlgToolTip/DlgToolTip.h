// DlgToolTip.h : main header file for the DLGTOOLTIP application
//

#if !defined(AFX_DLGTOOLTIP_H__3059149A_7E19_48EC_8DA4_6D8D54D34F6D__INCLUDED_)
#define AFX_DLGTOOLTIP_H__3059149A_7E19_48EC_8DA4_6D8D54D34F6D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CDlgToolTipApp:
// See DlgToolTip.cpp for the implementation of this class
//

class CDlgToolTipApp : public CWinApp
{
public:
	CDlgToolTipApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgToolTipApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CDlgToolTipApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLGTOOLTIP_H__3059149A_7E19_48EC_8DA4_6D8D54D34F6D__INCLUDED_)
