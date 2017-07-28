// WavOutPlayDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WavOutPlay.h"
#include "WavOutPlayDlg.h"
#include <Mmsystem.h>   
#pragma   comment(lib,   "Winmm.lib")   

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
// CWavOutPlayDlg dialog

CWavOutPlayDlg::CWavOutPlayDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWavOutPlayDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWavOutPlayDlg)
	m_wavfile = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWavOutPlayDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWavOutPlayDlg)
	DDX_Text(pDX, IDC_EDIT1, m_wavfile);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWavOutPlayDlg, CDialog)
	//{{AFX_MSG_MAP(CWavOutPlayDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_FILE, OnFile)
	ON_BN_CLICKED(IDC_PLAY, OnPlay)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWavOutPlayDlg message handlers

BOOL CWavOutPlayDlg::OnInitDialog()
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
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CWavOutPlayDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWavOutPlayDlg::OnPaint() 
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
HCURSOR CWavOutPlayDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWavOutPlayDlg::OnFile() 
{
	// TODO: Add your control notification handler code here
	CString szFilters="WAV Files (*.wav)|*.wav|All Files (*.*)|*.*||";		//定义文件过滤器
   //创建打开文件对话框对象，默认的文件扩展名为 ".wav".
   CFileDialog fileDlg (TRUE, "WAV", "*.wav",OFN_FILEMUSTEXIST| OFN_HIDEREADONLY, szFilters, this);
   //调用DoModal()函数显示打开文件对话框
   if( fileDlg.DoModal ()==IDOK )
   {
      m_wavfile = fileDlg.GetPathName();//获取文件路径
	  UpdateData(false);//编辑框显示
   }
}

