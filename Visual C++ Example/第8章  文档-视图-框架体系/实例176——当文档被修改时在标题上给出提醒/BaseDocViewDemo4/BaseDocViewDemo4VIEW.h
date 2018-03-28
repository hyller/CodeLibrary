// BaseDocViewDemo4View.h : interface of the CBaseDocViewDemo4View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BaseDocViewDemo4VIEW_H__87EB8DEC_3B19_404C_8AB9_E5DF802CAB56__INCLUDED_)
#define AFX_BaseDocViewDemo4VIEW_H__87EB8DEC_3B19_404C_8AB9_E5DF802CAB56__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseDocViewDemo4View : public CView
{
protected: // create from serialization only
	CBaseDocViewDemo4View();
	DECLARE_DYNCREATE(CBaseDocViewDemo4View)

// Attributes
public:
	CBaseDocViewDemo4Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDocViewDemo4View)
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
	virtual ~CBaseDocViewDemo4View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool m_bDraw;											//绘图标识
	HCURSOR m_Hcursor;									//光标对象
	CPoint m_pOld;											//记录鼠标位置

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDocViewDemo4View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BaseDocViewDemo4View.cpp
inline CBaseDocViewDemo4Doc* CBaseDocViewDemo4View::GetDocument()
   { return (CBaseDocViewDemo4Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDocViewDemo4VIEW_H__87EB8DEC_3B19_404C_8AB9_E5DF802CAB56__INCLUDED_)
