// ChageTitleView.h : interface of the CChageTitleView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHAGETITLEVIEW_H__AD0EE47C_3C43_4035_8ADD_100EDBED4329__INCLUDED_)
#define AFX_CHAGETITLEVIEW_H__AD0EE47C_3C43_4035_8ADD_100EDBED4329__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CChageTitleView : public CView
{
protected: // create from serialization only
	CChageTitleView();
	DECLARE_DYNCREATE(CChageTitleView)

// Attributes
public:
	CChageTitleDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChageTitleView)
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
	virtual ~CChageTitleView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CChageTitleView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ChageTitleView.cpp
inline CChageTitleDoc* CChageTitleView::GetDocument()
   { return (CChageTitleDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHAGETITLEVIEW_H__AD0EE47C_3C43_4035_8ADD_100EDBED4329__INCLUDED_)
