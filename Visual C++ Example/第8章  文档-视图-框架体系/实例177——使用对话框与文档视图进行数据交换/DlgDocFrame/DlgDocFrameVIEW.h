// DlgDocFrameView.h : interface of the CDlgDocFrameView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DlgDocFrameVIEW_H__73A87FC2_DA40_4750_82E1_2257F02F324A__INCLUDED_)
#define AFX_DlgDocFrameVIEW_H__73A87FC2_DA40_4750_82E1_2257F02F324A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "DlgDocFrameDlg.h"

class CDlgDocFrameView : public CView
{
protected: // create from serialization only
	CDlgDocFrameView();
	DECLARE_DYNCREATE(CDlgDocFrameView)

// Attributes
public:
	CDlgDocFrameDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDocFrameView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDlgDocFrameView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgDocFrameView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DlgDocFrameView.cpp
inline CDlgDocFrameDoc* CDlgDocFrameView::GetDocument()
   { return (CDlgDocFrameDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDocFrameVIEW_H__73A87FC2_DA40_4750_82E1_2257F02F324A__INCLUDED_)
