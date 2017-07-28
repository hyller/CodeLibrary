// MirroBmpDemoView.h : interface of the CMirroBmpDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MIRROBMPDEMOVIEW_H__084B448D_D817_493C_A7D6_E61AAFF7B9C5__INCLUDED_)
#define AFX_MIRROBMPDEMOVIEW_H__084B448D_D817_493C_A7D6_E61AAFF7B9C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMirroBmpDemoView : public CView
{
protected: // create from serialization only
	CMirroBmpDemoView();
	DECLARE_DYNCREATE(CMirroBmpDemoView)

// Attributes
public:
	CMirroBmpDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMirroBmpDemoView)
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
	virtual ~CMirroBmpDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CBitmap m_Bitmap;
// Generated message map functions
protected:
	//{{AFX_MSG(CMirroBmpDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MirroBmpDemoView.cpp
inline CMirroBmpDemoDoc* CMirroBmpDemoView::GetDocument()
   { return (CMirroBmpDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MIRROBMPDEMOVIEW_H__084B448D_D817_493C_A7D6_E61AAFF7B9C5__INCLUDED_)
