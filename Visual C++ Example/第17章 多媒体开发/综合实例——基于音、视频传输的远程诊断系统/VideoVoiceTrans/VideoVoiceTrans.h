// VideoVoiceTrans.h : main header file for the VideoVoiceTrans application
//

#if !defined(AFX_VideoVoiceTrans_H__B0986304_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
#define AFX_VideoVoiceTrans_H__B0986304_5F44_11D6_8897_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

//---------------------------
//For AppFace
#include "appface.h"
//---------------------------

/////////////////////////////////////////////////////////////////////////////
// CVideoVoiceTransApp:
// See VideoVoiceTrans.cpp for the implementation of this class
//

class CVideoVoiceTransApp : public CWinApp
{
public:
	CVideoVoiceTransApp();

		//--------------------------
	//For AppFace
	CAppFace m_af ;
	//--------------------------

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoVoiceTransApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVideoVoiceTransApp)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VideoVoiceTrans_H__B0986304_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
