// SinglePrintView.h : interface of the CSinglePrintView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SINGLEPRINTVIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_)
#define AFX_SINGLEPRINTVIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSinglePrintView : public CScrollView
{
protected: // create from serialization only
	CSinglePrintView();
	DECLARE_DYNCREATE(CSinglePrintView)

// Attributes
public:
	CSinglePrintDoc* GetDocument();

// Operations
public:
	CRect m_rectPrint;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSinglePrintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CSinglePrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSinglePrintView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SinglePrintView.cpp
inline CSinglePrintDoc* CSinglePrintView::GetDocument()
   { return (CSinglePrintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SINGLEPRINTVIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_)
