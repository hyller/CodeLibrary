// CMyOdbcExcel.h : main header file for the CMYODBCEXCEL application
//

#if !defined(AFX_CMYODBCEXCEL_H__81642B5B_CAED_4CD5_AAF2_4327BAA65DF3__INCLUDED_)
#define AFX_CMYODBCEXCEL_H__81642B5B_CAED_4CD5_AAF2_4327BAA65DF3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCMyOdbcExcelApp:
// See CMyOdbcExcel.cpp for the implementation of this class
//

class CCMyOdbcExcelApp : public CWinApp
{
public:
	CCMyOdbcExcelApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMyOdbcExcelApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCMyOdbcExcelApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMYODBCEXCEL_H__81642B5B_CAED_4CD5_AAF2_4327BAA65DF3__INCLUDED_)
