// NumToChinese.h : main header file for the NUMTOCHINESE application
//

#if !defined(AFX_NUMTOCHINESE_H__B17D72D6_B9E1_4C61_9534_814A508FBDD5__INCLUDED_)
#define AFX_NUMTOCHINESE_H__B17D72D6_B9E1_4C61_9534_814A508FBDD5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CNumToChineseApp:
// See NumToChinese.cpp for the implementation of this class
//

class CNumToChineseApp : public CWinApp
{
public:
	CNumToChineseApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNumToChineseApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CNumToChineseApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NUMTOCHINESE_H__B17D72D6_B9E1_4C61_9534_814A508FBDD5__INCLUDED_)
