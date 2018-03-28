#if !defined(AFX_DSOCKET_H__B098630F_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
#define AFX_DSOCKET_H__B098630F_5F44_11D6_8897_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


// Type of datagram socket

#define TYPE_CONTROL 11
#define TYPE_AUDIO   12
#define TYPE_VIDEO   13
#define TYPE_TEXT    14
#define TYPE_QUEST    15

// Port used for different datagram sockets

#define PORT_CONTROL 6000
#define PORT_AUDIO   6002
#define PORT_VIDEO   6004
#define PORT_TEXT    6006
#define PORT_QUEST    6008

// Message Types...
#define MESG_CONNECT     101
#define MESG_DISCONNECT  102
#define MESG_ACCEPT      103
#define MESG_REJECT      104



/////////////////////////////////////////////////////////////////////////////
// DSocket command target

class DSocket : public CSocket
{
// Attributes
public:
	
	CDialog *pdlg;
	char localname[200];
	static char remotename[500];
	static char remoteaddress[500];
	int type;
	static unsigned char data[2000],vdata[30000],adata[5000];
	static unsigned int length,vlength,alength;



	
// Operations
public:

	DSocket();
	virtual ~DSocket();	
	void CreateSocket(int port,int type);
	void SetParent(CDialog *dlg);
	void OnReceive(int errcode);
	void SendControlMessage(int type,char *address);
	void SendAudioData(unsigned char *data,int length);
	void SendVideoData(unsigned char *data,int length);
	void SendTextData(unsigned char *data,short length);
	void SendRequestCon(unsigned char *data,short length);
	void CloseSocket();


};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DSOCKET_H__B098630F_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
