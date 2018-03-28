// DyBMPMovieView.h : interface of the CDyBMPMovieView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYBMPMOVIEVIEW_H__81FB2EB3_7C3F_405E_98E5_1A20C9579C30__INCLUDED_)
#define AFX_DYBMPMOVIEVIEW_H__81FB2EB3_7C3F_405E_98E5_1A20C9579C30__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDyBMPMovieView : public CView
{
protected: // create from serialization only
	CDyBMPMovieView();
	DECLARE_DYNCREATE(CDyBMPMovieView)

// Attributes
public:
	CDyBMPMovieDoc* GetDocument();

// Operations
public:
private:
	CBitmap		m_Bitmap[6];    //装载要显示位图对象
	int			m_nFrameWidth;          //图象宽度
	int			m_nFrameHeight;         //图象高度
	CPoint		m_ptCurPos;				//当前的滚动位置	
	int			m_nCurFrameNo;          //当前显示的图象编号
	int			m_nStepX;				//水平方向上的步进量
	int			m_nStepY;               //垂直方向上的步进量
	CBrush      m_BKBrush;				//用来创建所需的背景刷子
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDyBMPMovieView)
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
	virtual ~CDyBMPMovieView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDyBMPMovieView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DyBMPMovieView.cpp
inline CDyBMPMovieDoc* CDyBMPMovieView::GetDocument()
   { return (CDyBMPMovieDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYBMPMOVIEVIEW_H__81FB2EB3_7C3F_405E_98E5_1A20C9579C30__INCLUDED_)
