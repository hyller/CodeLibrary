// ShowSaveBMPView.h : interface of the CShowSaveBMPView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ShowSaveBMPVIEW_H__28ABA988_BC61_4200_A627_629E0D822099__INCLUDED_)
#define AFX_ShowSaveBMPVIEW_H__28ABA988_BC61_4200_A627_629E0D822099__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CShowSaveBMPView : public CView
{
protected: // create from serialization only
	CShowSaveBMPView();
	DECLARE_DYNCREATE(CShowSaveBMPView)

// Attributes
public:
	CShowSaveBMPDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowSaveBMPView)
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
	virtual ~CShowSaveBMPView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CShowSaveBMPView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ShowSaveBMPView.cpp
inline CShowSaveBMPDoc* CShowSaveBMPView::GetDocument()
   { return (CShowSaveBMPDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ShowSaveBMPVIEW_H__28ABA988_BC61_4200_A627_629E0D822099__INCLUDED_)
