// OperateFileDlg.h : header file
//

#if !defined(AFX_OPERATEFILEDLG_H__130A70FE_421E_4130_8B56_4742EDEE3912__INCLUDED_)
#define AFX_OPERATEFILEDLG_H__130A70FE_421E_4130_8B56_4742EDEE3912__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// COperateFileDlg dialog

class COperateFileDlg : public CDialog
{
// Construction
public:
	COperateFileDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(COperateFileDlg)
	enum { IDD = IDD_OPERATEFILE_DIALOG };
	CString	m_strSrcFile;
	CString	m_strDstFile;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(COperateFileDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(COperateFileDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCopy();
	afx_msg void OnDelete();
	afx_msg void OnOpen1();
	afx_msg void OnMove();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPERATEFILEDLG_H__130A70FE_421E_4130_8B56_4742EDEE3912__INCLUDED_)
