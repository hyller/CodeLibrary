// UseKeyHookView.h : interface of the CUseKeyHookView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_USEKEYHOOKVIEW_H__3FDD6535_57D7_4FDB_90B2_F78D6857B376__INCLUDED_)
#define AFX_USEKEYHOOKVIEW_H__3FDD6535_57D7_4FDB_90B2_F78D6857B376__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CUseKeyHookView : public CEditView
{
protected: // create from serialization only
	CUseKeyHookView();
	DECLARE_DYNCREATE(CUseKeyHookView)

// Attributes
public:
	CUseKeyHookDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CUseKeyHookView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CUseKeyHookView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CUseKeyHookView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in UseKeyHookView.cpp
inline CUseKeyHookDoc* CUseKeyHookView::GetDocument()
   { return (CUseKeyHookDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USEKEYHOOKVIEW_H__3FDD6535_57D7_4FDB_90B2_F78D6857B376__INCLUDED_)
