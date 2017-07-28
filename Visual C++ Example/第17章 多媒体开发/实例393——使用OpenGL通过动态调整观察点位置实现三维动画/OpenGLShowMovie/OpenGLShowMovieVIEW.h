// OpenGLShowMovieView.h : interface of the COpenGLShowMovieView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OpenGLShowMovieVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_)
#define AFX_OpenGLShowMovieVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>


class COpenGLShowMovieView : public CView
{
protected: // create from serialization only
	COpenGLShowMovieView();
	DECLARE_DYNCREATE(COpenGLShowMovieView)
	void GetEye(double r, int hd, int vd, GLdouble &ex, GLdouble &ey, GLdouble &ez);
// Attributes
public:
	COpenGLShowMovieDoc* GetDocument();
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLShowMovieView)
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
	virtual ~COpenGLShowMovieView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CClientDC	*m_pDC;
	HGLRC		m_hglrc;
	int hDegree,vDegree;
	bool ctrl;
	double r,ex,ey,ez;

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLShowMovieView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OpenGLShowMovieView.cpp
inline COpenGLShowMovieDoc* COpenGLShowMovieView::GetDocument()
   { return (COpenGLShowMovieDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OpenGLShowMovieVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_)
