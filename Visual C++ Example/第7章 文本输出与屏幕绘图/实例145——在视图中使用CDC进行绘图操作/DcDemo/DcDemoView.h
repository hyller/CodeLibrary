// DcDemoView.h : interface of the CDcDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DCDEMOVIEW_H__F0E154B3_62AE_4407_8CAE_E79CBC044B4A__INCLUDED_)
#define AFX_DCDEMOVIEW_H__F0E154B3_62AE_4407_8CAE_E79CBC044B4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDcDemoView : public CView
{
protected: // create from serialization only
	CDcDemoView();
	DECLARE_DYNCREATE(CDcDemoView)

// Attributes
public:
	CDcDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDcDemoView)
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
	virtual ~CDcDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDcDemoView)
	afx_msg void OnMenucircle();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DcDemoView.cpp
inline CDcDemoDoc* CDcDemoView::GetDocument()
   { return (CDcDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DCDEMOVIEW_H__F0E154B3_62AE_4407_8CAE_E79CBC044B4A__INCLUDED_)
