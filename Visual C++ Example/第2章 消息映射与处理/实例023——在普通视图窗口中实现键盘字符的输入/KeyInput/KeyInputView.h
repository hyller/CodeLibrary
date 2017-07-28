// KeyInputView.h : interface of the CKeyInputView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_KEYINPUTVIEW_H__244D529D_70A5_49E2_8804_32FD4E457238__INCLUDED_)
#define AFX_KEYINPUTVIEW_H__244D529D_70A5_49E2_8804_32FD4E457238__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CKeyInputView : public CView
{
protected: // create from serialization only
	CKeyInputView();
	DECLARE_DYNCREATE(CKeyInputView)

// Attributes
public:
	CKeyInputDoc* GetDocument();

// Operations
public:

	CPoint ptCharacter;								//¼ÇÂ¼×Ö·ûÎ»ÖÃ

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CKeyInputView)
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
	virtual ~CKeyInputView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CKeyInputView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in KeyInputView.cpp
inline CKeyInputDoc* CKeyInputView::GetDocument()
   { return (CKeyInputDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_KEYINPUTVIEW_H__244D529D_70A5_49E2_8804_32FD4E457238__INCLUDED_)
