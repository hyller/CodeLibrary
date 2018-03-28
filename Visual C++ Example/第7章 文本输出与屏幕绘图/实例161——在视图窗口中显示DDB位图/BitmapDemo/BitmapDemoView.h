// BitmapDemoView.h : interface of the CBitmapDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPDEMOVIEW_H__E02F4D72_FEFB_4DB6_8A5B_7F9DF074AB8E__INCLUDED_)
#define AFX_BITMAPDEMOVIEW_H__E02F4D72_FEFB_4DB6_8A5B_7F9DF074AB8E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBitmapDemoView : public CView
{
protected: // create from serialization only
	CBitmapDemoView();
	DECLARE_DYNCREATE(CBitmapDemoView)

// Attributes
public:
	CBitmapDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapDemoView)
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
	virtual ~CBitmapDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BitmapDemoView.cpp
inline CBitmapDemoDoc* CBitmapDemoView::GetDocument()
   { return (CBitmapDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPDEMOVIEW_H__E02F4D72_FEFB_4DB6_8A5B_7F9DF074AB8E__INCLUDED_)
