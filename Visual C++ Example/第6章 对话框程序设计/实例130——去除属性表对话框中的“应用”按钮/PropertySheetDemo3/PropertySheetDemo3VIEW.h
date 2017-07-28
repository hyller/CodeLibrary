// PropertySheetDemo3View.h : interface of the CPropertySheetDemo3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PropertySheetDemo3VIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_)
#define AFX_PropertySheetDemo3VIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPropertySheetDemo3View : public CView
{
protected: // create from serialization only
	CPropertySheetDemo3View();
	DECLARE_DYNCREATE(CPropertySheetDemo3View)

// Attributes
public:
	CPropertySheetDemo3Doc* GetDocument();

// Operations
public:
	int m_r,m_g,m_b,m_type;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPropertySheetDemo3View)
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
	virtual ~CPropertySheetDemo3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPropertySheetDemo3View)
	afx_msg void OnMenuset();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PropertySheetDemo3View.cpp
inline CPropertySheetDemo3Doc* CPropertySheetDemo3View::GetDocument()
   { return (CPropertySheetDemo3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PropertySheetDemo3VIEW_H__E553CEF2_18B7_4D50_981B_CAB8887D9DC0__INCLUDED_)
