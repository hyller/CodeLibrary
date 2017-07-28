// ADOOperatePic2.h : main header file for the ADOOperatePic2 application
//

#if !defined(AFX_ADOOperatePic2_H__460B9244_2883_4B7F_A18D_CA4594BC0A9A__INCLUDED_)
#define AFX_ADOOperatePic2_H__460B9244_2883_4B7F_A18D_CA4594BC0A9A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePic2App:
// See ADOOperatePic2.cpp for the implementation of this class
//

class CADOOperatePic2App : public CWinApp
{
public:
	CADOOperatePic2App();
	_ConnectionPtr m_pConnection;//连接对象
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOOperatePic2App)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CADOOperatePic2App)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOOperatePic2_H__460B9244_2883_4B7F_A18D_CA4594BC0A9A__INCLUDED_)
