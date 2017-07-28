// DySplitterWndView.h : interface of the CDySplitterWndView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DYSPLITTERWNDVIEW_H__4F1D5CB7_24A1_4712_B069_0A2C3BAB8A00__INCLUDED_)
#define AFX_DYSPLITTERWNDVIEW_H__4F1D5CB7_24A1_4712_B069_0A2C3BAB8A00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDySplitterWndView : public CScrollView
{
protected: // create from serialization only
	CDySplitterWndView();
	DECLARE_DYNCREATE(CDySplitterWndView)

// Attributes
public:
	CDySplitterWndDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDySplitterWndView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void OnInitialUpdate();
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDySplitterWndView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDySplitterWndView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DySplitterWndView.cpp
inline CDySplitterWndDoc* CDySplitterWndView::GetDocument()
   { return (CDySplitterWndDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DYSPLITTERWNDVIEW_H__4F1D5CB7_24A1_4712_B069_0A2C3BAB8A00__INCLUDED_)
