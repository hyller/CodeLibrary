
#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "VideoVoiceTransDlg.h"
#include "Resource.h"
#include "reatReport.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern CVideoVoiceTransApp theApp ;
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
// CVideoVoiceTransDlg dialog




// Global varialbes...
int count=0;
unsigned char cdata[10000];
int cbuffer_size=10000;
unsigned char rgbdata[80000];
int buffersize=80000;




// Callback function gets invoked during compression...
// It returns the compressed data byte by byte...
void OwnWriteFunction(int byte)
{
	if(count<cbuffer_size)
	cdata[count]=(unsigned char)byte;	
	count++;

}



CVideoVoiceTransDlg::CVideoVoiceTransDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVideoVoiceTransDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVideoVoiceTransDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CVideoVoiceTransDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideoVoiceTransDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}





BEGIN_MESSAGE_MAP(CVideoVoiceTransDlg, CDialog)
	//{{AFX_MSG_MAP(CVideoVoiceTransDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	// Conference menu handlers
	ON_COMMAND(CONF_CONNECT,OnConnectRemote)
	ON_COMMAND(CONF_QUESTCONNECT,OnQuestRemote)
	ON_COMMAND(CONF_DISCONNECT,OnDisconnect)
	ON_COMMAND(CONF_EXIT,OnCancel)
	
	// View menu handlers
	ON_COMMAND(VIEW_LOCAL,OnViewLocal)
	ON_COMMAND(VIEW_REMOTE,OnViewRemote)
	
	// Audio menu handlers
	ON_COMMAND(AUDIO_CONTROL,OnVolumeControl)
	ON_COMMAND(AUDIO_SEND,OnAudioSend)
	ON_COMMAND(AUDIO_RECEIVE,OnAudioReceive)
	

	// Video menu handlers
	ON_COMMAND(VIDEO_SEND,OnVideoSend)
	ON_COMMAND(VIDEO_RECEIVE,OnVideoReceive)
	

	// Help menu handlers
	ON_COMMAND(HELP_ABOUT,OnAbout)
	//skin
	ON_COMMAND(ID_MENU_SKIN_LOAD, OnMenuSkinLoad)
	ON_COMMAND(ID_MENU_SKIN_NO, OnMenuSkinNo)

	//button
	ON_COMMAND(IDC_BUTTON1,OnSendMesg)
	ON_COMMAND(IDC_SNAP,OnSnap)
	ON_COMMAND(IDC_PICSAVE,OnPicSave)
	ON_COMMAND(IDC_STOPSNAP,OnStopSnap)
	ON_COMMAND(IDC_FILEFIND,OnQuerrySource)
	ON_COMMAND(IDC_BOOK,OnAdvice)
	ON_COMMAND(IDC_FILESEND,OnSendFile)
	ON_COMMAND(IDC_RESULT,OnResult)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()










