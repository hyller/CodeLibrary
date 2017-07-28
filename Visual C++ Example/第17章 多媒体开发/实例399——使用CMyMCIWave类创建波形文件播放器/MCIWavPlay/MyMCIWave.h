// MCIWave.h: interface for the CMCIWave class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_MCIWAVE_H__4D73F398_C689_46D2_AD2A_446EC8C3137F__INCLUDED_)
#define AFX_MCIWAVE_H__4D73F398_C689_46D2_AD2A_446EC8C3137F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include	<Mmsystem.h>   
#pragma   comment(lib,   "Winmm.lib")   
class CMyMCIWave  
{
public:
	CMyMCIWave();//构造函数
	virtual ~CMyMCIWave();//析构函数
	DWORD OpenWave(CString strFileName);                  //打开文件
	DWORD CloseWave();                  //关闭文件
	DWORD PlayWave();                   //播放
	void  StopWave();                   //停止播放
	DWORD RecordWave();                 //录制
	DWORD SaveWave(CString strFileName);  //保存
	DWORD  GetBitLength();          //得到位长
	DWORD GetSampleRate();          //得到采样率
	DWORD  GetChannel();             //得到当前声道
	DWORD GetWaveLength();         //得到音频长度
public:
	BOOL m_bPlaying;               //是否正在播放
	BOOL m_bRecord;                //是否在录音
	BOOL m_bOpen;                 //文件是否打开
	WORD m_wDeviceID;            //播放设备ID
};

#endif // !defined(AFX_MCIWAVE_H__4D73F398_C689_46D2_AD2A_446EC8C3137F__INCLUDED_)
