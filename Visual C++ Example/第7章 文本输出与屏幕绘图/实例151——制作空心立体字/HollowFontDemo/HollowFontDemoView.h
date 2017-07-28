// HollowFontDemoView.h : interface of the CHollowFontDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HOLLOWFONTDEMOVIEW_H__AA5752F4_0842_486C_BF96_45B737B9A0E6__INCLUDED_)
#define AFX_HOLLOWFONTDEMOVIEW_H__AA5752F4_0842_486C_BF96_45B737B9A0E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHollowFontDemoView : public CView
{
protected: // create from serialization only
	CHollowFontDemoView();
	DECLARE_DYNCREATE(CHollowFontDemoView)

// Attributes
public:
	CHollowFontDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHollowFontDemoView)
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
	virtual ~CHollowFontDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CFont m_font;//×ÖÌå¶ÔÏó
// Generated message map functions
protected:
	//{{AFX_MSG(CHollowFontDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HollowFontDemoView.cpp
inline CHollowFontDemoDoc* CHollowFontDemoView::GetDocument()
   { return (CHollowFontDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HOLLOWFONTDEMOVIEW_H__AA5752F4_0842_486C_BF96_45B737B9A0E6__INCLUDED_)
