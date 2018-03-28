// GradientTextDemoView.h : interface of the CGradientTextDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_GRADIENTTEXTDEMOVIEW_H__DC91106A_2933_4316_A173_FAD431844B04__INCLUDED_)
#define AFX_GRADIENTTEXTDEMOVIEW_H__DC91106A_2933_4316_A173_FAD431844B04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CGradientTextDemoView : public CView
{
protected: // create from serialization only
	CGradientTextDemoView();
	DECLARE_DYNCREATE(CGradientTextDemoView)

// Attributes
public:
	CGradientTextDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGradientTextDemoView)
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
	virtual ~CGradientTextDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CGradientTextDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in GradientTextDemoView.cpp
inline CGradientTextDemoDoc* CGradientTextDemoView::GetDocument()
   { return (CGradientTextDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GRADIENTTEXTDEMOVIEW_H__DC91106A_2933_4316_A173_FAD431844B04__INCLUDED_)
