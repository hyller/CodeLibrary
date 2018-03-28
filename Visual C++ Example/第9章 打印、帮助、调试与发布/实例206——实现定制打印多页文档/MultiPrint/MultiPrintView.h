// MultiPrintView.h : interface of the CMultiPrintView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MultiPrintVIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_)
#define AFX_MultiPrintVIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiPrintView : public CScrollView
{
protected: // create from serialization only
	CMultiPrintView();
	DECLARE_DYNCREATE(CMultiPrintView)

// Attributes
public:
	CMultiPrintDoc* GetDocument();

// Operations
public:
	CRect m_rectPrint;
	int m_nPage;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiPrintView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMultiPrintView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiPrintView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiPrintView.cpp
inline CMultiPrintDoc* CMultiPrintView::GetDocument()
   { return (CMultiPrintDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiPrintVIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_)
