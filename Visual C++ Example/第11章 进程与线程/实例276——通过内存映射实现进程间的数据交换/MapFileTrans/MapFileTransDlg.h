// MapFileTransDlg.h : header file
//

#if !defined(AFX_MAPFILETRANSDLG_H__DEE851EB_86BA_401D_8740_8BB3C6C3A637__INCLUDED_)
#define AFX_MAPFILETRANSDLG_H__DEE851EB_86BA_401D_8740_8BB3C6C3A637__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMapFileTransDlg dialog

class CMapFileTransDlg : public CDialog
{
// Construction
public:
	CMapFileTransDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMapFileTransDlg)
	enum { IDD = IDD_MAPFILETRANS_DIALOG };
	CString	m_strSource;
	CString	m_strDest;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMapFileTransDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMapFileTransDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSave();
	afx_msg void OnRead();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPFILETRANSDLG_H__DEE851EB_86BA_401D_8740_8BB3C6C3A637__INCLUDED_)
