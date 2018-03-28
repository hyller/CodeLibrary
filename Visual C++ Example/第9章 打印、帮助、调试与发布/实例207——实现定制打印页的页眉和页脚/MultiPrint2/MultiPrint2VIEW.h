// MultiPrint2View.h : interface of the CMultiPrint2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MultiPrint2VIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_)
#define AFX_MultiPrint2VIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiPrint2View : public CScrollView
{
protected: // create from serialization only
	CMultiPrint2View();
	DECLARE_DYNCREATE(CMultiPrint2View)

// Attributes
public:
	CMultiPrint2Doc* GetDocument();

// Operations
public:
	CRect m_rectPrint;
	int m_nPage;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiPrint2View)
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
	void PrintFooter(CDC *pDC);
	void PrintHeader(CDC *pDC);
	virtual ~CMultiPrint2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiPrint2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiPrint2View.cpp
inline CMultiPrint2Doc* CMultiPrint2View::GetDocument()
   { return (CMultiPrint2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiPrint2VIEW_H__5E75CE1E_C2D1_479F_8FB8_6597E86626B6__INCLUDED_)
