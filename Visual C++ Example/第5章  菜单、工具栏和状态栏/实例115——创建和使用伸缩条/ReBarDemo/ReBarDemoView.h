// ReBarDemoView.h : interface of the CReBarDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REBARDEMOVIEW_H__18C4B96C_A67E_44A3_BBB2_E5F3A6461E2D__INCLUDED_)
#define AFX_REBARDEMOVIEW_H__18C4B96C_A67E_44A3_BBB2_E5F3A6461E2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CReBarDemoView : public CView
{
protected: // create from serialization only
	CReBarDemoView();
	DECLARE_DYNCREATE(CReBarDemoView)

// Attributes
public:
	CReBarDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CReBarDemoView)
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
	virtual ~CReBarDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CReBarDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ReBarDemoView.cpp
inline CReBarDemoDoc* CReBarDemoView::GetDocument()
   { return (CReBarDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REBARDEMOVIEW_H__18C4B96C_A67E_44A3_BBB2_E5F3A6461E2D__INCLUDED_)
