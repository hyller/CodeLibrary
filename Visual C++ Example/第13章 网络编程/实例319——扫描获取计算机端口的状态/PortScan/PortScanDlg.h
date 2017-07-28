// PortScanDlg.h : header file
//

#if !defined(AFX_PORTSCANDLG_H__8BD76815_8905_11D6_8F32_00E04CE76240__INCLUDED_)
#define AFX_PORTSCANDLG_H__8BD76815_8905_11D6_8F32_00E04CE76240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPortScanDlg dialog

//扫描结果
typedef struct
{
	int nAttempts;
	TCHAR IPAddress[16];
	TCHAR port[5];
	BOOL bStatus; //1 = open , 0 = close
}DATA;

class CPortScanDlg : public CDialog
{
// Construction
public:
	CPortScanDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPortScanDlg)
	enum { IDD = IDD_PORTSCAN_DIALOG };
	CListCtrl	m_cResult;
	CIPAddressCtrl	m_cIP;
	CEdit	m_cPortTo;
	CEdit	m_cPortFrom;
	CEdit	m_cSinglePort;
	CEdit	m_cAttempts;
	CButton	m_cBtnStop;
	CButton	m_cBtnScan;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPortScanDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	BOOL TestConnection(CString IP, UINT nPort);
	void ShowHeaders(void);	//Shows the headers of member variable m_cResult (See below)
	void AddHeader(LPTSTR hdr);	//Adds some new headers to m_cResult.
	AddItem(int nItem,int nSubItem,LPCTSTR strItem,int nImageIndex = -1);	//Adds a new item to m_cResult


	BOOL AddColumn(		
	LPCTSTR strItem,int nItem,int nSubItem = -1,
	int nMask = LVCF_FMT | LVCF_WIDTH | LVCF_TEXT | LVCF_SUBITEM,
	int nFmt = LVCFMT_LEFT);//Adds a new column to m_cResult
	

	UINT m_nMaxAttempts;		//试图连接次数的最大值
	BOOL m_bSinglePort;			//是否只扫描单个端口
	UINT m_minPort,m_maxPort;	//扫描端口的范围
	UINT m_nCounter;			//端口的个数
	CStringList* m_pColumns;	//列表框标题栏

	CPtrList* m_pStatusList;//保存扫描结果的链表
//	CBrush* m_pBrush;
	// Generated message map functions
	//{{AFX_MSG(CPortScanDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDestroy();
	afx_msg void OnRadioSingle();
	afx_msg void OnRadioRange();
	afx_msg void OnButtonScan();
	afx_msg void OnButtonStop();
	afx_msg void OnButtonSave();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PORTSCANDLG_H__8BD76815_8905_11D6_8F32_00E04CE76240__INCLUDED_)
