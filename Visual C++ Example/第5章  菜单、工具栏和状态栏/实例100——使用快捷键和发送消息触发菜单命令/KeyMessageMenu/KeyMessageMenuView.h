// KeyMessageMenuView.h : interface of the CKeyMessageMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEYMESSAGEMENUVIEW_H__045FA2CD_B25F_4DE6_8CEA_B4BD8E894262__INCLUDED_)
#define AFX_KEYMESSAGEMENUVIEW_H__045FA2CD_B25F_4DE6_8CEA_B4BD8E894262__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKeyMessageMenuView : public CView
{
protected: // create from serialization only
	CKeyMessageMenuView();
	DECLARE_DYNCREATE(CKeyMessageMenuView)

// Attributes
public:
	CKeyMessageMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyMessageMenuView)
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
	virtual ~CKeyMessageMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKeyMessageMenuView)
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KeyMessageMenuView.cpp
inline CKeyMessageMenuDoc* CKeyMessageMenuView::GetDocument()
   { return (CKeyMessageMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYMESSAGEMENUVIEW_H__045FA2CD_B25F_4DE6_8CEA_B4BD8E894262__INCLUDED_)
