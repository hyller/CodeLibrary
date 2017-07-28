// ADODateGridView.h : interface of the CADODateGridView class
//
/////////////////////////////////////////////////////////////////////////////
//{{AFX_INCLUDES()
#include "datagrid.h"
//}}AFX_INCLUDES

#if !defined(AFX_ADODATEGRIDVIEW_H__8C996179_73C2_4A01_BE0A_3A84DD89FBE2__INCLUDED_)
#define AFX_ADODATEGRIDVIEW_H__8C996179_73C2_4A01_BE0A_3A84DD89FBE2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CADODateGridView : public CFormView
{
protected: // create from serialization only
	CADODateGridView();
	DECLARE_DYNCREATE(CADODateGridView)

public:
	//{{AFX_DATA(CADODateGridView)
	enum { IDD = IDD_ADODATEGRID_FORM };
	CListBox	m_ctlList;
	CString	m_strConnection;
	CString	m_strSQL;
	CDataGrid	m_ctlDataGrid;

	//}}AFX_DATA
	_ConnectionPtr m_Connection;
	_RecordsetPtr m_Recordset;
	CString m_strTable;//±Ì√˚
	BOOL isDesc;//Ωµ–Ú≈≈¡–
// Attributes
public:
	CADODateGridDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODateGridView)
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
	virtual ~CADODateGridView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CADODateGridView)
	afx_msg void OnSource();
	afx_msg void OnConnect();
	afx_msg void OnExecute();
	afx_msg void OnDisconnect();
	afx_msg void OnQuit();
	afx_msg void OnSelchangeList1();
	afx_msg void OnHeadClickDatagrid1(short ColIndex);
	DECLARE_EVENTSINK_MAP()
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in ADODateGridView.cpp
inline CADODateGridDoc* CADODateGridView::GetDocument()
   { return (CADODateGridDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODATEGRIDVIEW_H__8C996179_73C2_4A01_BE0A_3A84DD89FBE2__INCLUDED_)
