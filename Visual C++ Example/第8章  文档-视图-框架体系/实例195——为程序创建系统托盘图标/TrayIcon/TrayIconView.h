// TrayIconView.h : interface of the CTrayIconView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAYICONVIEW_H__7CFE47A1_0051_4ED1_81E0_D49E63885B04__INCLUDED_)
#define AFX_TRAYICONVIEW_H__7CFE47A1_0051_4ED1_81E0_D49E63885B04__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTrayIconView : public CView
{
protected: // create from serialization only
	CTrayIconView();
	DECLARE_DYNCREATE(CTrayIconView)

// Attributes
public:
	CTrayIconDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTrayIconView)
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
	virtual ~CTrayIconView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTrayIconView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in TrayIconView.cpp
inline CTrayIconDoc* CTrayIconView::GetDocument()
   { return (CTrayIconDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TRAYICONVIEW_H__7CFE47A1_0051_4ED1_81E0_D49E63885B04__INCLUDED_)
