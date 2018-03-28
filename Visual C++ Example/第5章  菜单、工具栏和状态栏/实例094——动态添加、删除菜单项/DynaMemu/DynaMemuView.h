// DynaMemuView.h : interface of the CDynaMemuView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYNAMEMUVIEW_H__7653380A_191E_4BDF_AC57_CBAF32E11D0B__INCLUDED_)
#define AFX_DYNAMEMUVIEW_H__7653380A_191E_4BDF_AC57_CBAF32E11D0B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDynaMemuView : public CView
{
protected: // create from serialization only
	CDynaMemuView();
	DECLARE_DYNCREATE(CDynaMemuView)

// Attributes
public:
	CDynaMemuDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDynaMemuView)
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
	virtual ~CDynaMemuView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	bool m_bcreate;

// Generated message map functions
protected:
	//{{AFX_MSG(CDynaMemuView)
	afx_msg void OnMenucreate();
	afx_msg void OnUpdateMenucreate(CCmdUI* pCmdUI);

	afx_msg void OnMenunew();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DynaMemuView.cpp
inline CDynaMemuDoc* CDynaMemuView::GetDocument()
   { return (CDynaMemuDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYNAMEMUVIEW_H__7653380A_191E_4BDF_AC57_CBAF32E11D0B__INCLUDED_)