BOOL CVideoVoiceTransDlg::OnInitDialog()
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

	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// initialize toolbar and status bar
	if (!m_wndToolBar.Create(this) ||
		!m_wndToolBar.LoadToolBar(IDR_TOOLBAR1))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}
	m_wndToolBar.SetBarStyle(m_wndToolBar.GetBarStyle()|CBRS_TOOLTIPS|CBRS_FLYBY|CBRS_SIZE_DYNAMIC);
	// move toolbar and status bar over static controls
	CRect rect2;
	GetDlgItem(IDC_TOOLBAR_STATIC)->GetWindowRect(&rect2);
	ScreenToClient(&rect2);
	m_wndToolBar.MoveWindow(&rect2);

	// 创建日志文件
	log.Open("main.log",CFile::modeCreate | CFile::modeWrite);
	// 初始化时，相关的菜单命令无效
	menu=this->GetMenu();
	menu->EnableMenuItem(CONF_CONNECT,MF_ENABLED);
	menu->EnableMenuItem(CONF_QUESTCONNECT,MF_ENABLED);
	menu->EnableMenuItem(CONF_DISCONNECT,MF_DISABLED | MF_GRAYED);
	menu->EnableMenuItem(AUDIO_SEND,MF_GRAYED);
	menu->EnableMenuItem(AUDIO_RECEIVE,MF_GRAYED);
	menu->EnableMenuItem(VIDEO_SEND,MF_GRAYED);
	menu->EnableMenuItem(VIDEO_RECEIVE,MF_GRAYED);
	menu->EnableMenuItem(VIEW_LOCAL,MF_GRAYED);
	menu->EnableMenuItem(VIEW_REMOTE,MF_GRAYED);
	
	list=(CListBox*)GetDlgItem(IDC_LIST1);//消息列表框
	bsend=(CButton*)GetDlgItem(IDC_BUTTON1);//“发送”按钮
	bsend->EnableWindow(FALSE);//“发送”按钮初始无效
	GetDlgItem(IDC_SNAP)->EnableWindow(false);//“视频捕捉”按钮初始无效
	GetDlgItem(IDC_PICSAVE)->EnableWindow(false);//“保存图像”按钮初始无效
	GetDlgItem(IDC_STOPSNAP)->EnableWindow(false);//“停止捕捉”按钮初始无效	
	// 创建录音线程
	record=new RecordSound(this);
	record->CreateThread();
	// 创建放音线程
	play=new PlaySound1(this);
	play->CreateThread();
	//初始化视频捕捉窗口
	vidcap=new VideoCapture();
	vidcap->SetDialog(this);
	if(vidcap->Initialize()) //初始化成功
	{	
		this->m_bmpinfo=&vidcap->m_bmpinfo;	
		isVideo=TRUE;
		// 压缩器初始化
		    // 从RGB 转化为 YUV
			InitLookupTable();
			//初始化压缩器
			cparams.format = CPARAM_QCIF;
			InitH263Encoder(&cparams);  
			WriteByteFunction = OwnWriteFunction;
	}
	else
	{
		isVideo=FALSE;		
		// 创建bmpinfo 结构
		m_bmpinfo=new BITMAPINFO;
		m_bmpinfo->bmiHeader.biSize=sizeof(BITMAPINFOHEADER);
		m_bmpinfo->bmiHeader.biWidth=IMAGE_WIDTH;
		m_bmpinfo->bmiHeader.biHeight=IMAGE_HEIGHT;
		m_bmpinfo->bmiHeader.biPlanes=1;
		m_bmpinfo->bmiHeader.biBitCount=24;
		m_bmpinfo->bmiHeader.biCompression=0;
		m_bmpinfo->bmiHeader.biSizeImage=0;
		m_bmpinfo->bmiHeader.biXPelsPerMeter=0;
		m_bmpinfo->bmiHeader.biYPelsPerMeter=0;
		m_bmpinfo->bmiHeader.biClrUsed=0;
		m_bmpinfo->bmiHeader.biClrImportant=0;
		//相关的菜单命令项无效
		menu->EnableMenuItem(VIEW_LOCAL,MF_DISABLED | MF_GRAYED);
		menu->EnableMenuItem(VIDEO_SEND,MF_DISABLED | MF_GRAYED);
	}
	
	
	// 初始状态还没有进行视频捕捉，相关的标识赋值
	isCaptureStarted=FALSE;
	isViewLocalVideo=TRUE;
	isViewRemoteVideo=TRUE;
	isAudioSend=TRUE;
	isAudioReceive=TRUE;
	isVideoSend=TRUE;
	isVideoReceive=TRUE;
	isSnap=FALSE;
	isPicdata=FALSE;
	isButtonShow=TRUE;
	//初始化H263解压缩器
	InitH263Decoder();
	// Adjust display windows
	CWnd *wnd,*bwnd;
	CRect rect,brect;
	// 设置本地视频播放窗口信息
	wnd=this->GetDlgItem(IDC_LOCALVIDEO);//
   	bwnd=this->GetDlgItem(IDC_LOCALBORDER);//local frame
   	bwnd->GetWindowRect(brect);
	ScreenToClient(brect);
	local_wnd_x=brect.TopLeft().x+(brect.Width()-IMAGE_WIDTH*1.5)/2;
	local_wnd_y=brect.TopLeft().y+(brect.Height()-IMAGE_HEIGHT*1.5)/2;	
	// Centre the local video window
	wnd->SetWindowPos(&wndTop,local_wnd_x-4,local_wnd_y-4,IMAGE_WIDTH*1.5+9,IMAGE_HEIGHT*1.5+9,SWP_SHOWWINDOW | SWP_DRAWFRAME);

	// 设置接收的对端视频播放窗口信息
	wnd=this->GetDlgItem(IDC_REMOTEVIDEO);	// Video display window
   	bwnd=this->GetDlgItem(IDC_REMOTEBORDER); // Border window...
   	bwnd->GetWindowRect(brect);
	ScreenToClient(brect);
	remote_wnd_x=brect.TopLeft().x+(brect.Width()-IMAGE_WIDTH*1.5)/2;
	remote_wnd_y=brect.TopLeft().y+(brect.Height()-IMAGE_HEIGHT*1.5)/2;
	// Centre the remote video window
	wnd->SetWindowPos(&wndTop,remote_wnd_x-4,remote_wnd_y-4,IMAGE_WIDTH*1.5+9,IMAGE_HEIGHT*1.5+9,SWP_SHOWWINDOW | SWP_DRAWFRAME);
	// 获取对话框DC
	m_hdc=this->GetDC()->m_hDC;
	//初始化DIB
	hdib=::DrawDibOpen();
	if(hdib!=NULL)
	{
		::DrawDibBegin(hdib,
					   m_hdc,
					   IMAGE_WIDTH*1.5,				// 拉伸1.5倍
					   IMAGE_HEIGHT*1.5,				// 拉伸1.5倍
					   &m_bmpinfo->bmiHeader,
					   IMAGE_WIDTH,         // 图像宽度
					   IMAGE_HEIGHT,        // 图像高度
					   0				
					   );
	}
    

	//声明连接对话框对象
	connectdlg=new ConnectDlg(NULL);
	connectdlg->SetParent(this);
	//声明响应对话框对象
	requestdlg=new REQUESTCON(NULL);
	requestdlg->SetParent(this);
	
	// 设置SOCKET
	dcontrol.SetParent(this);
	daudio.SetParent(this);
	dvideo.SetParent(this);
	dtext.SetParent(this);
	drequest.SetParent(this);
	// Create  control datagram socket for handling messages
	dcontrol.CreateSocket(PORT_CONTROL,TYPE_CONTROL);//控制Socket
	drequest.CreateSocket(PORT_QUEST,TYPE_QUEST);//
	isStarted=FALSE;
	return TRUE; 

}






