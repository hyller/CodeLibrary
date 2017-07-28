// ADODataBase3Dlg.h : header file
//

#if !defined(AFX_ADODataBase3DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_)
#define AFX_ADODataBase3DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADODataBase3Dlg dialog

class CADODataBase3Dlg : public CDialog
{
// Construction
public:
	CADODataBase3Dlg(CWnd* pParent = NULL);	// standard constructor
	_ConnectionPtr m_pConnection;									//连接对象指针
	_RecordsetPtr m_pRecordset; //记录集对象
	int count;//记录数
	int curNo;//当前操作记录序号
// Dialog Data
	//{{AFX_DATA(CADODataBase3Dlg)
	enum { IDD = IDD_ADODataBase3_DIALOG };
	CString	m_strNumber;
	CString	m_strName;
	CString	m_strSex;
	CString	m_strAddress;
	int		m_radio;
	CString	m_Status;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADODataBase3Dlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	void ShowRecord();//显示记录
	// Generated message map functions
	//{{AFX_MSG(CADODataBase3Dlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAdd();
	afx_msg void OnRadio1();
	afx_msg void OnRadio2();
	afx_msg void OnRadio3();
	afx_msg void OnFirst();
	afx_msg void OnLast();
	afx_msg void OnNext();
	afx_msg void OnPrev();
	afx_msg void OnCheckin();
	afx_msg void OnRemove();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADODataBase3DLG_H__C350EC08_C082_4B6B_8561_C295B04DB14B__INCLUDED_)
