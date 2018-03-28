// BaseDlgDemo2View.h : interface of the CBaseDlgDemo2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_BaseDlgDemo2VIEW_H__0EC14D44_779E_4615_B348_788694DC0925__INCLUDED_)
#define AFX_BaseDlgDemo2VIEW_H__0EC14D44_779E_4615_B348_788694DC0925__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CBaseDlgDemo2View : public CView
{
protected: // create from serialization only
	CBaseDlgDemo2View();
	DECLARE_DYNCREATE(CBaseDlgDemo2View)

// Attributes
public:
	CBaseDlgDemo2Doc* GetDocument();

// Operations
public:
		CString szOut;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBaseDlgDemo2View)
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
	virtual ~CBaseDlgDemo2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CBaseDlgDemo2View)
	afx_msg void OnCreatedlg();
	afx_msg void OnCreatedlg2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in BaseDlgDemo2View.cpp
inline CBaseDlgDemo2Doc* CBaseDlgDemo2View::GetDocument()
   { return (CBaseDlgDemo2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BaseDlgDemo2VIEW_H__0EC14D44_779E_4615_B348_788694DC0925__INCLUDED_)
