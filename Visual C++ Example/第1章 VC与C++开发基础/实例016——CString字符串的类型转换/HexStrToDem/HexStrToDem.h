// HexStrToDem.h : main header file for the HEXSTRTODEM application
//

#if !defined(AFX_HEXSTRTODEM_H__09134CC9_4C76_4DDA_B35F_A2E852ADA3AF__INCLUDED_)
#define AFX_HEXSTRTODEM_H__09134CC9_4C76_4DDA_B35F_A2E852ADA3AF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHexStrToDemApp:
// See HexStrToDem.cpp for the implementation of this class
//

class CHexStrToDemApp : public CWinApp
{
public:
	CHexStrToDemApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHexStrToDemApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHexStrToDemApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEXSTRTODEM_H__09134CC9_4C76_4DDA_B35F_A2E852ADA3AF__INCLUDED_)
