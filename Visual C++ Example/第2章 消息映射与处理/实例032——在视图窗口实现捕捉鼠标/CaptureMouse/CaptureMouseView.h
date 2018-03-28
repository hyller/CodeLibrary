// CaptureMouseView.h : interface of the CCaptureMouseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CAPTUREMOUSEVIEW_H__4A921168_CA77_4435_807E_5EF47592EEC7__INCLUDED_)
#define AFX_CAPTUREMOUSEVIEW_H__4A921168_CA77_4435_807E_5EF47592EEC7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCaptureMouseView : public CView
{
protected: // create from serialization only
	CCaptureMouseView();
	DECLARE_DYNCREATE(CCaptureMouseView)

// Attributes
public:
	CCaptureMouseDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCaptureMouseView)
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
	virtual ~CCaptureMouseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCaptureMouseView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CaptureMouseView.cpp
inline CCaptureMouseDoc* CCaptureMouseView::GetDocument()
   { return (CCaptureMouseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CAPTUREMOUSEVIEW_H__4A921168_CA77_4435_807E_5EF47592EEC7__INCLUDED_)
