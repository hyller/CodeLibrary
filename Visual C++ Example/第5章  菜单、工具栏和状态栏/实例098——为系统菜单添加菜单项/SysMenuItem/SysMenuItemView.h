// SysMenuItemView.h : interface of the CSysMenuItemView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SYSMENUITEMVIEW_H__50E800CD_6273_4F29_8460_FCE83F18D007__INCLUDED_)
#define AFX_SYSMENUITEMVIEW_H__50E800CD_6273_4F29_8460_FCE83F18D007__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSysMenuItemView : public CView
{
protected: // create from serialization only
	CSysMenuItemView();
	DECLARE_DYNCREATE(CSysMenuItemView)

// Attributes
public:
	CSysMenuItemDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSysMenuItemView)
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
	virtual ~CSysMenuItemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSysMenuItemView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SysMenuItemView.cpp
inline CSysMenuItemDoc* CSysMenuItemView::GetDocument()
   { return (CSysMenuItemDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SYSMENUITEMVIEW_H__50E800CD_6273_4F29_8460_FCE83F18D007__INCLUDED_)
