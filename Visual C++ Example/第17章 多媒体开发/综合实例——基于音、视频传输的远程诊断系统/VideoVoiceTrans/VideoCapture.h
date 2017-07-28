// VideoCapture.h: interface for the VideoCapture class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_VIDEOCAPTURE_H__5C825E61_611A_11D6_889B_000B2B0F84B6__INCLUDED_)
#define AFX_VIDEOCAPTURE_H__5C825E61_611A_11D6_889B_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#include<vfw.h>
#include<afxmt.h>
//#include<afxole.h>

/****************************   NOTE **************************/
//  If the parameters below are changed then change following
//  > cdata & cbuffer_size in VideoVoiceTransDlg.cpp
//  > rgbdata & buffersize in VideoVoiceTransDlg.cpp
//  > update CPARAMS structure before compression
//  > computation of local_wnd_x para in OnInitDialog()
//
////////////////////////////////////////////////////////////////

#define QCIF_WIDTH  176
#define QCIF_HEIGHT 144

#define IMAGE_WIDTH       QCIF_WIDTH
#define IMAGE_HEIGHT      QCIF_HEIGHT
    

class VideoCapture  
{
public:
	
	HWND m_capwnd;
	CStdioFile log;
	CAPDRIVERCAPS caps;
	CMutex protectframe;
	int avgaudiosize;
	BOOL isOver;
	CDialog *dlg;
	BITMAPINFOHEADER m_bmpheader;
	BITMAPINFO m_bmpinfo;

	VideoCapture();
	virtual ~VideoCapture();
	void SetDialog(CDialog *dlg);
	BOOL Initialize();
	BOOL SetCapturePara();
	void Destroy();
	void GetDriverCaps();
	void SetAudioFormat();
	int AllocateMemory(PBITMAPINFO &bmpinfo);
	int getFormatSize(BITMAPINFO bmp);
    int getImageSize(BITMAPINFO bmp);

	BOOL StartCapture();
	BOOL StopCapture();

    friend LRESULT CALLBACK OnCaptureVideo(HWND hWnd, LPVIDEOHDR lpheader) ;


};


#endif // !defined(AFX_VIDEOCAPTURE_H__5C825E61_611A_11D6_889B_000B2B0F84B6__INCLUDED_)
