// SetVolumeDlg.h : header file
//

#if !defined(AFX_SETVOLUMEDLG_H__6A353BC0_3616_499D_8A70_72CDB48FB0B8__INCLUDED_)
#define AFX_SETVOLUMEDLG_H__6A353BC0_3616_499D_8A70_72CDB48FB0B8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <mmsystem.h>
#pragma   comment(lib,   "Winmm.lib")   
/////////////////////////////////////////////////////////////////////////////
// CSetVolumeDlg dialog

class CSetVolumeDlg : public CDialog
{
// Construction
public:
	CSetVolumeDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSetVolumeDlg)
	enum { IDD = IDD_SETVOLUME_DIALOG };
	CSliderCtrl	m_ctlSlider;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetVolumeDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	UINT m_nNumMixers;									//混音器的数量
	HMIXER m_hMixer;									//当前混音器的句柄
	MIXERCAPS m_mxcaps;									//当前混音器的性能参数

	CString m_strDstLineName, m_strVolumeControlName;	//混音器控件的名称
	DWORD m_dwMinimum, m_dwMaximum;						//最大，最小的音量值
	DWORD m_dwVolumeControlID;							//混音器控件的ID

	BOOL amdUninitialize();	//关闭混音器							
	BOOL amdInitialize();//初始化混音器
	BOOL amdGetMasterVolumeControl();//获得主音量控件
	BOOL amdGetMasterVolumeValue(DWORD &dwVal) const;//获取音量
	BOOL amdSetMasterVolumeValue(DWORD dwVal) const;//设置音量

	// Generated message map functions
	//{{AFX_MSG(CSetVolumeDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SETVOLUMEDLG_H__6A353BC0_3616_499D_8A70_72CDB48FB0B8__INCLUDED_)