void CVideoVoiceTransDlg::OnSysCommand(UINT nID, LPARAM lParam)
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






//  If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CVideoVoiceTransDlg::OnPaint() 
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






HCURSOR CVideoVoiceTransDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}





void CVideoVoiceTransDlg::OnCancel() 
{
	
	// If conference is going on...then 
	// it must be destroyed...
	if(isStarted)
	DestroyConference();
	// Close the control session
	dcontrol.CloseSocket();
	drequest.CloseSocket();
	// End recording and player thread
	record->PostThreadMessage(WM_RECORDSOUND_ENDTHREAD,0,0);	
	play->PostThreadMessage(WM_PLAYSOUND_ENDTHREAD,0,0);
	// Close the video capture device
	vidcap->Destroy();		
	// Close graphics....
	if(hdib!=NULL)
	{
	::DrawDibEnd(hdib);
	::DrawDibClose(hdib);
	}	
	// Close the encoder
	if(isVideo)
	ExitH263Encoder(&cparams);
	// close decoder ......
	ExitH263Decoder();
	CDialog::OnCancel();
}




void CVideoVoiceTransDlg::OnConnectRemote()//执行连接命令
{
	connectdlg->DoModal();//显示连接对话框
}

void CVideoVoiceTransDlg::OnQuestRemote()//连接响应函数
{
	requestdlg->DoModal();//弹出响应连接对话框
}

