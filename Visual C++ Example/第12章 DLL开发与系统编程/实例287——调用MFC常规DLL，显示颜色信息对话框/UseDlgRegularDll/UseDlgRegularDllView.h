// UseDlgRegularDllView.h : interface of the CUseDlgRegularDllView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEDLGREGULARDLLVIEW_H__4C2AAA79_FD61_43D0_B60B_911318B05032__INCLUDED_)
#define AFX_USEDLGREGULARDLLVIEW_H__4C2AAA79_FD61_43D0_B60B_911318B05032__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUseDlgRegularDllView : public CView
{
protected: // create from serialization only
	CUseDlgRegularDllView();
	DECLARE_DYNCREATE(CUseDlgRegularDllView)

// Attributes
public:
	CUseDlgRegularDllDoc* GetDocument();

// Operations
public:
	
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseDlgRegularDllView)
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
	virtual ~CUseDlgRegularDllView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_r,m_g,m_b;

// Generated message map functions
protected:
	//{{AFX_MSG(CUseDlgRegularDllView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UseDlgRegularDllView.cpp
inline CUseDlgRegularDllDoc* CUseDlgRegularDllView::GetDocument()
   { return (CUseDlgRegularDllDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEDLGREGULARDLLVIEW_H__4C2AAA79_FD61_43D0_B60B_911318B05032__INCLUDED_)
