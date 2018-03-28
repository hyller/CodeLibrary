#if !defined(AFX_RULLERSPLLITERWND_H__87A9CE88_04E2_4C40_ADC9_B1984C8EB9F8__INCLUDED_)
#define AFX_RULLERSPLLITERWND_H__87A9CE88_04E2_4C40_ADC9_B1984C8EB9F8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// RullerSplliterWnd.h : header file
//
#define RT_VERTICAL	  0
#define RT_HORIZONTAL 1


#define RW_VSCROLL	  1
#define RW_HSCROLL	  2
#define RW_POSITION   3

struct stRULER_INFO {
    UINT   uMessage;
    CPoint ScrollPos;
    CSize  DocSize;
	CPoint Pos;
};

/////////////////////////////////////////////////////////////////////////////
// CRullerSplliterWnd window
#ifndef __AFXEXT_H__
#include <afxext.h>
#endif

class CRullerSplliterWnd : public CSplitterWnd
{
// Construction
	DECLARE_DYNCREATE(CRullerSplliterWnd)
public:
	CRullerSplliterWnd();  
	BOOL CreateRulers(CFrameWnd* pParent, CCreateContext* pContext);
	void ShowRulers();
	void UpdateRulersInfo(stRULER_INFO stRulerInfo); 
	 // protected constructor used by dynamic creation

// Attributes
protected:
	CSplitterWnd    m_wndSplitter;
// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRullerSplliterWnd)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CRullerSplliterWnd();

	// Generated message map functions
	//{{AFX_MSG(CRullerSplliterWnd)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RULLERSPLLITERWND_H__F27F57B2_CF9D_4837_9222_52DF073FF5EB__INCLUDED_)
