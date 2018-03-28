// MyMCIVideo.cpp: implementation of the CMyMCIVideo class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MCIDigitalVideoPlay.h"
#include "MyMCIVideo.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyMCIVideo::CMyMCIVideo()
{
	//初始化状态变量
	m_bOpen = FALSE;
	m_bPause = FALSE;
	m_bPlaying = FALSE;
	m_wDeviceID = NULL;
}

CMyMCIVideo::~CMyMCIVideo()
{
	Close();    // 关闭视频设备
}
int CMyMCIVideo::OpenAvi(CString FileName, CWnd* pWnd, int left, int top, int width, int height)
{
	if (!m_bOpen)      // 如果m_bOpen＝FALSE，没有打开设备
	{
		//初始化数据成员
		m_bOpen = m_bPause = m_bPlaying = FALSE;
		m_wDeviceID = NULL;
		//判断数字视频文件是否存在
		CFileStatus fileStatus;
		if (!CFile::GetStatus(FileName, fileStatus))
				 return 0;
		//打开设备，并获的视频设备的ID号
		MCI_DGV_OPEN_PARMS mciOpenParms;
		mciOpenParms.lpstrDeviceType = "AviVideo";    //设置播放设备为视频播放设备
		mciOpenParms.lpstrElementName = (LPSTR)FileName.GetBuffer(0);  //赋给文件名
		mciOpenParms.wDeviceID = NULL;
		mciOpenParms.hWndParent = pWnd->m_hWnd;  //可播放视频文件窗口指针
		mciOpenParms.dwStyle = WS_CHILD|WS_VISIBLE;
		if (mciSendCommand(NULL, MCI_OPEN, MCI_WAIT|MCI_OPEN_TYPE|MCI_OPEN_ELEMENT|MCI_DGV_OPEN_PARENT|MCI_DGV_OPEN_WS, (DWORD)(LPVOID)&mciOpenParms))
		{
			return 0;
		}
		m_wDeviceID = mciOpenParms.wDeviceID;
		m_bOpen = TRUE;    //表示视频设备已经被正确获得
		// 对视频设备的播放进行初始化
		MCI_DGV_SET_PARMS mciSetParms;
		mciSetParms.dwTimeFormat = MCI_FORMAT_FRAMES;// 设置视频文件播放单位为帧
		if (mciSendCommand(m_wDeviceID, MCI_SET, MCI_SET_TIME_FORMAT,(DWORD)(LPVOID)& mciSetParms))
		{
			Close();
			return 0;    //表示打开设备时出错
		}
		// 把视频文件当前的位置设为开始位置
		mciSendCommand(m_wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
		// 将播放画面置于pWnd窗口之中
		MCI_DGV_PUT_PARMS mciPutParms;
		mciPutParms.rc.left = left;
		mciPutParms.rc.top = top;        //视频播放窗口左上角的坐标
		mciPutParms.rc.right = left + width;
		mciPutParms.rc.bottom = top + height;
		if (mciSendCommand(m_wDeviceID, MCI_PUT, MCI_WAIT |MCI_DGV_PUT_CLIENT | MCI_DGV_PUT_WINDOW | MCI_DGV_RECT, (DWORD)(LPVOID)& mciPutParms))
		{
			Close();
			return 0;
		}
	}
	return 1;
}
int CMyMCIVideo::PlayAvi(int Loop, int FullScreen)//播放
{
	if (m_bOpen)
	{
		// 如果是视频的尾部则重新开始
		if (GetFrame()>=GetFrames())
			mciSendCommand(m_wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);//定位到起始位置
		MCI_DGV_PLAY_PARMS mciPlayParms;
		mciPlayParms.dwCallback = NULL;
		mciPlayParms.dwFrom = GetFrame();    // 得到当前的视频位置
		DWORD dwFlags = MCI_FROM;
		if (Loop)
			dwFlags |=MCI_DGV_PLAY_REPEAT;    //循环播放标志
		if (FullScreen)
			dwFlags |=MCI_MCIAVI_PLAY_FULLSCREEN;    //全屏幕播放标志
		if (mciSendCommand(m_wDeviceID,MCI_PLAY,dwFlags,(DWORD)(LPVOID)&mciPlayParms))//开始播放
		{
			return 0;
		}
		//设置状态变量的值
		m_bPause = FALSE;
		m_bPlaying = TRUE;
		return 1;
	}
	return 1;
}
void CMyMCIVideo::Close()
{
	if (m_bOpen)
	{
		mciSendCommand(m_wDeviceID, MCI_STOP, NULL, NULL);    // 发送停止消息
		mciSendCommand(m_wDeviceID, MCI_CLOSE, NULL, NULL);  // 发送关闭消息
		m_bOpen = m_bPause = m_bPlaying = FALSE;
	    m_wDeviceID = NULL;
	}
}
void CMyMCIVideo::Stop()
{
	if (m_bOpen && m_bPlaying)
	{
		mciSendCommand(m_wDeviceID, MCI_STOP, NULL, NULL);
		mciSendCommand(m_wDeviceID, MCI_SEEK, MCI_SEEK_TO_START, NULL);
		m_bPause = TRUE;
	    m_bPlaying = FALSE;
	}
}
void CMyMCIVideo::Pause()
{
	if (m_bOpen)
	{
		MCI_DGV_PAUSE_PARMS mciPauseParms;
		if (mciSendCommand(m_wDeviceID, MCI_PAUSE, NULL,
		(DWORD)(LPVOID) & mciPauseParms))
			return;
		m_bPause = TRUE;
	}
}
void CMyMCIVideo::Forward(int nFrames)
{
	if (m_bOpen)
	{
		if (m_bPlaying && !m_bPause)
			Pause();
		MCI_DGV_STEP_PARMS mciStepParms;
		mciStepParms.dwFrames = nFrames;
		mciSendCommand(m_wDeviceID, MCI_STEP, MCI_DGV_STEP_FRAMES, 
		(DWORD)(LPVOID)&mciStepParms);
	}
}
void CMyMCIVideo::Backward(int nFrames)
{
	if (m_bOpen)
	{
		if (m_bPlaying && !m_bPause)
			Pause();
		MCI_DGV_STEP_PARMS mciStepParms;
		mciStepParms.dwFrames = nFrames;
		mciSendCommand(m_wDeviceID, MCI_STEP, MCI_DGV_STEP_REVERSE | 
		MCI_DGV_STEP_FRAMES, (DWORD)(LPVOID)&mciStepParms);
	}
}
void CMyMCIVideo::SetSpeed(int nSpeed)
{
	if (m_bOpen)
	{
		MCI_DGV_SET_PARMS mciSetParms;//参数结构
		mciSetParms.dwSpeed = nSpeed;
		//发送MCI_SET命令，设置播放速度
		mciSendCommand(m_wDeviceID, MCI_SET, MCI_WAIT | MCI_DGV_SET_SPEED,(DWORD)(LPVOID)&mciSetParms);
	}
}
BOOL CMyMCIVideo::SeekTo(int nFrame)
{
	if (m_bOpen)
	{
		MCI_SEEK_PARMS mciSeekParms;
		mciSeekParms.dwTo = nFrame;
		if (m_bPlaying && !m_bPause)
		    mciSendCommand(m_wDeviceID, MCI_PAUSE, 0, NULL);
	    if (mciSendCommand(m_wDeviceID, MCI_SEEK, MCI_TO | MCI_WAIT,
	      (DWORD)(LPVOID)&mciSeekParms))
        	return FALSE;
		if (m_bPlaying && m_bPause)
			PlayAvi();
		return TRUE;
	}
	return FALSE;
}
int CMyMCIVideo::GetFrames()//获取视频的总帧数
{
	if (m_bOpen)
	{
		MCI_DGV_STATUS_PARMS mciStatusParms;
	    mciStatusParms.dwItem = MCI_STATUS_LENGTH;
		if (mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT|
		MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
			return 0;
		return (int)mciStatusParms.dwReturn;
	}
	return 0;
}
int CMyMCIVideo::GetFrame()
{
	if (m_bOpen)
	{
		MCI_DGV_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_STATUS_POSITION;
		if (mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT |
		MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
			return -1;
		return (int)mciStatusParms.dwReturn;
	}
	return -1;
}
int CMyMCIVideo::GetSpeed()
{
	if (m_bOpen)
	{
		MCI_DGV_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_DGV_STATUS_SPEED;
		if (mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT |
		MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
			return -1;
		return (int)mciStatusParms.dwReturn;
	}
	return -1;
}
BOOL CMyMCIVideo::IsPlaying()
{
	if (m_bOpen)
	{
		MCI_DGV_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_STATUS_MODE;
		if (mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT |
			MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
			return FALSE;
		if (mciStatusParms.dwReturn == MCI_MODE_PLAY)
		{
			m_bPlaying = TRUE;
			m_bPause = FALSE;
			return TRUE;
		}
		else if(mciStatusParms.dwReturn == MCI_MODE_PAUSE)
		{
			m_bPlaying = TRUE;
			m_bPause = TRUE;
			return TRUE;
		}
		else
		{
			m_bPlaying = FALSE;
			m_bPause = FALSE;
			return FALSE;
		}
	}
	return FALSE;
}
int CMyMCIVideo::GetWidth()
{
	if (m_bOpen)
	{
		MCI_DGV_WHERE_PARMS mciWhereParms;
		if (mciSendCommand(m_wDeviceID, MCI_WHERE,
			MCI_DGV_WHERE_SOURCE, (DWORD)(LPVOID)&mciWhereParms))
			return 0;
		return (int) mciWhereParms.rc.right;
	}
	return 0;
}
int CMyMCIVideo::GetHeight()
{
	if (m_bOpen)
	{
		MCI_DGV_WHERE_PARMS mciWhereParms;
		if (mciSendCommand(m_wDeviceID, MCI_WHERE,
		MCI_DGV_WHERE_SOURCE, (DWORD)(LPVOID)&mciWhereParms))
			return 0;
		return (int) mciWhereParms.rc.bottom;
	}
	return 0;
}
BOOL CMyMCIVideo::GetPause()
{
	if (m_bOpen)
	{
		MCI_DGV_STATUS_PARMS mciStatusParms;
		mciStatusParms.dwItem = MCI_STATUS_MODE;
		if (mciSendCommand(m_wDeviceID, MCI_STATUS, MCI_WAIT |
			MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParms))
			return FALSE;
		if(mciStatusParms.dwReturn == MCI_MODE_PAUSE)
		{
			return TRUE;
		}
		else
		{
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}
