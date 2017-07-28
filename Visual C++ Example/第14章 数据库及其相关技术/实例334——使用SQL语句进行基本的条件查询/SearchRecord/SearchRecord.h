// SearchRecord.h : main header file for the SEARCHRECORD application
//

#if !defined(AFX_SEARCHRECORD_H__FBB8BA71_85A1_429C_83D5_28DCF2C1F4CC__INCLUDED_)
#define AFX_SEARCHRECORD_H__FBB8BA71_85A1_429C_83D5_28DCF2C1F4CC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSearchRecordApp:
// See SearchRecord.cpp for the implementation of this class
//

class CSearchRecordApp : public CWinApp
{
public:
	CSearchRecordApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSearchRecordApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSearchRecordApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEARCHRECORD_H__FBB8BA71_85A1_429C_83D5_28DCF2C1F4CC__INCLUDED_)
