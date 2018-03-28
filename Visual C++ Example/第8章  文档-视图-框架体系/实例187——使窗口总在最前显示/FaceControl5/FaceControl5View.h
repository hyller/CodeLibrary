// FaceControl5View.h : interface of the CFaceControl5View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FaceControl5VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_)
#define AFX_FaceControl5VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFaceControl5View : public CView
{
protected: // create from serialization only
	CFaceControl5View();
	DECLARE_DYNCREATE(CFaceControl5View)

// Attributes
public:
	CFaceControl5Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceControl5View)
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
	virtual ~CFaceControl5View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	   COLORREF m_rgbBack;
	   BOOL m_bTop;
// Generated message map functions
protected:
	//{{AFX_MSG(CFaceControl5View)
	afx_msg void OnChageviewbk();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnChangeframeicon();
	afx_msg void OnChangechildicon();
	afx_msg void OnAlmosttop();
	afx_msg void OnUpdateAlmosttop(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FaceControl5View.cpp
inline CFaceControl5Doc* CFaceControl5View::GetDocument()
   { return (CFaceControl5Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FaceControl5VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_)
