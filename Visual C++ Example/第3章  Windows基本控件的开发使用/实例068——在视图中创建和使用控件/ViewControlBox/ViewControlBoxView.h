// ViewControlBoxView.h : interface of the CViewControlBoxView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIEWCONTROLBOXVIEW_H__B9065319_DD8A_4B43_A733_8F224F3D7E9C__INCLUDED_)
#define AFX_VIEWCONTROLBOXVIEW_H__B9065319_DD8A_4B43_A733_8F224F3D7E9C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CViewControlBoxView : public CView
{
protected: // create from serialization only
	CViewControlBoxView();
	DECLARE_DYNCREATE(CViewControlBoxView)

// Attributes
public:
	CViewControlBoxDoc* GetDocument();
	CButton m_button;//定义按钮对象
	CListBox m_listbox;//定义列表框对象

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CViewControlBoxView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext = NULL);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CViewControlBoxView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CViewControlBoxView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnClickButton();//按钮控件的消息响应函数
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ViewControlBoxView.cpp
inline CViewControlBoxDoc* CViewControlBoxView::GetDocument()
   { return (CViewControlBoxDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIEWCONTROLBOXVIEW_H__B9065319_DD8A_4B43_A733_8F224F3D7E9C__INCLUDED_)
