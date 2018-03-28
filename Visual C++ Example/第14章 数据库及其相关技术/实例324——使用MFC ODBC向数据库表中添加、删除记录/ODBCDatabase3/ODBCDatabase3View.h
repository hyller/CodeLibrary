// ODBCDatabase3View.h : interface of the CODBCDatabase3View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_ODBCDatabase3VIEW_H__B625B639_0CD9_493B_B485_CF7A448DB961__INCLUDED_)
#define AFX_ODBCDatabase3VIEW_H__B625B639_0CD9_493B_B485_CF7A448DB961__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CODBCDatabase3Set;

class CODBCDatabase3View : public CRecordView
{
protected: // create from serialization only
	CODBCDatabase3View();
	DECLARE_DYNCREATE(CODBCDatabase3View)

public:
	//{{AFX_DATA(CODBCDatabase3View)
	enum { IDD = IDD_ODBCDatabase3_FORM };
	CODBCDatabase3Set* m_pSet;
	//}}AFX_DATA

// Attributes
public:
	CODBCDatabase3Doc* GetDocument();

// Operations
public:
	  BOOL m_bAddMode;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CODBCDatabase3View)
	public:
	virtual CRecordset* OnGetRecordset();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL OnMove(UINT nIDMoveCommand);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CODBCDatabase3View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CODBCDatabase3View)
	afx_msg void OnAddrecord();
	afx_msg void OnDeleterecord();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ODBCDatabase3View.cpp
inline CODBCDatabase3Doc* CODBCDatabase3View::GetDocument()
   { return (CODBCDatabase3Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ODBCDatabase3VIEW_H__B625B639_0CD9_493B_B485_CF7A448DB961__INCLUDED_)
