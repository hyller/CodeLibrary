
#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "DSocket.h"
#include "VideoVoiceTransDlg.h"
#include "RequestDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// DSocket

// Initialize static members...
char DSocket::remoteaddress[500]="";
char DSocket::remotename[500]="";
unsigned char DSocket::data[2000];
unsigned char DSocket::vdata[30000];
unsigned char DSocket::adata[5000];
unsigned int DSocket::length=2000;
unsigned int DSocket::vlength=30000;
unsigned int DSocket::alength=5000;


DSocket::DSocket()
{

}

DSocket::~DSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(DSocket, CSocket)
	//{{AFX_MSG_MAP(DSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// DSocket member functions

void DSocket::CreateSocket(int port,int dtype)
{
	this->Create(port,SOCK_DGRAM);//创建Socket
	type=dtype;//Socket类型
	gethostname(localname,300);//获取对端用户名
}


void DSocket::SetParent(CDialog *dlg)
{
	pdlg=dlg;	
}

/**
*    Invoked when any data arrives from the remote host
*
*/
void DSocket::OnReceive(int errcode)
{
	CString address;
	char hname[400],str[1000],mesg[500];
	unsigned int port,retvalue;
	int n,len;
	RequestDlg rdlg(NULL);//请求连接对话框
	if(type==TYPE_CONTROL)//Socket为命令消息Socket
	{	
		retvalue=this->ReceiveFrom(data,length,address,port);//接收对端消息
		if(retvalue==SOCKET_ERROR)
		return;
		for(int i=0;i<data[1];i++)
		hname[i]=data[i+2];
		hname[i]=0;
		strcpy(remotename,hname);//获取对端名称
		strcpy(remoteaddress,(LPCTSTR)address);	
		switch(data[0])
		{
			
			case MESG_CONNECT://连接消息
			// display the accept , reject dialog box
			rdlg.SetParameter(remotename,remoteaddress,pdlg);
			rdlg.DoModal();//弹出请求连接对话框
			return;	
			case MESG_DISCONNECT://断开连接
			( (CVideoVoiceTransDlg*)pdlg)->DestroyConference();
			sprintf(str,"用户 %s 断开了连接！",hname);
			AfxMessageBox(str);
			return;
			case MESG_ACCEPT://接收连接
			AfxMessageBox("用户已经接受了连接请求！");
			( (CVideoVoiceTransDlg*)pdlg)->StartConference();//开始交互
			return;
			case MESG_REJECT://拒绝连接
			sprintf(str,"用户 %s 拒绝了连接请求",hname);
			AfxMessageBox(str);
			return;
		}
		return;
	}

	if(type==TYPE_AUDIO)//音频Socket
	{
		
		retvalue=this->ReceiveFrom(adata,alength,address,port);//接收音频数据
		if(retvalue==SOCKET_ERROR)
		return;
		((CVideoVoiceTransDlg *)pdlg)->play->PostThreadMessage(WM_PLAYSOUND_PLAYBLOCK,retvalue,(LPARAM)adata);//播放声音	
		return;
	}
	if(type==TYPE_VIDEO)//视频Socket
	{
		
		retvalue=this->ReceiveFrom(vdata,vlength,address,port);//接收视频数据
		if(retvalue==SOCKET_ERROR)
		return;
		((CVideoVoiceTransDlg *)pdlg)->DisplayRemoteFrame(vdata,retvalue);//显示对端视频
		return;
	}
	if(type==TYPE_TEXT)//文本Socket
	{
		
		retvalue=this->ReceiveFrom(data,length,address,port);//接收文本信息
		if(retvalue==SOCKET_ERROR)
		return;
		n=data[1];
		for(int i=0;i<n;i++)
		hname[i]=data[i+2];
		hname[i]=0;	
		len=data[n+2] | ( data[n+3]<<8 );
		memcpy(mesg,&data[n+4],len);
		mesg[len]=0;
		sprintf(str,"%s >> %s ",hname,mesg);
		((CVideoVoiceTransDlg *)pdlg)->DisplayMesg(str);//在列表框显示文本
		return;
	}
}


/**
*       Send the control data to remote host
*
*
*/
void DSocket::SendControlMessage(int type,char *address)
{
	char data[1000];
	int n;
	data[0]=type;//第一个字节为命令类型标识				
	n=strlen(localname);//本端机器名	
	data[1]=n;//第二个字节为名字长度						
	memcpy(&data[2],localname,n);
	if(address==NULL)
	{	
		SendTo(data,n+2,PORT_CONTROL,remoteaddress);
	}
	else
	{
		SendTo(data,n+2,PORT_CONTROL,address);//发送命令消息数据
	}
}


void DSocket::SendAudioData(unsigned char *data,int length)//发送音频数据
{
	SendTo(data,length,PORT_AUDIO,remoteaddress);	
}

void DSocket::SendVideoData(unsigned char *data,int length)//发送视频数据
{
	SendTo(data,length,PORT_VIDEO,remoteaddress);	
}


void DSocket::SendTextData(unsigned char *data,short length)//发送文本数据
{
	unsigned char *packet=new unsigned char[length+500];
	int n;	
	packet[0]=TYPE_TEXT;//第一个字节存储类型
	n=strlen(localname);//本机名称长度
	packet[1]=n;	
	// Hostname
	memcpy(&packet[2],localname,n);//将本节名称加入数据
	packet[n+2]=(unsigned char) length;//文本消息长度
	packet[n+3]=(unsigned char) (length>>8);
	memcpy(&packet[n+4],data,length);	
	SendTo(packet,n+4+length,PORT_TEXT,remoteaddress);//发送数据	
}


void DSocket::SendRequestCon(unsigned char *data,short length)
{
	
	//static char address[50];
	//address[50]="127.0.0.1";
	SendTo(data,length,PORT_QUEST,"127.0.0.1");
	
}

/**
*    Closes the socket created by the createsocket method
*
*/
void DSocket::CloseSocket()
{
	DSocket::Close();
}
