// FaceControl3View.h : interface of the CFaceControl3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FaceControl3VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_)
#define AFX_FaceControl3VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFaceControl3View : public CView
{
protected: // create from serialization only
	CFaceControl3View();
	DECLARE_DYNCREATE(CFaceControl3View)

// Attributes
public:
	CFaceControl3Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceControl3View)
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
	virtual ~CFaceControl3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	   COLORREF m_rgbBack;
// Generated message map functions
protected:
	//{{AFX_MSG(CFaceControl3View)
	afx_msg void OnChageviewbk();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnChangeframeicon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FaceControl3View.cpp
inline CFaceControl3Doc* CFaceControl3View::GetDocument()
   { return (CFaceControl3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FaceControl3VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_)
