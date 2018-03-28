// SuspendWndView.h : interface of the CSuspendWndView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SUSPENDWNDVIEW_H__9E7CAD85_6065_4130_9CCF_4AEE8ACEED9D__INCLUDED_)
#define AFX_SUSPENDWNDVIEW_H__9E7CAD85_6065_4130_9CCF_4AEE8ACEED9D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSuspendWndView : public CView
{
protected: // create from serialization only
	CSuspendWndView();
	DECLARE_DYNCREATE(CSuspendWndView)

// Attributes
public:
	CSuspendWndDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSuspendWndView)
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
	virtual ~CSuspendWndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSuspendWndView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SuspendWndView.cpp
inline CSuspendWndDoc* CSuspendWndView::GetDocument()
   { return (CSuspendWndDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SUSPENDWNDVIEW_H__9E7CAD85_6065_4130_9CCF_4AEE8ACEED9D__INCLUDED_)
