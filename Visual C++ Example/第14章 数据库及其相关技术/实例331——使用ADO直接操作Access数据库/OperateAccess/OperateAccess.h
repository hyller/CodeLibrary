// OperateAccess.h : main header file for the OPERATEACCESS application
//

#if !defined(AFX_OPERATEACCESS_H__A523BFF6_BC86_489F_9459_3AA9BC79784B__INCLUDED_)
#define AFX_OPERATEACCESS_H__A523BFF6_BC86_489F_9459_3AA9BC79784B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// COperateAccessApp:
// See OperateAccess.cpp for the implementation of this class
//

class COperateAccessApp : public CWinApp
{
public:
	COperateAccessApp();
	// 定义ADO连接变量指针
	_ConnectionPtr	m_pConnection;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperateAccessApp)
	public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(COperateAccessApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATEACCESS_H__A523BFF6_BC86_489F_9459_3AA9BC79784B__INCLUDED_)
