#if !defined(AFX_MYSCROLLVIEW_H__6A8184E1_BECF_44E5_8E67_F1CB7D4C71FF__INCLUDED_)
#define AFX_MYSCROLLVIEW_H__6A8184E1_BECF_44E5_8E67_F1CB7D4C71FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// MyScrollView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CMyScrollView view

class CMyScrollView : public CScrollView
{
protected:
	CMyScrollView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CMyScrollView)

// Attributes
public:

	// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMyScrollView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();     // first time after construct
	//}}AFX_VIRTUAL

// Implementation
protected:
		virtual ~CMyScrollView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
	//{{AFX_MSG(CMyScrollView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MYSCROLLVIEW_H__6A8184E1_BECF_44E5_8E67_F1CB7D4C71FF__INCLUDED_)
