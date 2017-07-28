// TimeLimit.h : main header file for the TIMELIMIT application
//

#if !defined(AFX_TIMELIMIT_H__9D415FE3_2499_48F4_A7C0_132861A2FC2F__INCLUDED_)
#define AFX_TIMELIMIT_H__9D415FE3_2499_48F4_A7C0_132861A2FC2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CTimeLimitApp:
// See TimeLimit.cpp for the implementation of this class
//

class CTimeLimitApp : public CWinApp
{
public:
	CTimeLimitApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTimeLimitApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

public:
	BOOL IsInstalled();
	BOOL GetLimitTime(CTime& t);  //t用来存储从注册表中读到的时间值
	BOOL SetLimitTime(DWORD nYear,DWORD nMonth,DWORD nDay,
		              DWORD nHour,DWORD nMinute,DWORD nSecond);

// Implementation

	//{{AFX_MSG(CTimeLimitApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TIMELIMIT_H__9D415FE3_2499_48F4_A7C0_132861A2FC2F__INCLUDED_)
