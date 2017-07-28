// DecodeStringDlg.h : header file
//

#if !defined(AFX_DECODESTRINGDLG_H__4F50850D_7D11_40CC_9C9D_B8E052EE7CEC__INCLUDED_)
#define AFX_DECODESTRINGDLG_H__4F50850D_7D11_40CC_9C9D_B8E052EE7CEC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDecodeStringDlg dialog

class CDecodeStringDlg : public CDialog
{
// Construction
public:
	void StringDecode(CString source, CStringArray& dest, char division);
	CDecodeStringDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDecodeStringDlg)
	enum { IDD = IDD_DECODESTRING_DIALOG };
	CListBox	m_ctlList;
	CString	m_strOrigin;
	CString	m_strDivision;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDecodeStringDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDecodeStringDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDecode();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DECODESTRINGDLG_H__4F50850D_7D11_40CC_9C9D_B8E052EE7CEC__INCLUDED_)
