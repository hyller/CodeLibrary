// PenDemoView.h : interface of the CPenDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PENDEMOVIEW_H__AF10F007_777E_4CD7_92F4_77CDDD93F492__INCLUDED_)
#define AFX_PENDEMOVIEW_H__AF10F007_777E_4CD7_92F4_77CDDD93F492__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPenDemoView : public CView
{
protected: // create from serialization only
	CPenDemoView();
	DECLARE_DYNCREATE(CPenDemoView)

// Attributes
public:
	CPenDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPenDemoView)
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
	virtual ~CPenDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPenDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PenDemoView.cpp
inline CPenDemoDoc* CPenDemoView::GetDocument()
   { return (CPenDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PENDEMOVIEW_H__AF10F007_777E_4CD7_92F4_77CDDD93F492__INCLUDED_)
