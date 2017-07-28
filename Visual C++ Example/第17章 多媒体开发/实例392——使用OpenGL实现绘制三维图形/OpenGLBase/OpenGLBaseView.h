// OpenGLBaseView.h : interface of the COpenGLBaseView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OPENGLBASEVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_)
#define AFX_OPENGLBASEVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>


class COpenGLBaseView : public CView
{
protected: // create from serialization only
	COpenGLBaseView();
	DECLARE_DYNCREATE(COpenGLBaseView)

// Attributes
public:
	COpenGLBaseDoc* GetDocument();
	void DrawGLSquare(); 
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLBaseView)
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
	virtual ~COpenGLBaseView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CClientDC	*m_pDC;
	HGLRC		m_hglrc;

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLBaseView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OpenGLBaseView.cpp
inline COpenGLBaseDoc* COpenGLBaseView::GetDocument()
   { return (COpenGLBaseDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPENGLBASEVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_)
