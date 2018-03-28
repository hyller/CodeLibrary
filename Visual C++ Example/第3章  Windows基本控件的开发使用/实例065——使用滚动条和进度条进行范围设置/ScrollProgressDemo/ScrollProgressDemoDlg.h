// ScrollProgressDemoDlg.h : header file
//

#if !defined(AFX_SCROLLPROGRESSDEMODLG_H__14323562_8AA4_4301_9135_B77C27FC513B__INCLUDED_)
#define AFX_SCROLLPROGRESSDEMODLG_H__14323562_8AA4_4301_9135_B77C27FC513B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CScrollProgressDemoDlg dialog

class CScrollProgressDemoDlg : public CDialog
{
// Construction
public:
	CScrollProgressDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CScrollProgressDemoDlg)
	enum { IDD = IDD_SCROLLPROGRESSDEMO_DIALOG };
	CProgressCtrl	m_ctlProgressV;
	CProgressCtrl	m_ctlProgressH;
	CScrollBar	m_crlScrollV;
	CScrollBar	m_crlScrollH;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CScrollProgressDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CScrollProgressDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SCROLLPROGRESSDEMODLG_H__14323562_8AA4_4301_9135_B77C27FC513B__INCLUDED_)
