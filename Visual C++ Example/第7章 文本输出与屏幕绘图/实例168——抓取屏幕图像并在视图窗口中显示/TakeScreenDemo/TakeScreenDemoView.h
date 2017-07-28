// TakeScreenDemoView.h : interface of the CTakeScreenDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TAKESCREENDEMOVIEW_H__93DA733E_5FF2_46E1_9646_03E0C78765F2__INCLUDED_)
#define AFX_TAKESCREENDEMOVIEW_H__93DA733E_5FF2_46E1_9646_03E0C78765F2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTakeScreenDemoView : public CView
{
protected: // create from serialization only
	CTakeScreenDemoView();
	DECLARE_DYNCREATE(CTakeScreenDemoView)
	HBITMAP TakeScreen();
// Attributes
public:
	CTakeScreenDemoDoc* GetDocument();
	
// Operations
public:
	bool bTakeScreen;
	HBITMAP m_hbmp;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTakeScreenDemoView)
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
	virtual ~CTakeScreenDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTakeScreenDemoView)
	afx_msg void OnMenuscreen();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TakeScreenDemoView.cpp
inline CTakeScreenDemoDoc* CTakeScreenDemoView::GetDocument()
   { return (CTakeScreenDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TAKESCREENDEMOVIEW_H__93DA733E_5FF2_46E1_9646_03E0C78765F2__INCLUDED_)
