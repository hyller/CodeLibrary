// FaceControl1View.h : interface of the CFaceControl1View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_FACECONTROL1VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_)
#define AFX_FACECONTROL1VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CFaceControl1View : public CView
{
protected: // create from serialization only
	CFaceControl1View();
	DECLARE_DYNCREATE(CFaceControl1View)

// Attributes
public:
	CFaceControl1Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFaceControl1View)
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
	virtual ~CFaceControl1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	   COLORREF m_rgbBack;
// Generated message map functions
protected:
	//{{AFX_MSG(CFaceControl1View)
	afx_msg void OnChageviewbk();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in FaceControl1View.cpp
inline CFaceControl1Doc* CFaceControl1View::GetDocument()
   { return (CFaceControl1Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FACECONTROL1VIEW_H__7C21D121_8C51_4A99_9E17_851DD389F0EA__INCLUDED_)