void CVideoVoiceTransDlg::OnDisconnect()//断开连接响应函数
{
	dcontrol.SendControlMessage(MESG_DISCONNECT,NULL);//发送断开连接命令
	DestroyConference();//结束连接会话
}


void CVideoVoiceTransDlg::OnViewLocal()//显示、隐藏本地视频控制
{

	CMenu *menu=this->GetMenu();
	if(isViewLocalVideo)
	{
	isViewLocalVideo=FALSE;
	menu->CheckMenuItem(VIEW_LOCAL,MF_BYCOMMAND | MF_UNCHECKED);
	}
	else
	{
	isViewLocalVideo=TRUE;
	menu->CheckMenuItem(VIEW_LOCAL,MF_BYCOMMAND | MF_CHECKED);
	}
}

void CVideoVoiceTransDlg::OnViewRemote()//显示、隐藏对方视频控制
{

	CMenu *menu=this->GetMenu();
	
	if(isViewRemoteVideo)
	{
	isViewRemoteVideo=FALSE;
	menu->CheckMenuItem(VIEW_REMOTE,MF_BYCOMMAND | MF_UNCHECKED);
	}
	else
	{
	isViewRemoteVideo=TRUE;
	menu->CheckMenuItem(VIEW_REMOTE,MF_BYCOMMAND | MF_CHECKED);
	}
}
	

void CVideoVoiceTransDlg::OnVolumeControl()//显示音量控制对话框
{	
	Volume vol(IDD_DIALOG3);
	vol.DoModal();
}




/**
*	  Enables/Disables transmission of audio
*     Invoked when user presses Audio -> Send menu item
*/
void CVideoVoiceTransDlg::OnAudioSend()
{

	if(isAudioSend)
	{
		// Stop recording audio
		record->SuspendThread();//
		//>PostThreadMessage(WM_RECORDSOUND_STOPRECORDING,0,0);
		isAudioSend=FALSE;
		menu->CheckMenuItem(AUDIO_SEND,MF_BYCOMMAND | MF_UNCHECKED);

	}
	else
	{
		//Start recording audio
		record->ResumeThread();
		//record->PostThreadMessage(WM_RECORDSOUND_STARTRECORDING,0,0);
		isAudioSend=TRUE;
		menu->CheckMenuItem(AUDIO_SEND,MF_BYCOMMAND | MF_CHECKED);
	}
}


/**
*	  Enables/Disables reception of audio
*     Invoked when user presses Audio -> Receive menu item
*/
void CVideoVoiceTransDlg::OnAudioReceive()
{

	if(isAudioReceive)
	{
		isAudioReceive=FALSE;
		menu->CheckMenuItem(AUDIO_RECEIVE,MF_BYCOMMAND | MF_UNCHECKED);
	}
	else
	{
		isAudioReceive=TRUE;
		menu->CheckMenuItem(AUDIO_RECEIVE,MF_BYCOMMAND | MF_CHECKED);
	}
}
	

/**
*	  Enables/Disables transmission of video
*     Invoked when user presses Video-> Send menu item
*/
void CVideoVoiceTransDlg::OnVideoSend()
{

	if(isVideoSend)
	{
		isVideoSend=FALSE;
		menu->CheckMenuItem(VIDEO_SEND,MF_BYCOMMAND | MF_UNCHECKED);	
	}
	else
	{
		isVideoSend=TRUE;
		menu->CheckMenuItem(VIDEO_SEND,MF_BYCOMMAND | MF_CHECKED);
	}

}




