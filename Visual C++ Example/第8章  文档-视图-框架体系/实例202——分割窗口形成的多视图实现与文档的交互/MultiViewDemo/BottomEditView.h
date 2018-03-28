#if !defined(AFX_BOTTOMEDIEVIEW_H__F41B76CE_BBB7_4C5B_B5C0_68EDACE2A6F1__INCLUDED_)
#define AFX_BOTTOMEDIEVIEW_H__F41B76CE_BBB7_4C5B_B5C0_68EDACE2A6F1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BottomEdieView.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBottomEditView view

class CBottomEditView : public CEditView
{
protected:
	CBottomEditView();           // protected constructor used by dynamic creation
	DECLARE_DYNCREATE(CBottomEditView)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBottomEditView)
	protected:
	virtual void OnDraw(CDC* pDC);      // overridden to draw this view
	virtual void OnInitialUpdate();
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
protected:
	virtual ~CBottomEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

	// Generated message map functions
protected:
	//{{AFX_MSG(CBottomEditView)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOTTOMEDIEVIEW_H__F41B76CE_BBB7_4C5B_B5C0_68EDACE2A6F1__INCLUDED_)
