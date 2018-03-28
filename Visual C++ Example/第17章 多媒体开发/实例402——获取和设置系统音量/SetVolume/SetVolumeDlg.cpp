// SetVolumeDlg.cpp : implementation file
//

#include "stdafx.h"
#include "SetVolume.h"
#include "SetVolumeDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetVolumeDlg dialog

CSetVolumeDlg::CSetVolumeDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetVolumeDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetVolumeDlg)
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSetVolumeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetVolumeDlg)
	DDX_Control(pDX, IDC_SLIDER1, m_ctlSlider);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CSetVolumeDlg, CDialog)
	//{{AFX_MSG_MAP(CSetVolumeDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_HSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetVolumeDlg message handlers

BOOL CSetVolumeDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
		
	if (amdInitialize())//初始化混音器设备
	{
		amdGetMasterVolumeControl();//获得音量控制控件的ID和名称
		m_ctlSlider.SetRange(m_dwMinimum, m_dwMaximum);//初始化滚动条
		// 获得当前音量值，并设置滚动条的初始位置
		DWORD dwVal;
		if(amdGetMasterVolumeValue(dwVal))
			m_ctlSlider.SetPos(dwVal);
		UpdateData(FALSE);
	}
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CSetVolumeDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CSetVolumeDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CSetVolumeDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}


BOOL CSetVolumeDlg::amdInitialize()//初始化混音器
{
	m_nNumMixers = ::mixerGetNumDevs();//获取当前混音设备数量 
	m_hMixer = NULL;
	::ZeroMemory(&m_mxcaps, sizeof(MIXERCAPS));
	if (m_nNumMixers != 0)
	{
		//打开混音设备
		if (::mixerOpen(&m_hMixer,0,(DWORD)this->GetSafeHwnd(),NULL,
						MIXER_OBJECTF_MIXER | CALLBACK_WINDOW)!= MMSYSERR_NOERROR)
		return FALSE;
		// 获取混音器性能 
		if (::mixerGetDevCaps((UINT)m_hMixer, &m_mxcaps, sizeof(MIXERCAPS))!= MMSYSERR_NOERROR)
		return FALSE;
	}
	return TRUE;
}
BOOL CSetVolumeDlg::amdUninitialize()//关闭混音器
{
	BOOL bSucc = TRUE;
	if (m_hMixer != NULL)//关闭混音器
	{		
		bSucc = ::mixerClose(m_hMixer) == MMSYSERR_NOERROR;
		m_hMixer = NULL;
	}
	return bSucc;
}


BOOL CSetVolumeDlg::amdGetMasterVolumeControl()//获得主音量控件
{
	m_strDstLineName.Empty();
	m_strVolumeControlName.Empty();
	if (m_hMixer == NULL)
		return FALSE;
	//获得混音器性能
	MIXERLINE mxl;
	mxl.cbStruct = sizeof(MIXERLINE);
	mxl.dwComponentType = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;
	if (::mixerGetLineInfo((HMIXEROBJ)m_hMixer,&mxl,MIXER_OBJECTF_HMIXER|
						MIXER_GETLINEINFOF_COMPONENTTYPE)!= MMSYSERR_NOERROR)
		return FALSE;
	MIXERCONTROL mxc;
	MIXERLINECONTROLS mxlc;
	mxlc.cbStruct = sizeof(MIXERLINECONTROLS);
	mxlc.dwLineID = mxl.dwLineID;
	mxlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
	mxlc.cControls = 1;
	mxlc.cbmxctrl = sizeof(MIXERCONTROL);
	mxlc.pamxctrl = &mxc;
	//获得混音器的音频线线控件
	if (::mixerGetLineControls((HMIXEROBJ)m_hMixer,&mxlc,MIXER_OBJECTF_HMIXER |
							   MIXER_GETLINECONTROLSF_ONEBYTYPE)!= MMSYSERR_NOERROR)
		return FALSE;
	//记录控件的信息
	m_strDstLineName = mxl.szName;
	m_strVolumeControlName = mxc.szName;
	m_dwMinimum = mxc.Bounds.dwMinimum;
	m_dwMaximum = mxc.Bounds.dwMaximum;
	m_dwVolumeControlID = mxc.dwControlID;
	return TRUE;
}

BOOL CSetVolumeDlg::amdGetMasterVolumeValue(DWORD &dwVal) const//获得音量
{
	if (m_hMixer == NULL ||m_strDstLineName.IsEmpty() || m_strVolumeControlName.IsEmpty())
	return FALSE;
	MIXERCONTROLDETAILS_UNSIGNED mxcdVolume;
	MIXERCONTROLDETAILS mxcd;
	mxcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
	mxcd.dwControlID = m_dwVolumeControlID;
	mxcd.cChannels = 1;
	mxcd.cMultipleItems = 0;
	mxcd.cbDetails = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
	mxcd.paDetails = &mxcdVolume;
	//获取指定混音器控件 
	if (::mixerGetControlDetails((HMIXEROBJ)m_hMixer, &mxcd,
								 MIXER_OBJECTF_HMIXER |MIXER_GETCONTROLDETAILSF_VALUE)!= MMSYSERR_NOERROR)
	return FALSE;	
	dwVal = mxcdVolume.dwValue;
	return TRUE;
}
//设置音量
BOOL CSetVolumeDlg::amdSetMasterVolumeValue(DWORD dwVal) const
{
	if (m_hMixer == NULL ||m_strDstLineName.IsEmpty() || m_strVolumeControlName.IsEmpty())
		return FALSE;
	MIXERCONTROLDETAILS_UNSIGNED mxcdVolume = { dwVal };
	MIXERCONTROLDETAILS mxcd;
	mxcd.cbStruct = sizeof(MIXERCONTROLDETAILS);
	mxcd.dwControlID = m_dwVolumeControlID;
	mxcd.cChannels = 1;
	mxcd.cMultipleItems = 0;
	mxcd.cbDetails = sizeof(MIXERCONTROLDETAILS_UNSIGNED);
	mxcd.paDetails = &mxcdVolume;
	//放置混音器控件 
	if (::mixerSetControlDetails((HMIXEROBJ)m_hMixer,&mxcd,
								 MIXER_OBJECTF_HMIXER |MIXER_SETCONTROLDETAILSF_VALUE)!= MMSYSERR_NOERROR)
	return FALSE;
	return TRUE;
}

void CSetVolumeDlg::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
		//根据滑块的位置设置音量
	if (pScrollBar != NULL)
		amdSetMasterVolumeValue(((CSliderCtrl *)pScrollBar)->GetPos());
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}
