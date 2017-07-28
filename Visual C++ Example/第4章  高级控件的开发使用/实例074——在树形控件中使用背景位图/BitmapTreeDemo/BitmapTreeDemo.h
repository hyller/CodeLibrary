// BitmapTreeDemo.h : main header file for the BITMAPTREEDEMO application
//

#if !defined(AFX_BITMAPTREEDEMO_H__352D8ABA_5A72_4E1A_91AD_6D3A2BC9A20A__INCLUDED_)
#define AFX_BITMAPTREEDEMO_H__352D8ABA_5A72_4E1A_91AD_6D3A2BC9A20A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CBitmapTreeDemoApp:
// See BitmapTreeDemo.cpp for the implementation of this class
//

class CBitmapTreeDemoApp : public CWinApp
{
public:
	CBitmapTreeDemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapTreeDemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CBitmapTreeDemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPTREEDEMO_H__352D8ABA_5A72_4E1A_91AD_6D3A2BC9A20A__INCLUDED_)