/**
*	  Enables/Disables reception of video
*     Invoked when user presses Video -> Receive menu item
*/
void CVideoVoiceTransDlg::OnVideoReceive()
{

	if(isVideoReceive)
	{
		isVideoReceive=FALSE;
		menu->CheckMenuItem(VIDEO_RECEIVE,MF_BYCOMMAND | MF_UNCHECKED);
	}
	else
	{
		isVideoReceive=TRUE;
		menu->CheckMenuItem(VIDEO_RECEIVE,MF_BYCOMMAND | MF_CHECKED);
	}
}
	


/**
*	  Display the about dialog box
*/
void CVideoVoiceTransDlg::OnAbout()
{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
}




/**
*	  Send the message to remote host
*/
void CVideoVoiceTransDlg::OnSendMesg()
{
unsigned char data[500];

	GetDlgItemText(IDC_EDIT1,(char*)data,500);
	
	
	if(strlen((const char*)data)>0)
	{
	dtext.SendTextData(data,strlen((const char*)data));
	SetDlgItemText(IDC_EDIT1,"");
	}
		
}
void CVideoVoiceTransDlg::OnSnap()
{
	GetDlgItem(IDC_SNAP)->EnableWindow(false);
	GetDlgItem(IDC_PICSAVE)->EnableWindow(true);
	GetDlgItem(IDC_STOPSNAP)->EnableWindow(true);
	
	isPicdata=true;
	isSnap=true;
}
void CVideoVoiceTransDlg::OnPicSave()
{
	CString strFilter;
	CString m_FileName;
	strFilter="Bmp Files(*.bmp)|*.*||";
	CFileDialog dlg(FALSE, NULL, NULL, OFN_EXPLORER|OFN_HIDEREADONLY|
		OFN_ENABLESIZING|OFN_FILEMUSTEXIST,strFilter);
	//dlg.m_ofn.lStructSize = sizeof(OPENFILENAME);
	if(dlg.DoModal() == IDOK )
	{
		m_FileName=dlg.GetFileName();//GetPathName();
	
	CFile fp;
	fp.Open(m_FileName,CFile::modeCreate | CFile::modeWrite);
	BITMAPFILEHEADER bmfHdr; //定义文件头
	BITMAPINFOHEADER bmiHdr; //定义信息头
	//RGBQUAD rgbQuad[256];    //定义调色板
        //对信息头进行赋值
	 //bmiHdr=&m_bmpinfo->bmiHeader;
        //对调色板进行赋值
	//	for(i=0; i<256; i++)
	//	{
	//		rgbQuad[i].rgbBlue = (BYTE)i;
	//		rgbQuad[i].rgbGreen = (BYTE)i;
	//		rgbQuad[i].rgbRed = (BYTE)i;
	//		rgbQuad[i].rgbReserved = 0;
		//}
    //对文件头进行赋值
	bmfHdr.bfType = (WORD)0x4D42;//;((WORD)('M'<<8) | 'B')
	bmfHdr.bfSize=(DWORD)(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER)+IMAGE_WIDTH*IMAGE_HEIGHT*3);
	bmfHdr.bfReserved1 = 0;
	bmfHdr.bfReserved2 = 0;
	bmfHdr.bfOffBits=(DWORD)(sizeof(BITMAPFILEHEADER)+sizeof(BITMAPINFOHEADER));

	fp.Write((LPSTR)&bmfHdr,sizeof(BITMAPFILEHEADER)); //写文件头
	fp.Write((LPSTR)&m_bmpinfo->bmiHeader,sizeof(BITMAPINFOHEADER)); //写信息头
	//fp.Write((LPSTR)rgbQuad,sizeof(RGBQUAD)*256); //写调色板
	//fp.Write(lpvBuffer2Bits,m_WidthOfModel*m_HeightOfModel);//写数据
	fp.Write(imagedata,IMAGE_WIDTH*IMAGE_HEIGHT*3);//写数据

	fp.Close();
	}
	
}
void CVideoVoiceTransDlg::OnStopSnap()
{
	GetDlgItem(IDC_SNAP)->EnableWindow(true);
	GetDlgItem(IDC_PICSAVE)->EnableWindow(false);
	GetDlgItem(IDC_STOPSNAP)->EnableWindow(false);
	
	isPicdata=false;
	isSnap=false;
}

