// VideoVoiceTransDlg.h : header file
//

#if !defined(AFX_VideoVoiceTransDLG_H__B0986306_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
#define AFX_VideoVoiceTransDLG_H__B0986306_5F44_11D6_8897_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include "DSocket.h"
#include "ConnectDlg.h"
#include "RecordSound.h"
#include "VideoCapture.h"
#include "PlaySound.h"
#include "Volume.h"
#include "Encoder/libr263.h"
#include "Decoder/tmndec.h"
#include "REQUESTCON.h"


class CVideoVoiceTransDlg : public CDialog
{

	// Attributes
	public:
	
	VideoCapture *vidcap;
	BOOL isVideo , isAudio , isStarted , isCaptureStarted;
	BOOL isViewLocalVideo,isViewRemoteVideo;
	BOOL isAudioSend,isAudioReceive;
	BOOL isVideoSend,isVideoReceive;
	BOOL isSnap;//ÊÇ·ñ²¶×½Í¼Ïñ
	BOOL isPicdata;//Í¼ÏñÊý¾Ý
	BOOL isButtonShow;//
	unsigned char* imagedata;

	PBITMAPINFO m_bmpinfo;
	BITMAPINFO compbmp;
	RecordSound *record;
	PlaySound1 *play;
	HDC m_hdc;

	CMenu *menu;
	CButton *bsend;
	CListBox *list;
	CStdioFile log;

	HICON m_hIcon;
	HWND hwnd;

	ConnectDlg *connectdlg;	
	REQUESTCON *requestdlg;
	
	DSocket dcontrol,daudio,dvideo,dtext,drequest;

	HDRAWDIB hdib;
	int local_wnd_x , local_wnd_y;
	int remote_wnd_x , remote_wnd_y;


	// Compression parameters....
	CParam cparams;
	
	// Buffer for storing YUV data....
	unsigned int yuv[ QCIF_WIDTH*QCIF_HEIGHT  + (QCIF_WIDTH*QCIF_HEIGHT)/2 ];

	CStatusBar  m_wndStatusBar;
	CToolBar    m_wndToolBar;



	
// Construction
public:
	CVideoVoiceTransDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVideoVoiceTransDlg)
	enum { IDD = IDD_VideoVoiceTrans_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoVoiceTransDlg)
public:	
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation




	// Generated message map functions
	//{{AFX_MSG(CVideoVoiceTransDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();

	afx_msg void OnMenuSkinLoad();
	afx_msg void OnMenuSkinNo();

	afx_msg HCURSOR OnQueryDragIcon();
	virtual void OnCancel();
	
	// Conference menu handlers
	void OnConnectRemote();
	void OnQuestRemote();
	void OnDisconnect();
	
	// View menu handlers
	void OnViewLocal();
	void OnViewRemote();
	
	
	//Audio menu handlers
	void OnVolumeControl();
	void OnAudioSend();
	void OnAudioReceive();
	

	// Video menu handlers
	void OnVideoSend();
	void OnVideoReceive();
	

	// Help menu handlers
	void OnAbout();
		
	void StartConference();
	
	void DestroyConference();

	void OnSendMesg();
	
	//button
	void OnSnap();//ÊÓÆµ²¶×½
	void OnPicSave();
	void OnStopSnap();
	void OnQuerrySource();
	void OnAdvice();
	void OnSendFile();
	void OnResult();



	void DisplayMesg(char *str);

	void SendVideo(BYTE *data,int size);

	void DisplayRemoteFrame(unsigned char *data,int size);

	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VideoVoiceTransDLG_H__B0986306_5F44_11D6_8897_000B2B0F84B6__INCLUDED_)
