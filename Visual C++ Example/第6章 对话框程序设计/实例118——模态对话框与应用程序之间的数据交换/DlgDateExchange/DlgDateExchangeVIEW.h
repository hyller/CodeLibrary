// DlgDateExchangeView.h : interface of the CDlgDateExchangeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DlgDateExchangeVIEW_H__107CDFA9_7550_4F0C_8958_F4AD86F1FCF1__INCLUDED_)
#define AFX_DlgDateExchangeVIEW_H__107CDFA9_7550_4F0C_8958_F4AD86F1FCF1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDlgDateExchangeView : public CView
{
protected: // create from serialization only
	CDlgDateExchangeView();
	DECLARE_DYNCREATE(CDlgDateExchangeView)

// Attributes
public:
	CDlgDateExchangeDoc* GetDocument();
	int r,g,b;//定义颜色值

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlgDateExchangeView)
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
	virtual ~CDlgDateExchangeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDlgDateExchangeView)
	afx_msg void OnSetcolor();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DlgDateExchangeView.cpp
inline CDlgDateExchangeDoc* CDlgDateExchangeView::GetDocument()
   { return (CDlgDateExchangeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DlgDateExchangeVIEW_H__107CDFA9_7550_4F0C_8958_F4AD86F1FCF1__INCLUDED_)
