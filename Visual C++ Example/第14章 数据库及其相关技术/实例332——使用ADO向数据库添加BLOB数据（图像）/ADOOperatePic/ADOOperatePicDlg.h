// ADOOperatePicDlg.h : header file
//

#if !defined(AFX_ADOOPERATEPICDLG_H__382E862D_8CBD_4670_A74B_7A5F4CD337A5__INCLUDED_)
#define AFX_ADOOPERATEPICDLG_H__382E862D_8CBD_4670_A74B_7A5F4CD337A5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CADOOperatePicDlg dialog

class CADOOperatePicDlg : public CDialog
{
// Construction
public:
	CADOOperatePicDlg(CWnd* pParent = NULL);	// standard constructor
	HBITMAP BufferToHBITMAP();
// Dialog Data
	//{{AFX_DATA(CADOOperatePicDlg)
	enum { IDD = IDD_ADOOPERATEPIC_DIALOG };
	CStatic	m_ctlPic;
	CString	m_strNo;
	CString	m_strName;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CADOOperatePicDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HBITMAP			m_hPhotoBitmap;
	char			*m_pBMPBuffer;
	DWORD			m_nFileLen;
	_RecordsetPtr	m_pRecordset;
	// Generated message map functions
	//{{AFX_MSG(CADOOperatePicDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnLoadbmp();
	afx_msg void OnSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADOOPERATEPICDLG_H__382E862D_8CBD_4670_A74B_7A5F4CD337A5__INCLUDED_)
