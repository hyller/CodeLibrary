// TransBmpDemoView.h : interface of the CTransBmpDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRANSBMPDEMOVIEW_H__D026D36E_B8FF_40BD_B262_0F5B9560FF2D__INCLUDED_)
#define AFX_TRANSBMPDEMOVIEW_H__D026D36E_B8FF_40BD_B262_0F5B9560FF2D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTransBmpDemoView : public CView
{
protected: // create from serialization only
	CTransBmpDemoView();
	DECLARE_DYNCREATE(CTransBmpDemoView)

// Attributes
public:
	CTransBmpDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTransBmpDemoView)
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
	virtual ~CTransBmpDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	void DrawTransparent(CDC* pDC,int x, int y, COLORREF crColour);
// Generated message map functions
protected:
	//{{AFX_MSG(CTransBmpDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TransBmpDemoView.cpp
inline CTransBmpDemoDoc* CTransBmpDemoView::GetDocument()
   { return (CTransBmpDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRANSBMPDEMOVIEW_H__D026D36E_B8FF_40BD_B262_0F5B9560FF2D__INCLUDED_)
