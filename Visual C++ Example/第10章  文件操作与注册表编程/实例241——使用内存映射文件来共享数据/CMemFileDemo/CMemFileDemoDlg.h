// CMemFileDemoDlg.h : header file
//

#if !defined(AFX_CMEMFILEDEMODLG_H__13FAB5E4_B2BE_42ED_9E41_CB7D414B7234__INCLUDED_)
#define AFX_CMEMFILEDEMODLG_H__13FAB5E4_B2BE_42ED_9E41_CB7D414B7234__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCMemFileDemoDlg dialog

class CCMemFileDemoDlg : public CDialog
{
// Construction
public:
	CCMemFileDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCMemFileDemoDlg)
	enum { IDD = IDD_CMEMFILEDEMO_DIALOG };
	CString	m_strWrite;
	CString	m_strRead;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCMemFileDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CMemFile file;//声明内存文件
	// Generated message map functions
	//{{AFX_MSG(CCMemFileDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnRead();
	afx_msg void OnWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMEMFILEDEMODLG_H__13FAB5E4_B2BE_42ED_9E41_CB7D414B7234__INCLUDED_)
