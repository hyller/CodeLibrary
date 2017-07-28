// MCIDigitalVideoPlayDlg.h : header file
//

#if !defined(AFX_MCIDigitalVideoPlayDLG_H__C56803F9_2A1C_46CC_AEDF_3610794AA43F__INCLUDED_)
#define AFX_MCIDigitalVideoPlayDLG_H__C56803F9_2A1C_46CC_AEDF_3610794AA43F__INCLUDED_

#include "MyMCIVideo.h"
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMCIDigitalVideoPlayDlg dialog

class CMCIDigitalVideoPlayDlg : public CDialog
{
// Construction
public:
	CMCIDigitalVideoPlayDlg(CWnd* pParent = NULL);	// standard constructor
	CMyMCIVideo m_avi;//CMCIAviPlay类对象
	BOOL m_bOpen;//打开标记
	BOOL m_bLoop;//循环标记
	BOOL m_bFullScreen;//全屏标记

// Dialog Data
	//{{AFX_DATA(CMCIDigitalVideoPlayDlg)
	enum { IDD = IDD_MCIDigitalVideoPlay_DIALOG };
	CButton	m_ctlCheckLoop;
	CButton	m_ctlCheckFull;
	CString	m_strfile;
	CString	m_strspeed;
	CString	m_strframenum;
	CString	m_framesize;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMCIDigitalVideoPlayDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMCIDigitalVideoPlayDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBackavi();
	afx_msg void OnForwardavi();
	afx_msg void OnOpenavi();
	afx_msg void OnPauseavi();
	afx_msg void OnPlayavi();
	afx_msg void OnStopavi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MCIDigitalVideoPlayDLG_H__C56803F9_2A1C_46CC_AEDF_3610794AA43F__INCLUDED_)
