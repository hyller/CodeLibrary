// StarFaceDemoView.h : interface of the CStarFaceDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STARFACEDEMOVIEW_H__8F1063B8_C0A1_4099_BFC0_80ABDDCDF07C__INCLUDED_)
#define AFX_STARFACEDEMOVIEW_H__8F1063B8_C0A1_4099_BFC0_80ABDDCDF07C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStarFaceDemoView : public CView
{
protected: // create from serialization only
	CStarFaceDemoView();
	DECLARE_DYNCREATE(CStarFaceDemoView)

// Attributes
public:
	CStarFaceDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStarFaceDemoView)
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
	virtual ~CStarFaceDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStarFaceDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StarFaceDemoView.cpp
inline CStarFaceDemoDoc* CStarFaceDemoView::GetDocument()
   { return (CStarFaceDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STARFACEDEMOVIEW_H__8F1063B8_C0A1_4099_BFC0_80ABDDCDF07C__INCLUDED_)
