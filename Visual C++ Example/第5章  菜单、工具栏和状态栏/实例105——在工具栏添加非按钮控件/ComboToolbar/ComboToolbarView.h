// ComboToolbarView.h : interface of the CComboToolbarView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMBOTOOLBARVIEW_H__EA8455C1_CA25_46F3_8C73_9F9C29E7AB4D__INCLUDED_)
#define AFX_COMBOTOOLBARVIEW_H__EA8455C1_CA25_46F3_8C73_9F9C29E7AB4D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CComboToolbarView : public CView
{
protected: // create from serialization only
	CComboToolbarView();
	DECLARE_DYNCREATE(CComboToolbarView)

// Attributes
public:
	CComboToolbarDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboToolbarView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

	afx_msg void OnSelchangeCombo( );					//响应CBN_SELCHANGE消息的函数
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CComboToolbarView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CComboToolbarView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ComboToolbarView.cpp
inline CComboToolbarDoc* CComboToolbarView::GetDocument()
   { return (CComboToolbarDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOTOOLBARVIEW_H__EA8455C1_CA25_46F3_8C73_9F9C29E7AB4D__INCLUDED_)
