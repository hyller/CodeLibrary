// BaseMouseDemoView.h : interface of the CBaseMouseDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BASEMOUSEDEMOVIEW_H__8D347C4A_F42B_4FEB_A681_828C43D83E9D__INCLUDED_)
#define AFX_BASEMOUSEDEMOVIEW_H__8D347C4A_F42B_4FEB_A681_828C43D83E9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseMouseDemoView : public CView
{
protected: // create from serialization only
	CBaseMouseDemoView();
	DECLARE_DYNCREATE(CBaseMouseDemoView)

// Attributes
public:
	CBaseMouseDemoDoc* GetDocument();

	void DrawCircle();

// Operations
public:
	BOOL bDrag;									//是否在拉动
	CPoint ptDown;									//鼠标左键按下位置
	CPoint ptUp;									//鼠标左键释放位置


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseMouseDemoView)
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
	virtual ~CBaseMouseDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseMouseDemoView)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BaseMouseDemoView.cpp
inline CBaseMouseDemoDoc* CBaseMouseDemoView::GetDocument()
   { return (CBaseMouseDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BASEMOUSEDEMOVIEW_H__8D347C4A_F42B_4FEB_A681_828C43D83E9D__INCLUDED_)
