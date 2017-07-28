// SolidFontDemoView.h : interface of the CSolidFontDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOLIDFONTDEMOVIEW_H__BC36AD05_7194_40AB_BE6C_7DDF5BEA7F0C__INCLUDED_)
#define AFX_SOLIDFONTDEMOVIEW_H__BC36AD05_7194_40AB_BE6C_7DDF5BEA7F0C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSolidFontDemoView : public CView
{
protected: // create from serialization only
	CSolidFontDemoView();
	DECLARE_DYNCREATE(CSolidFontDemoView)

// Attributes
public:
	CSolidFontDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSolidFontDemoView)
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
	virtual ~CSolidFontDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSolidFontDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SolidFontDemoView.cpp
inline CSolidFontDemoDoc* CSolidFontDemoView::GetDocument()
   { return (CSolidFontDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SOLIDFONTDEMOVIEW_H__BC36AD05_7194_40AB_BE6C_7DDF5BEA7F0C__INCLUDED_)
