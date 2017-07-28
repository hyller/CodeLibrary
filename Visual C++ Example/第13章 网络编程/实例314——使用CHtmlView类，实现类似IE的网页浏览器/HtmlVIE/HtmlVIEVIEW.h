// HtmlVIEView.h : interface of the CHtmlVIEView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_HtmlVIEVIEW_H__73F9981C_B860_449E_BA4F_FFB9AE32919E__INCLUDED_)
#define AFX_HtmlVIEVIEW_H__73F9981C_B860_449E_BA4F_FFB9AE32919E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CHtmlVIEView : public CHtmlView
{
protected: // create from serialization only
	CHtmlVIEView();
	DECLARE_DYNCREATE(CHtmlVIEView)

// Attributes
public:
	CHtmlVIEDoc* GetDocument();
	CString m_site;												//Õ¯“≥µÿ÷∑–≈œ¢

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHtmlVIEView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CHtmlVIEView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CHtmlVIEView)
	afx_msg void OnGo();
	afx_msg void OnReflesh();
	afx_msg void OnStop();
	afx_msg void OnBack();
	afx_msg void OnEditchangeCombo1();
	afx_msg void OnSelchangeCombo1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in HtmlVIEView.cpp
inline CHtmlVIEDoc* CHtmlVIEView::GetDocument()
   { return (CHtmlVIEDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HtmlVIEVIEW_H__73F9981C_B860_449E_BA4F_FFB9AE32919E__INCLUDED_)
