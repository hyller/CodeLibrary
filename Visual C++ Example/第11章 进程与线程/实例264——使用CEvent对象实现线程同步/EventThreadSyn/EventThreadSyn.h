// EventThreadSyn.h : main header file for the EventThreadSyn application
//

#if !defined(AFX_EventThreadSyn_H__77233D90_6960_4572_ACFB_82CCF6315A9F__INCLUDED_)
#define AFX_EventThreadSyn_H__77233D90_6960_4572_ACFB_82CCF6315A9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CEventThreadSynApp:
// See EventThreadSyn.cpp for the implementation of this class
//

class CEventThreadSynApp : public CWinApp
{
public:
	CEventThreadSynApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEventThreadSynApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CEventThreadSynApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EventThreadSyn_H__77233D90_6960_4572_ACFB_82CCF6315A9F__INCLUDED_)
