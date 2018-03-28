// MultiDocDemoView.h : interface of the CMultiDocDemoView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MultiDocDemoVIEW_H__37344185_9412_496B_9BD7_9BFBA7688270__INCLUDED_)
#define AFX_MultiDocDemoVIEW_H__37344185_9412_496B_9BD7_9BFBA7688270__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMultiDocDemoView : public CView
{
protected: // create from serialization only
	CMultiDocDemoView();
	DECLARE_DYNCREATE(CMultiDocDemoView)

// Attributes
public:
	CMultiDocDemoDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMultiDocDemoView)
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
	virtual ~CMultiDocDemoView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMultiDocDemoView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MultiDocDemoView.cpp
inline CMultiDocDemoDoc* CMultiDocDemoView::GetDocument()
   { return (CMultiDocDemoDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MultiDocDemoVIEW_H__37344185_9412_496B_9BD7_9BFBA7688270__INCLUDED_)
