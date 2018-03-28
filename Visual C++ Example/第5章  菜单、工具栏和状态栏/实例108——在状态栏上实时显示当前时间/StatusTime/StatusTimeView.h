// StatusTimeView.h : interface of the CStatusTimeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSTIMEVIEW_H__9EB03F12_5309_4CC3_9CDD_8EEC96AE637C__INCLUDED_)
#define AFX_STATUSTIMEVIEW_H__9EB03F12_5309_4CC3_9CDD_8EEC96AE637C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusTimeView : public CView
{
protected: // create from serialization only
	CStatusTimeView();
	DECLARE_DYNCREATE(CStatusTimeView)

// Attributes
public:
	CStatusTimeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusTimeView)
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
	virtual ~CStatusTimeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusTimeView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StatusTimeView.cpp
inline CStatusTimeDoc* CStatusTimeView::GetDocument()
   { return (CStatusTimeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSTIMEVIEW_H__9EB03F12_5309_4CC3_9CDD_8EEC96AE637C__INCLUDED_)
