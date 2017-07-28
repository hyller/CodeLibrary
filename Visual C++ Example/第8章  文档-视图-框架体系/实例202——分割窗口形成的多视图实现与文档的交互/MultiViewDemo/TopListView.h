#if !defined(AFX_TOPLISTVIEW_H__2CC9F2EA_71C7_4571_9704_477D9BD99D9F__INCLUDED_)
#define AFX_TOPLISTVIEW_H__2CC9F2EA_71C7_4571_9704_477D9BD99D9F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// TopListView.h : header file
//
#include "afxcview.h"//CListView的头文件
/////////////////////////////////////////////////////////////////////////////
// CTopListView view
#include "MultiViewDemoDoc.h"
class CTopListView : public CListView
{
protected:
	CTopListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CTopListView)
	//CListCtrl& listctrl;

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTopListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CTopListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CTopListView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TOPLISTVIEW_H__2CC9F2EA_71C7_4571_9704_477D9BD99D9F__INCLUDED_)
