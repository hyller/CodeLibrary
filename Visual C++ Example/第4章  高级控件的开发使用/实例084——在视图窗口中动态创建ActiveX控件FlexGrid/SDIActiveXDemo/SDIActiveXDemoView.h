// SDIActiveXDemoView.h : interface of the CSDIActiveXDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SDIACTIVEXDEMOVIEW_H__493DEB1F_64D3_4C7C_8B2C_29B777756789__INCLUDED_)
#define AFX_SDIACTIVEXDEMOVIEW_H__493DEB1F_64D3_4C7C_8B2C_29B777756789__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "mshflexgrid.h"
//#include "font.h"

class CSDIActiveXDemoView : public CView
{
protected: // create from serialization only
	CSDIActiveXDemoView();
	DECLARE_DYNCREATE(CSDIActiveXDemoView)

// Attributes
public:
	CSDIActiveXDemoDoc* GetDocument();
	CMSHFlexGrid m_flexgrid;
	CString str;//消息字符串

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDIActiveXDemoView)
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
	virtual ~CSDIActiveXDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSDIActiveXDemoView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClick();//消息响应函数
	//}}AFX_MSG
	DECLARE_EVENTSINK_MAP()//事件映射宏
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SDIActiveXDemoView.cpp
inline CSDIActiveXDemoDoc* CSDIActiveXDemoView::GetDocument()
   { return (CSDIActiveXDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDIACTIVEXDEMOVIEW_H__493DEB1F_64D3_4C7C_8B2C_29B777756789__INCLUDED_)
