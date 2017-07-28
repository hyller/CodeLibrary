// ShowGraphicsView.h : interface of the CShowGraphicsView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWGRAPHICSVIEW_H__45AE3021_3863_429F_9D71_CE7384F57444__INCLUDED_)
#define AFX_SHOWGRAPHICSVIEW_H__45AE3021_3863_429F_9D71_CE7384F57444__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowGraphicsView : public CScrollView
{
protected: // create from serialization only
	CShowGraphicsView();
	DECLARE_DYNCREATE(CShowGraphicsView)

// Attributes
public:
	CShowGraphicsDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowGraphicsView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CShowGraphicsView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_nScale;	//缩放比例
	LPPICTURE	m_lPciture;//图像对象

// Generated message map functions
protected:
	//{{AFX_MSG(CShowGraphicsView)
	afx_msg void OnNormal();
	afx_msg void OnEnlarge();
	afx_msg void OnEnsmall();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowGraphicsView.cpp
inline CShowGraphicsDoc* CShowGraphicsView::GetDocument()
   { return (CShowGraphicsDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWGRAPHICSVIEW_H__45AE3021_3863_429F_9D71_CE7384F57444__INCLUDED_)
