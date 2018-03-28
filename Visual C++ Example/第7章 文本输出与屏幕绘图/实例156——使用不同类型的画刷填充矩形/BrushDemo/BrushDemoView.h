// BrushDemoView.h : interface of the CBrushDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BRUSHDEMOVIEW_H__CF05635A_28C1_4AE7_B1BF_93C701665C1D__INCLUDED_)
#define AFX_BRUSHDEMOVIEW_H__CF05635A_28C1_4AE7_B1BF_93C701665C1D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBrushDemoView : public CView
{
protected: // create from serialization only
	CBrushDemoView();
	DECLARE_DYNCREATE(CBrushDemoView)

// Attributes
public:
	CBrushDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBrushDemoView)
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
	virtual ~CBrushDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBrushDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BrushDemoView.cpp
inline CBrushDemoDoc* CBrushDemoView::GetDocument()
   { return (CBrushDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BRUSHDEMOVIEW_H__CF05635A_28C1_4AE7_B1BF_93C701665C1D__INCLUDED_)
