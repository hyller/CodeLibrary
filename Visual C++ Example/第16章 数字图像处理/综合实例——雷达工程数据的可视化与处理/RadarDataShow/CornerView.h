#if !defined(AFX_CORNERVIEW_H__27EB98ED_5815_4E59_B8B9_45D4F2FF0262__INCLUDED_)
#define AFX_CORNERVIEW_H__27EB98ED_5815_4E59_B8B9_45D4F2FF0262__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CornerView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCornerView view

class CCornerView : public CView
{
protected:
	CCornerView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CCornerView)

// Attributes
public:

// Operations
public:
	int A_Num;//显示的A_Scan道数

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCornerView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CCornerView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CCornerView)
		// NOTE - the ClassWizard will add and remove member functions here.
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CORNERVIEW_H__27EB98ED_5815_4E59_B8B9_45D4F2FF0262__INCLUDED_)
