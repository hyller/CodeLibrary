// ClipBmpDemoView.h : interface of the CClipBmpDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIPBMPDEMOVIEW_H__A0F80BD3_1238_4C5B_ACAD_7232EF89DF69__INCLUDED_)
#define AFX_CLIPBMPDEMOVIEW_H__A0F80BD3_1238_4C5B_ACAD_7232EF89DF69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CClipBmpDemoView : public CView
{
protected: // create from serialization only
	CClipBmpDemoView();
	DECLARE_DYNCREATE(CClipBmpDemoView)

// Attributes
public:
	CClipBmpDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClipBmpDemoView)
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
	virtual ~CClipBmpDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CBitmap bmp;
// Generated message map functions
protected:
	//{{AFX_MSG(CClipBmpDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ClipBmpDemoView.cpp
inline CClipBmpDemoDoc* CClipBmpDemoView::GetDocument()
   { return (CClipBmpDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIPBMPDEMOVIEW_H__A0F80BD3_1238_4C5B_ACAD_7232EF89DF69__INCLUDED_)
