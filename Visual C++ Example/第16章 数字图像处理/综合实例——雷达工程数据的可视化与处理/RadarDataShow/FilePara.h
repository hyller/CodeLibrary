#pragma once
#include "afxwin.h"


// CFilePara 对话框

class CFilePara : public CDialog
{
	DECLARE_DYNAMIC(CFilePara)

public:
	CFilePara(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CFilePara();

// 对话框数据
	enum { IDD = IDD_FILEPARA };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_Outshow;
	int m_Radio1;
	int m_Radio3;
	CButton mb_Radio1;
	//CButton mb_Radio2;
	CButton mb_Radio3;
	CEdit mb_Slice;
	int m_Slice;
	CEdit mb_Polebegin;
	int m_Polebegin;
	CEdit mb_Poleend;
	int m_Poleend;

	int m_Timewindow;//时窗
	int m_Samplenum;//采样点
	int m_Sampleslice;//采样剖面数
	int m_Samplepole;//每个剖面的测点数


	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedRadio5();
	afx_msg void OnBnClickedRadio6();
protected:
	virtual void OnOK();
};
