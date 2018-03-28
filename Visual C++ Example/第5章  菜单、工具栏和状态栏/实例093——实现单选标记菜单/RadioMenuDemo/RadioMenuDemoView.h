// RadioMenuDemoView.h : interface of the CRadioMenuDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RADIOMENUDEMOVIEW_H__D3C0C6BE_836C_47B6_83B5_1A5C0F321190__INCLUDED_)
#define AFX_RADIOMENUDEMOVIEW_H__D3C0C6BE_836C_47B6_83B5_1A5C0F321190__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRadioMenuDemoView : public CView
{
protected: // create from serialization only
	CRadioMenuDemoView();
	DECLARE_DYNCREATE(CRadioMenuDemoView)

// Attributes
public:
	CRadioMenuDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRadioMenuDemoView)
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
	virtual ~CRadioMenuDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_radiomode;

// Generated message map functions
protected:
	//{{AFX_MSG(CRadioMenuDemoView)
	afx_msg void OnMenucircle();
	afx_msg void OnUpdateMenucircle(CCmdUI* pCmdUI);
	afx_msg void OnMenurect();
	afx_msg void OnUpdateMenurect(CCmdUI* pCmdUI);
	afx_msg void OnMenutriangle();
	afx_msg void OnUpdateMenutriangle(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RadioMenuDemoView.cpp
inline CRadioMenuDemoDoc* CRadioMenuDemoView::GetDocument()
   { return (CRadioMenuDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RADIOMENUDEMOVIEW_H__D3C0C6BE_836C_47B6_83B5_1A5C0F321190__INCLUDED_)
