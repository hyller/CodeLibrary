// NoMoveResizeView.h : interface of the CNoMoveResizeView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_NOMOVERESIZEVIEW_H__BCB60E06_D67C_486F_9F90_FBA5A0ECC127__INCLUDED_)
#define AFX_NOMOVERESIZEVIEW_H__BCB60E06_D67C_486F_9F90_FBA5A0ECC127__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CNoMoveResizeView : public CView
{
protected: // create from serialization only
	CNoMoveResizeView();
	DECLARE_DYNCREATE(CNoMoveResizeView)

// Attributes
public:
	CNoMoveResizeDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNoMoveResizeView)
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
	virtual ~CNoMoveResizeView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CNoMoveResizeView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in NoMoveResizeView.cpp
inline CNoMoveResizeDoc* CNoMoveResizeView::GetDocument()
   { return (CNoMoveResizeDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NOMOVERESIZEVIEW_H__BCB60E06_D67C_486F_9F90_FBA5A0ECC127__INCLUDED_)
