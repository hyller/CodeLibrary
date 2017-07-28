// SelectMunuView.h : interface of the CSelectMunuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_SELECTMUNUVIEW_H__E0B0B662_D287_47CA_8EF9_AC8B01E176EE__INCLUDED_)
#define AFX_SELECTMUNUVIEW_H__E0B0B662_D287_47CA_8EF9_AC8B01E176EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSelectMunuView : public CView
{
protected: // create from serialization only
	CSelectMunuView();
	DECLARE_DYNCREATE(CSelectMunuView)

// Attributes
public:
	CSelectMunuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSelectMunuView)
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
	virtual ~CSelectMunuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CSelectMunuView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in SelectMunuView.cpp
inline CSelectMunuDoc* CSelectMunuView::GetDocument()
   { return (CSelectMunuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SELECTMUNUVIEW_H__E0B0B662_D287_47CA_8EF9_AC8B01E176EE__INCLUDED_)
