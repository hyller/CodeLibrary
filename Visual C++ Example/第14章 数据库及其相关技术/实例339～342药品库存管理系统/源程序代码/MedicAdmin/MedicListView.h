#if !defined(AFX_MEDICLISTVIEW_H__1FA48425_9911_4BC6_B58D_7AD0903547BB__INCLUDED_)
#define AFX_MEDICLISTVIEW_H__1FA48425_9911_4BC6_B58D_7AD0903547BB__INCLUDED_

#include "saleSet.h"
#include "MedicSet.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MedicListView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMedicListView view

class CMedicListView : public CListView
{
protected:
	CMedicListView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMedicListView)

// Attributes
public:

// Operations
public:
	CListCtrl* theListCtrl;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMedicListView)
	public:
	virtual void OnInitialUpdate();
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CMedicListView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	CSaleSet* saleSet;
	CMedicSet* medicSet;
	//{{AFX_MSG(CMedicListView)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MEDICLISTVIEW_H__1FA48425_9911_4BC6_B58D_7AD0903547BB__INCLUDED_)