void CVideoVoiceTransDlg::OnQuerrySource()
{
	ShellExecute(GetParent()->GetSafeHwnd(), "open", "http://firenet.topcool.net", NULL, NULL, SW_SHOW);	
}

void CVideoVoiceTransDlg::OnAdvice()
{
	ShellExecute(GetParent()->GetSafeHwnd(), "open", "http://firenet.topcool.net", NULL, NULL, SW_SHOW);	
}
void CVideoVoiceTransDlg::OnSendFile()
{


}
void CVideoVoiceTransDlg::OnResult()
{
	CreatReport report;
	report.DoModal();
}

/**
*	  Display mesg received from the remote host
*/
void CVideoVoiceTransDlg::DisplayMesg(char *mesg)
{

	list->AddString(mesg);
	// Highlight the currently added string
	// This will scroll the window automatically
	list->SetCurSel(list->GetCount()-1);

	
}



/**
*	  Display frame got from remote host
*/
void CVideoVoiceTransDlg::DisplayRemoteFrame(unsigned char *data,int size)
{
int retvalue;

	// If remote view disabled then return...
	if(!isViewRemoteVideo)
	return;

	// If video reception disabled..then return..
	if(!isVideoReceive)
	return;

	retvalue=DecompressFrame(data,size,rgbdata,buffersize);

	if(!retvalue)
	{
		log.WriteString("\n Decompression failed");
		return;
	}
	if(isButtonShow)
	{
		GetDlgItem(IDC_SNAP)->EnableWindow(true);
		isButtonShow=FALSE;
	}



	log.WriteString("\n Decompression succeeded");

	if(!isSnap)
	{
	::DrawDibDraw(hdib,
				  m_hdc,
				  remote_wnd_x,		// dest : left pos
				  remote_wnd_y,		// dest : top pos
				  IMAGE_WIDTH*1.5,//-1,				// don't stretch
				  IMAGE_HEIGHT*1.5,//-1,				// don't stretch
				  &m_bmpinfo->bmiHeader,			 // bmp header info
				  rgbdata,					 // bmp data
				  0,					 // src :left
				  0,					 // src :top
				  IMAGE_WIDTH,				 // src : width
				  IMAGE_HEIGHT,				 // src : height
				  DDF_SAME_DRAW			 // use prev params....
				  );
	}
	else
	{
		if(isPicdata)
		{
			imagedata=new unsigned char[80000];
			for(int k=0;k<80000;k++)
			{
				imagedata[k]=rgbdata[k];
			}
			isPicdata=false;
		}
		::DrawDibDraw(hdib,
				  m_hdc,
				  remote_wnd_x,		// dest : left pos
				  remote_wnd_y,		// dest : top pos
				  IMAGE_WIDTH*1.5,//-1,				// don't stretch
				  IMAGE_HEIGHT*1.5,//-1,				// don't stretch
				  &m_bmpinfo->bmiHeader,			 // bmp header info
				  imagedata,					 // bmp data
				  0,					 // src :left
				  0,					 // src :top
				  IMAGE_WIDTH,				 // src : width
				  IMAGE_HEIGHT,				 // src : height
				  DDF_SAME_DRAW			 // use prev params....
				  );
	}


}



