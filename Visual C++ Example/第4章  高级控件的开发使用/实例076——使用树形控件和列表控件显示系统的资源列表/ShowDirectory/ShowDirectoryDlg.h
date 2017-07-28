// ShowDirectoryDlg.h : header file
//

#if !defined(AFX_SHOWDIRECTORYDLG_H__C2B6EEC9_318F_4BA1_B8A6_9F0D76DC054C__INCLUDED_)
#define AFX_SHOWDIRECTORYDLG_H__C2B6EEC9_318F_4BA1_B8A6_9F0D76DC054C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CShowDirectoryDlg dialog

class CShowDirectoryDlg : public CDialog
{
// Construction
public:
	CShowDirectoryDlg(CWnd* pParent = NULL);	// standard constructor
	
	void AddSubItem(HTREEITEM hParent);//向树形控件中添加子目录
	CString GetFullPath(HTREEITEM hCurrent);
	void GetDriveDir(HTREEITEM hParent);
	void GetLogicalDrives(HTREEITEM hParen);
	CTreeViewDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CShowDirectoryDlg)
	enum { IDD = IDD_SHOWDIRECTORY_DIALOG };
	CTreeCtrl	m_ctlTree;
	CListCtrl	m_ctlList;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowDirectoryDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

    HTREEITEM m_hRoot;//根节点
	CImageList m_ImageList;//图像列表
	// Generated message map functions
	//{{AFX_MSG(CShowDirectoryDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnItemexpandedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangedTree1(NMHDR* pNMHDR, LRESULT* pResult);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWDIRECTORYDLG_H__C2B6EEC9_318F_4BA1_B8A6_9F0D76DC054C__INCLUDED_)
