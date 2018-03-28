// LineDDADemoView.h : interface of the CLineDDADemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LINEDDADEMOVIEW_H__DE922EC1_3E5D_4255_9841_06405BA2711B__INCLUDED_)
#define AFX_LINEDDADEMOVIEW_H__DE922EC1_3E5D_4255_9841_06405BA2711B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLineDDADemoView : public CView
{
protected: // create from serialization only
	CLineDDADemoView();
	DECLARE_DYNCREATE(CLineDDADemoView)

// Attributes
public:
	CLineDDADemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLineDDADemoView)
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
	virtual ~CLineDDADemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLineDDADemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LineDDADemoView.cpp
inline CLineDDADemoDoc* CLineDDADemoView::GetDocument()
   { return (CLineDDADemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LINEDDADEMOVIEW_H__DE922EC1_3E5D_4255_9841_06405BA2711B__INCLUDED_)
