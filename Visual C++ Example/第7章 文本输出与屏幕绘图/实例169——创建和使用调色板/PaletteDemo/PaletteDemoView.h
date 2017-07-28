// PaletteDemoView.h : interface of the CPaletteDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_PALETTEDEMOVIEW_H__BF96C31B_056E_44D1_89FA_5A0350119221__INCLUDED_)
#define AFX_PALETTEDEMOVIEW_H__BF96C31B_056E_44D1_89FA_5A0350119221__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CPaletteDemoView : public CView
{
protected: // create from serialization only
	CPaletteDemoView();
	DECLARE_DYNCREATE(CPaletteDemoView)
	CPalette m_Palette;								//声明调色板类对象
// Attributes
public:
	CPaletteDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPaletteDemoView)
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
	virtual ~CPaletteDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPaletteDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in PaletteDemoView.cpp
inline CPaletteDemoDoc* CPaletteDemoView::GetDocument()
   { return (CPaletteDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PALETTEDEMOVIEW_H__BF96C31B_056E_44D1_89FA_5A0350119221__INCLUDED_)
