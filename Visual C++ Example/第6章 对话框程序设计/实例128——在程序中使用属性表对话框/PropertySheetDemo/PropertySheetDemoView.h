// PropertySheetDemoView.h : interface of the CPropertySheetDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PROPERTYSHEETDEMOVIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_)
#define AFX_PROPERTYSHEETDEMOVIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPropertySheetDemoView : public CView
{
protected: // create from serialization only
	CPropertySheetDemoView();
	DECLARE_DYNCREATE(CPropertySheetDemoView)

// Attributes
public:
	CPropertySheetDemoDoc* GetDocument();

// Operations
public:
	int m_r,m_g,m_b,m_type;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheetDemoView)
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
	virtual ~CPropertySheetDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropertySheetDemoView)
	afx_msg void OnMenuset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PropertySheetDemoView.cpp
inline CPropertySheetDemoDoc* CPropertySheetDemoView::GetDocument()
   { return (CPropertySheetDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PROPERTYSHEETDEMOVIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_)
