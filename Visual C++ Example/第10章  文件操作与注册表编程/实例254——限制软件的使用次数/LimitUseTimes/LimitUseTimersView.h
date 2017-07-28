// LimitUseTimersView.h : interface of the CLimitUseTimersView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_LIMITUSETIMERSVIEW_H__93942EBE_2DF6_4327_952F_5AFC840247CF__INCLUDED_)
#define AFX_LIMITUSETIMERSVIEW_H__93942EBE_2DF6_4327_952F_5AFC840247CF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CLimitUseTimersView : public CView
{
protected: // create from serialization only
	CLimitUseTimersView();
	DECLARE_DYNCREATE(CLimitUseTimersView)

// Attributes
public:
	CLimitUseTimersDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLimitUseTimersView)
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
	virtual ~CLimitUseTimersView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CLimitUseTimersView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in LimitUseTimersView.cpp
inline CLimitUseTimersDoc* CLimitUseTimersView::GetDocument()
   { return (CLimitUseTimersDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIMITUSETIMERSVIEW_H__93942EBE_2DF6_4327_952F_5AFC840247CF__INCLUDED_)
