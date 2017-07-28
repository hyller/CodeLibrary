// RestoreWinPosView.h : interface of the CRestoreWinPosView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_RESTOREWINPOSVIEW_H__63604B0E_DD09_46F9_8BA4_8D5C8999ED13__INCLUDED_)
#define AFX_RESTOREWINPOSVIEW_H__63604B0E_DD09_46F9_8BA4_8D5C8999ED13__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CRestoreWinPosView : public CView
{
protected: // create from serialization only
	CRestoreWinPosView();
	DECLARE_DYNCREATE(CRestoreWinPosView)

// Attributes
public:
	CRestoreWinPosDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRestoreWinPosView)
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
	virtual ~CRestoreWinPosView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CRestoreWinPosView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in RestoreWinPosView.cpp
inline CRestoreWinPosDoc* CRestoreWinPosView::GetDocument()
   { return (CRestoreWinPosDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RESTOREWINPOSVIEW_H__63604B0E_DD09_46F9_8BA4_8D5C8999ED13__INCLUDED_)
