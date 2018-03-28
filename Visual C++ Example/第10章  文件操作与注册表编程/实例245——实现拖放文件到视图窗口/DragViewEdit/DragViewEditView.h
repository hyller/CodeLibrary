// DragViewEditView.h : interface of the CDragViewEditView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DRAGVIEWEDITVIEW_H__AA1DCA2F_CD80_48FF_BEDB_956DF7B2CE59__INCLUDED_)
#define AFX_DRAGVIEWEDITVIEW_H__AA1DCA2F_CD80_48FF_BEDB_956DF7B2CE59__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDragViewEditView : public CFormView
{
protected: // create from serialization only
	CDragViewEditView();
	DECLARE_DYNCREATE(CDragViewEditView)

public:
	//{{AFX_DATA(CDragViewEditView)
	enum{ IDD = IDD_DRAGVIEWEDIT_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CDragViewEditDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDragViewEditView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDragViewEditView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDragViewEditView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in DragViewEditView.cpp
inline CDragViewEditDoc* CDragViewEditView::GetDocument()
   { return (CDragViewEditDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DRAGVIEWEDITVIEW_H__AA1DCA2F_CD80_48FF_BEDB_956DF7B2CE59__INCLUDED_)
