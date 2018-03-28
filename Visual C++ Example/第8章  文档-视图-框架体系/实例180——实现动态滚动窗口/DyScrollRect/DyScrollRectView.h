// DyScrollRectView.h : interface of the CDyScrollRectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYSCROLLRECTVIEW_H__653D26E9_F3D8_4CF9_B135_0E5058897389__INCLUDED_)
#define AFX_DYSCROLLRECTVIEW_H__653D26E9_F3D8_4CF9_B135_0E5058897389__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDyScrollRectView : public CScrollView
{
protected: // create from serialization only
	CDyScrollRectView();
	DECLARE_DYNCREATE(CDyScrollRectView)

// Attributes
public:
	CDyScrollRectDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyScrollRectView)
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
	virtual ~CDyScrollRectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CSize sizetemp;//图形区域
	int lable;//矩形标识

// Generated message map functions
protected:
	//{{AFX_MSG(CDyScrollRectView)
	afx_msg void OnMenurect1();
	afx_msg void OnMenurect2();
	afx_msg void OnMenurect3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DyScrollRectView.cpp
inline CDyScrollRectDoc* CDyScrollRectView::GetDocument()
   { return (CDyScrollRectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYSCROLLRECTVIEW_H__653D26E9_F3D8_4CF9_B135_0E5058897389__INCLUDED_)
