// StatusComboView.h : interface of the CStatusComboView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_STATUSCOMBOVIEW_H__8516154C_D137_41AE_BAE4_F86BC07EC23E__INCLUDED_)
#define AFX_STATUSCOMBOVIEW_H__8516154C_D137_41AE_BAE4_F86BC07EC23E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CStatusComboView : public CView
{
protected: // create from serialization only
	CStatusComboView();
	DECLARE_DYNCREATE(CStatusComboView)

// Attributes
public:
	CStatusComboDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CStatusComboView)
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
	virtual ~CStatusComboView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CStatusComboView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in StatusComboView.cpp
inline CStatusComboDoc* CStatusComboView::GetDocument()
   { return (CStatusComboDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_STATUSCOMBOVIEW_H__8516154C_D137_41AE_BAE4_F86BC07EC23E__INCLUDED_)
