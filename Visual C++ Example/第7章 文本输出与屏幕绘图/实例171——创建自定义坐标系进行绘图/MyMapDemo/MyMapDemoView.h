// MyMapDemoView.h : interface of the CMyMapDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MYMAPDEMOVIEW_H__FA344D0F_282C_4364_9FF8_E869C55C22AB__INCLUDED_)
#define AFX_MYMAPDEMOVIEW_H__FA344D0F_282C_4364_9FF8_E869C55C22AB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMyMapDemoView : public CView
{
protected: // create from serialization only
	CMyMapDemoView();
	DECLARE_DYNCREATE(CMyMapDemoView)

// Attributes
public:
	CMyMapDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyMapDemoView)
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
	virtual ~CMyMapDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMyMapDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MyMapDemoView.cpp
inline CMyMapDemoDoc* CMyMapDemoView::GetDocument()
   { return (CMyMapDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYMAPDEMOVIEW_H__FA344D0F_282C_4364_9FF8_E869C55C22AB__INCLUDED_)
