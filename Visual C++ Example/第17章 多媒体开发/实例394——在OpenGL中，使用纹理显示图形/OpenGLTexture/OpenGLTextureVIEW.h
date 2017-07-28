// OpenGLTextureView.h : interface of the COpenGLTextureView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_OpenGLTextureVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_)
#define AFX_OpenGLTextureVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <gl/gl.h>
#include <gl/glu.h>
#include <gl/glaux.h>
#define IMAGEWIDTH 32
#define IMAGEHEIGHT 32

class COpenGLTextureView : public CView
{
protected: // create from serialization only
	COpenGLTextureView();
	DECLARE_DYNCREATE(COpenGLTextureView)

// Attributes
public:
	COpenGLTextureDoc* GetDocument();
	void DrawGLSquare(float x1,float y1,float x2,float y2); 
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COpenGLTextureView)
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
	virtual ~COpenGLTextureView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	CClientDC	*m_pDC;
	HGLRC		m_hglrc;
	float distance; // init value
	GLubyte Image[IMAGEWIDTH][IMAGEHEIGHT][4]; // textureÊý¾Ý

// Generated message map functions
protected:
	//{{AFX_MSG(COpenGLTextureView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in OpenGLTextureView.cpp
inline COpenGLTextureDoc* COpenGLTextureView::GetDocument()
   { return (COpenGLTextureDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OpenGLTextureVIEW_H__4D0BCC8D_D5E7_40AE_B598_98707162A3D5__INCLUDED_)
