// ADODataControl.h : main header file for the ADODATACONTROL application
//

#if !defined(AFX_ADODATACONTROL_H__5E11BBF1_515D_44C2_AC3A_38E929E05434__INCLUDED_)
#define AFX_ADODATACONTROL_H__5E11BBF1_515D_44C2_AC3A_38E929E05434__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CADODataControlApp:
// See ADODataControl.cpp for the implementation of this class
//

class CADODataControlApp : public CWinApp
{
public:
	CADODataControlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataControlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CADODataControlApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATACONTROL_H__5E11BBF1_515D_44C2_AC3A_38E929E05434__INCLUDED_)