/**
*
*	Send the video frame to the remote host...
*
*/
void CVideoVoiceTransDlg::SendVideo(BYTE *data,int size)
{
CRect wndrect;
Bits bits;		// Various count about compression


	if(vidcap->isOver==TRUE)
	return;
	
	if(data==NULL)
	return;


	// Display the captured frame...
	if(isViewLocalVideo)
	{

	::DrawDibDraw(hdib,
				  m_hdc,
				  local_wnd_x,		// dest : left pos
				  local_wnd_y,		// dest : top pos
				  IMAGE_WIDTH*1.5,//-1,				// don't stretch
				  IMAGE_HEIGHT*1.5,//-1,				// don't stretch
				  &m_bmpinfo->bmiHeader,			 // bmp header info
				  data,					 // bmp data
				  0,					 // src :left
				  0,					 // src :top
				  IMAGE_WIDTH,				 // src : width
				  IMAGE_HEIGHT,				 // src : height
				  DDF_SAME_DRAW			 // use prev params....
				  );

	}

	
	if(isVideoSend)
	{

		//log.WriteString("\n Converting to YUV format..");
		
		//Convert the data from rgb format to YUV format	
		ConvertRGB2YUV(IMAGE_WIDTH,IMAGE_HEIGHT,data,yuv);


		// Reset the counter
		count=0;

		//Compress the data...to h263
		cparams.format=CPARAM_QCIF;
		cparams.inter = CPARAM_INTRA;  
		cparams.Q_intra = 8;
		cparams.data=yuv;		//  Data in YUV format...
		CompressFrame(&cparams, &bits);
		
		// Transmit the compressed frame
		//log.WriteString("Transmitting the frame");
		dvideo.SendVideoData(cdata,count);

	}

}


void CVideoVoiceTransDlg::StartConference()//两端开始对话
{
	if(isStarted)
	return;
	//状态标志赋值
	isStarted=TRUE;
	isViewLocalVideo=TRUE;
	isViewRemoteVideo=TRUE;
	//相应的菜单项更改状态
	menu->EnableMenuItem(CONF_CONNECT,MF_DISABLED | MF_GRAYED);
	menu->EnableMenuItem(CONF_DISCONNECT,MF_ENABLED);	
	menu->EnableMenuItem(AUDIO_SEND,MF_ENABLED);
	menu->EnableMenuItem(AUDIO_RECEIVE,MF_ENABLED);	
	menu->EnableMenuItem(VIDEO_SEND,MF_ENABLED);
	menu->EnableMenuItem(VIDEO_RECEIVE,MF_ENABLED);
	menu->EnableMenuItem(VIEW_LOCAL,MF_ENABLED);
	menu->EnableMenuItem(VIEW_REMOTE,MF_ENABLED);
	menu->CheckMenuItem(VIEW_LOCAL,MF_BYCOMMAND | MF_CHECKED);
	menu->CheckMenuItem(VIEW_REMOTE,MF_BYCOMMAND | MF_CHECKED);
	dtext.CreateSocket(PORT_TEXT,TYPE_TEXT);// 创建文本消息Socket
	bsend->EnableWindow(TRUE);//"发送"按钮生效
	daudio.CreateSocket(PORT_AUDIO,TYPE_AUDIO);//创建音频Socket
	dvideo.CreateSocket(PORT_VIDEO,TYPE_VIDEO);//创建视频Socket
	record->PostThreadMessage(WM_RECORDSOUND_STARTRECORDING,0,0);//开始录音	
	play->PostThreadMessage(WM_PLAYSOUND_STARTPLAYING,0,0);//开始放音
	if(isVideo)	// 开始视频捕捉
	{
		if(vidcap->StartCapture()==FALSE)
		{
			MessageBox("不能开始视频捕捉！");
			isCaptureStarted=FALSE;
		}
		else
		{
		isCaptureStarted=TRUE;
		}
	}
}



