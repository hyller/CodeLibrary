// RefrainChildView.h : interface of the CRefrainChildView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_REFRAINCHILDVIEW_H__73E4BFC8_510D_4128_8FE2_ED685205472B__INCLUDED_)
#define AFX_REFRAINCHILDVIEW_H__73E4BFC8_510D_4128_8FE2_ED685205472B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRefrainChildView : public CView
{
protected: // create from serialization only
	CRefrainChildView();
	DECLARE_DYNCREATE(CRefrainChildView)

// Attributes
public:
	CRefrainChildDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRefrainChildView)
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
	virtual ~CRefrainChildView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRefrainChildView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RefrainChildView.cpp
inline CRefrainChildDoc* CRefrainChildView::GetDocument()
   { return (CRefrainChildDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_REFRAINCHILDVIEW_H__73E4BFC8_510D_4128_8FE2_ED685205472B__INCLUDED_)
