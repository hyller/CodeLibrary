// BaseDlgDemoView.h : interface of the CBaseDlgDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BaseDlgDemoVIEW_H__0EC14D44_779E_4615_B348_788694DC0925__INCLUDED_)
#define AFX_BaseDlgDemoVIEW_H__0EC14D44_779E_4615_B348_788694DC0925__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseDlgDemoView : public CView
{
protected: // create from serialization only
	CBaseDlgDemoView();
	DECLARE_DYNCREATE(CBaseDlgDemoView)

// Attributes
public:
	CBaseDlgDemoDoc* GetDocument();

// Operations
public:
		CString szOut;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDlgDemoView)
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
	virtual ~CBaseDlgDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDlgDemoView)
	afx_msg void OnCreatedlg();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BaseDlgDemoView.cpp
inline CBaseDlgDemoDoc* CBaseDlgDemoView::GetDocument()
   { return (CBaseDlgDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDlgDemoVIEW_H__0EC14D44_779E_4615_B348_788694DC0925__INCLUDED_)
