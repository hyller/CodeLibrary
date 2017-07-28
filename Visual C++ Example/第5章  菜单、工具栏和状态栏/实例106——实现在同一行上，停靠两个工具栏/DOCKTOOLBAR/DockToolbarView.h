// DockToolbarView.h : interface of the CDockToolbarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOCKTOOLBARVIEW_H__A6CD090C_6A3D_46CF_81F9_885003B0746A__INCLUDED_)
#define AFX_DOCKTOOLBARVIEW_H__A6CD090C_6A3D_46CF_81F9_885003B0746A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDockToolbarView : public CView
{
protected: // create from serialization only
	CDockToolbarView();
	DECLARE_DYNCREATE(CDockToolbarView)

// Attributes
public:
	CDockToolbarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDockToolbarView)
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
	virtual ~CDockToolbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDockToolbarView)
	afx_msg void OnButton32771();
	afx_msg void OnButton32772();
	afx_msg void OnButton32773();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DockToolbarView.cpp
inline CDockToolbarDoc* CDockToolbarView::GetDocument()
   { return (CDockToolbarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DOCKTOOLBARVIEW_H__A6CD090C_6A3D_46CF_81F9_885003B0746A__INCLUDED_)
