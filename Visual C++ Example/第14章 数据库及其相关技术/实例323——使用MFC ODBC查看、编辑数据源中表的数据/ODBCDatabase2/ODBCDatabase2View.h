// ODBCDatabase2View.h : interface of the CODBCDatabase2View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCDatabase2VIEW_H__B625B639_0CD9_493B_B485_CF7A448DB961__INCLUDED_)
#define AFX_ODBCDatabase2VIEW_H__B625B639_0CD9_493B_B485_CF7A448DB961__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CODBCDatabase2Set;

class CODBCDatabase2View : public CRecordView
{
protected: // create from serialization only
	CODBCDatabase2View();
	DECLARE_DYNCREATE(CODBCDatabase2View)

public:
	//{{AFX_DATA(CODBCDatabase2View)
	enum { IDD = IDD_ODBCDatabase2_FORM };
	CODBCDatabase2Set* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CODBCDatabase2Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDatabase2View)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CODBCDatabase2View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBCDatabase2View)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ODBCDatabase2View.cpp
inline CODBCDatabase2Doc* CODBCDatabase2View::GetDocument()
   { return (CODBCDatabase2Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDatabase2VIEW_H__B625B639_0CD9_493B_B485_CF7A448DB961__INCLUDED_)
