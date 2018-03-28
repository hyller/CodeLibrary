// ImageZoomDemoDlg.h : header file
//

#if !defined(AFX_IMAGEZOOMDEMODLG_H__EF34D651_D506_4E39_A27B_EB16D883A4F5__INCLUDED_)
#define AFX_IMAGEZOOMDEMODLG_H__EF34D651_D506_4E39_A27B_EB16D883A4F5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "ImageStatic.h"
/////////////////////////////////////////////////////////////////////////////
// CImageZoomDemoDlg dialog

class CImageZoomDemoDlg : public CDialog
{
// Construction
public:
	CImageZoomDemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CImageZoomDemoDlg)
	enum { IDD = IDD_IMAGEZOOMDEMO_DIALOG };
	CImageStatic	m_ctlStatic;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CImageZoomDemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CImageZoomDemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCenter();
	afx_msg void OnFull();
	afx_msg void OnHeight();
	afx_msg void OnOrigin();
	afx_msg void OnWidth();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IMAGEZOOMDEMODLG_H__EF34D651_D506_4E39_A27B_EB16D883A4F5__INCLUDED_)
