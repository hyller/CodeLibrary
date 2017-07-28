// ShowEffectView.h : interface of the CShowEffectView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SHOWEFFECTVIEW_H__A485A160_60FC_4969_B25E_4BA74D0B8960__INCLUDED_)
#define AFX_SHOWEFFECTVIEW_H__A485A160_60FC_4969_B25E_4BA74D0B8960__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowEffectView : public CView
{
protected: // create from serialization only
	CShowEffectView();
	DECLARE_DYNCREATE(CShowEffectView)

// Attributes
public:
	CShowEffectDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowEffectView)
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
	virtual ~CShowEffectView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowEffectView)
	afx_msg void OnBlock();
	//}}AFX_MSG
	afx_msg void OnImageScan(UINT nID);//扫描
	afx_msg void OnImageMove(UINT nID);//移动
	afx_msg void OnImageJalousie(UINT nID);//百叶窗
	afx_msg void OnImageGrid(UINT nID);//栅格交错
	afx_msg void OnImageStunt(UINT nID);//伸缩特效
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowEffectView.cpp
inline CShowEffectDoc* CShowEffectView::GetDocument()
   { return (CShowEffectDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWEFFECTVIEW_H__A485A160_60FC_4969_B25E_4BA74D0B8960__INCLUDED_)
