// BitmapMenuView.h : interface of the CBitmapMenuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BITMAPMENUVIEW_H__ED0B82D2_87A6_40FD_A982_5F3D1633DFFB__INCLUDED_)
#define AFX_BITMAPMENUVIEW_H__ED0B82D2_87A6_40FD_A982_5F3D1633DFFB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBitmapMenuView : public CView
{
protected: // create from serialization only
	CBitmapMenuView();
	DECLARE_DYNCREATE(CBitmapMenuView)

// Attributes
public:
	CBitmapMenuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBitmapMenuView)
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
	virtual ~CBitmapMenuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBitmapMenuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BitmapMenuView.cpp
inline CBitmapMenuDoc* CBitmapMenuView::GetDocument()
   { return (CBitmapMenuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BITMAPMENUVIEW_H__ED0B82D2_87A6_40FD_A982_5F3D1633DFFB__INCLUDED_)
