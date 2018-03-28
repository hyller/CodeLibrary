// ADODataControlView.h : interface of the CADODataControlView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADODATACONTROLVIEW_H__F1ADD5AE_F579_4998_BCA7_4737D25E831F__INCLUDED_)
#define AFX_ADODATACONTROLVIEW_H__F1ADD5AE_F579_4998_BCA7_4737D25E831F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CADODataControlView : public CFormView
{
protected: // create from serialization only
	CADODataControlView();
	DECLARE_DYNCREATE(CADODataControlView)

public:
	//{{AFX_DATA(CADODataControlView)
	enum{ IDD = IDD_ADODATACONTROL_FORM };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

// Attributes
public:
	CADODataControlDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataControlView)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnPrint(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CADODataControlView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CADODataControlView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ADODataControlView.cpp
inline CADODataControlDoc* CADODataControlView::GetDocument()
   { return (CADODataControlDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATACONTROLVIEW_H__F1ADD5AE_F579_4998_BCA7_4737D25E831F__INCLUDED_)