void CVideoVoiceTransDlg::OnMenuSkinLoad() 
{
	//---------------------------------------
	//For AppFace
	CString str =theApp.m_pszHelpFilePath ;
	str = str.Left(str.ReverseFind(_T('\\'))) ;
	CFileDialog f(TRUE,_T("bmp"),NULL,OFN_HIDEREADONLY | OFN_OVERWRITEPROMPT|OFN_NOCHANGEDIR,
		   _T("UI Resource Files (*.urf)|*.urf|All Files (*.*)|*.*||"),
		                            this);
	f.m_ofn.lpstrInitialDir = (LPCTSTR)str ;
	if(IDOK == f.DoModal())
	{
		theApp.m_af.Start((LPTSTR)(LPCTSTR)f.GetPathName());
	}		
	//---------------------------------------
	
}

void CVideoVoiceTransDlg::OnMenuSkinNo() 
{
	//---------------------------------------
	//For AppFace
	theApp.m_af.Start();
	//Do not call m_af.Remove() here !It will be released all the resource.
	//---------------------------------------	
}



/**
*	  Destroy the current conference
*/
void CVideoVoiceTransDlg::DestroyConference()
{

	// If not started / already destroyed..then return;
	if(isStarted==FALSE)
	return;

	isStarted=FALSE;
	isViewLocalVideo=FALSE;
	isViewRemoteVideo=FALSE;


	// Enable/disable menu items
	menu->EnableMenuItem(CONF_CONNECT,MF_ENABLED);
	menu->EnableMenuItem(CONF_DISCONNECT,MF_DISABLED | MF_GRAYED);


	// Disable Text session
	dtext.CloseSocket();

	// Disable the send button...
	bsend->EnableWindow(FALSE);

	// Clear the contents of text chat windows
	SetDlgItemText(IDC_EDIT1,"");
	list->ResetContent();

		
	// If recording is going on ...then stop it
	if(isAudioSend)
	record->SuspendThread();

	record->PostThreadMessage(WM_RECORDSOUND_STOPRECORDING,0,0);	 

	// stop audio session
	daudio.CloseSocket();

	// stop playing audio
	play->PostThreadMessage(WM_PLAYSOUND_STOPPLAYING,0,0);


	// stop capturing video
	if(isVideo && isCaptureStarted)
	vidcap->StopCapture();	
	
	// stop video session
	dvideo.CloseSocket();

	// Update local and remote viewer..
	CWnd *wnd=(CWnd*)this->GetDlgItem(IDC_LOCALVIDEO);
    wnd->Invalidate(TRUE);

	wnd=(CWnd*)this->GetDlgItem(IDC_REMOTEVIDEO);
    wnd->Invalidate(TRUE);

	// Reset the status..
	record->ResumeThread();

	isAudioSend=TRUE;
	menu->CheckMenuItem(AUDIO_SEND,MF_BYCOMMAND | MF_CHECKED);

	isAudioReceive=TRUE;
	menu->CheckMenuItem(AUDIO_RECEIVE,MF_BYCOMMAND | MF_CHECKED);
	
	isVideoSend=TRUE;
	menu->CheckMenuItem(VIDEO_SEND,MF_BYCOMMAND | MF_CHECKED);

	isVideoReceive=TRUE;
	menu->CheckMenuItem(VIDEO_RECEIVE,MF_BYCOMMAND | MF_CHECKED);

	menu->EnableMenuItem(AUDIO_SEND,MF_GRAYED);
	menu->EnableMenuItem(AUDIO_RECEIVE,MF_GRAYED);
	
	menu->EnableMenuItem(VIDEO_SEND,MF_GRAYED);
	menu->EnableMenuItem(VIDEO_RECEIVE,MF_GRAYED);

	menu->EnableMenuItem(VIEW_LOCAL,MF_GRAYED);
	menu->EnableMenuItem(VIEW_REMOTE,MF_GRAYED);

	GetDlgItem(IDC_SNAP)->EnableWindow(false);
	GetDlgItem(IDC_PICSAVE)->EnableWindow(false);
	GetDlgItem(IDC_STOPSNAP)->EnableWindow(false);
	/*if (imagedata!=NULL)
	{
		delete [] imagedata;
	}*/



}