void CWavOutPlayDlg::OnPlay() 
{
// TODO: Add your control notification handler code here
	UpdateData(true);
	if(m_wavfile.IsEmpty())
	{
		AfxMessageBox("请选择要播放的波形文件！");
		 return;
	}
	HMMIO m_hmmio;	//音频文件句柄
	DWORD           WaveLong;       
	DWORD           dwFmtSize; //fmt数据大小          
	DWORD           dwDataOffset;//偏移地址           
	DWORD           dwDataSize; //数组大小  
	MMCKINFO     mmckinfoParent; //父块结构          
	MMCKINFO     mmckinfoSubChunk;//子块结构        
	WAVEFORMATEX     *lpFormat; //波形结构                     
	LONG SoundOffset=0;  //声音数据偏移地址     
	LONG SoundLong=0;    //声音数据的大小
	HPSTR m_lpData;//音频数据
	HWAVEOUT m_hWaveOut;//HWAVEOUT结构
	//打开波形文件
	m_hmmio = mmioOpen((LPSTR)(LPCTSTR)m_wavfile,NULL,MMIO_READ);       
	if(!m_hmmio)           
	{             
		mmioClose(m_hmmio,MMIO_FHOPEN); //关闭文件
		return;           
	}           
	//检查打开文件是否为WAV文件           
	mmckinfoParent.fccType =  mmioFOURCC('W','A','V','E');           
	if(mmioDescend(m_hmmio,(LPMMCKINFO)&mmckinfoParent,NULL,MMIO_FINDRIFF))           
	{           
		//不是WAV文件,关闭文件并退出
		AfxMessageBox("该文件不是Wav文件！");
		mmioClose(m_hmmio,MMIO_FHOPEN);           
		return;           
	}           
	//查找'fmt'块        
	mmckinfoSubChunk.ckid=mmioFOURCC('f','m','t',' ');           
	if(mmioDescend(m_hmmio,&mmckinfoSubChunk,&mmckinfoParent,MMIO_FINDCHUNK))           
	{           
		//找不到fmt块,关闭文件并退出      
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		return;           
	}             
	//获取fmt块的大小，申请内存         
	dwFmtSize= mmckinfoSubChunk.cksize;         
	HLOCAL m_hFormat=LocalAlloc(LMEM_MOVEABLE,LOWORD(dwFmtSize));           
	if(!m_hFormat)      //申请内存失败,关闭文件并退出      
	{             
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		return;           
	}           
	//锁定fmt块内存  
	lpFormat = (WAVEFORMATEX*)LocalLock(m_hFormat);           
	if(!lpFormat)        //锁定内存失败,关闭文件并退出     
	{           
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);       
		return;           
	}           
	//将波形文件的Fmt块数据读入lpFormat 
	if((unsigned long)mmioRead(m_hmmio,(HPSTR)lpFormat,dwFmtSize)!= dwFmtSize)           
	{           
		//读数据失败,关闭文件并退出       
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);       
		return;           
	}            
	//离开'fmt'块           
	mmioAscend(m_hmmio,&mmckinfoSubChunk,0);            
	//查找'data'块         
	mmckinfoSubChunk.ckid   =   mmioFOURCC('d','a','t','a');           
	if(mmioDescend(m_hmmio,&mmckinfoSubChunk,&mmckinfoParent,MMIO_FINDCHUNK))           
	{           
		//不能找到data块, 关闭文件并退出         
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);       
		return;           
	}              
	//获取'data'块的大小及偏移地址           
	dwDataSize =   mmckinfoSubChunk.cksize;           
	dwDataOffset  =   mmckinfoSubChunk.dwDataOffset;           
	if(dwDataSize== 0L)           
	{           
		//如果data块中没有数据,关闭文件并退出      
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);       
		return;           
	}           
	//为音频数据分配内存
	m_lpData = new  char[dwDataSize];         
	if(!m_lpData)//分配失败           
	{               
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);           
		if(m_lpData!= NULL)       
		delete[] m_lpData;       
		return;           
	}             
	//将波形文件定位到声音数据处
	SoundOffset =   dwDataOffset;   
	if(mmioSeek(m_hmmio,SoundOffset,SEEK_SET) < 0 )           
	{           
		//定位失败,关闭文件并退出       
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);           
		delete[]  m_lpData; 
		return;             
	}           
	//读取声音波形数据data  
	SoundLong = dwDataSize;   
	WaveLong=mmioRead(m_hmmio,m_lpData,SoundLong);           
	if(WaveLong <0)           
	{           
		//读取data数据失败,关闭文件并退出       
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);           
		delete[]  m_lpData;    
		return;           
	}       
	//检查音频设备
	if(waveOutGetNumDevs()==0)
	{
		AfxMessageBox("没有可用的音频设备!");
		return;
	} 

	//检查音频输出设备是否能播放指定的音频文件           
	if(waveOutOpen (&m_hWaveOut,0,lpFormat,NULL,NULL,CALLBACK_NULL) !=  MMSYSERR_NOERROR)           
	{               
		//如果不能播放, 关闭文件、释放内存并退出    
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		waveOutReset(m_hWaveOut);           
		waveOutClose(m_hWaveOut);           
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);           
		delete [] m_lpData;       
		return;           
	}           
	//准备待播放的数据  
	 WAVEHDR m_pWaveOutHdr;
	m_pWaveOutHdr.lpData  =   (HPSTR)m_lpData;//数据           
	m_pWaveOutHdr.dwBufferLength =   WaveLong;  //长度         
	m_pWaveOutHdr.dwFlags= 0;    
	m_pWaveOutHdr.dwFlags= WHDR_BEGINLOOP|WHDR_ENDLOOP   ;       
	m_pWaveOutHdr.dwLoops= 1;   //循环次数 
	//准备WAV数据 
	if(waveOutPrepareHeader(m_hWaveOut,&m_pWaveOutHdr,sizeof(WAVEHDR)) == MMSYSERR_INVALHANDLE)           
	{           
		//如果创建WAV数据内存失败, 关闭文件、释放内存并退出      
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		waveOutReset(m_hWaveOut);           
		waveOutClose(m_hWaveOut);           
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat);       
		return;           
	}
	//播放音频数据文件           
	if(waveOutWrite(m_hWaveOut,&m_pWaveOutHdr,sizeof(WAVEHDR))!=0)           
	{           
		//如果播放失败, 关闭文件、释放内存并退出     
		mmioClose(m_hmmio,MMIO_FHOPEN);       
		waveOutReset(m_hWaveOut);           
		waveOutClose(m_hWaveOut);           
		LocalUnlock(m_hFormat);           
		LocalFree(m_hFormat); 
		return;           
	} 

}
