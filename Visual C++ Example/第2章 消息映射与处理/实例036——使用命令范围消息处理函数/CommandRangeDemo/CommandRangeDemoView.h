// CommandRangeDemoView.h : interface of the CCommandRangeDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMMANDRANGEDEMOVIEW_H__BD63C670_D94A_482E_9D07_E0F745CCA76C__INCLUDED_)
#define AFX_COMMANDRANGEDEMOVIEW_H__BD63C670_D94A_482E_9D07_E0F745CCA76C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CCommandRangeDemoView : public CView
{
protected: // create from serialization only
	CCommandRangeDemoView();
	DECLARE_DYNCREATE(CCommandRangeDemoView)

// Attributes
public:
	CCommandRangeDemoDoc* GetDocument();

// Operations
public:
	int m_radio;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCommandRangeDemoView)
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
	virtual ~CCommandRangeDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CCommandRangeDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	afx_msg void OnMenuItemCommandRange(UINT nID);
	afx_msg void OnUpdateMenuItemCommandRange(CCmdUI* pCCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in CommandRangeDemoView.cpp
inline CCommandRangeDemoDoc* CCommandRangeDemoView::GetDocument()
   { return (CCommandRangeDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMMANDRANGEDEMOVIEW_H__BD63C670_D94A_482E_9D07_E0F745CCA76C__INCLUDED_)
