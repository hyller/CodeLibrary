// SemaphoreThreadSyn.h : main header file for the SemaphoreThreadSyn application
//

#if !defined(AFX_SemaphoreThreadSyn_H__BED7C684_26FA_4F11_8114_67D1CE95EB8F__INCLUDED_)
#define AFX_SemaphoreThreadSyn_H__BED7C684_26FA_4F11_8114_67D1CE95EB8F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSemaphoreThreadSynApp:
// See SemaphoreThreadSyn.cpp for the implementation of this class
//

class CSemaphoreThreadSynApp : public CWinApp
{
public:
	CSemaphoreThreadSynApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSemaphoreThreadSynApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSemaphoreThreadSynApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SemaphoreThreadSyn_H__BED7C684_26FA_4F11_8114_67D1CE95EB8F__INCLUDED_)
