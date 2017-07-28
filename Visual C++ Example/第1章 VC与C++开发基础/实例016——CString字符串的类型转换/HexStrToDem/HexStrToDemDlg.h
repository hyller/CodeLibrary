// HexStrToDemDlg.h : header file
//

#if !defined(AFX_HEXSTRTODEMDLG_H__67ED97C5_DAEE_4789_A885_16505D50073B__INCLUDED_)
#define AFX_HEXSTRTODEMDLG_H__67ED97C5_DAEE_4789_A885_16505D50073B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHexStrToDemDlg dialog

class CHexStrToDemDlg : public CDialog
{
// Construction
public:
	int HexToDem(CString str);
	CHexStrToDemDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHexStrToDemDlg)
	enum { IDD = IDD_HEXSTRTODEM_DIALOG };
	CString	m_strHex;
	int		m_intDem;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHexStrToDemDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHexStrToDemDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnChange();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HEXSTRTODEMDLG_H__67ED97C5_DAEE_4789_A885_16505D50073B__INCLUDED_)
