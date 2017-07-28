// MCIWave.cpp: implementation of the CMyMCIWave class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "MCIWavPlay.h"
#include "MyMCIWave.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CMyMCIWave::CMyMCIWave()
{
	//进行状态指示变量的初始化
	m_bPlaying = FALSE;
    m_bRecord = FALSE;
    m_bOpen = FALSE;
    m_wDeviceID = 0;
}

CMyMCIWave::~CMyMCIWave()
{
	CloseWave();//关闭WAV文件
}
DWORD CMyMCIWave::OpenWave(CString strFileName)//打开波形文件
{
	if (m_bOpen)//如果文件已经打开
	{
		CloseWave();//关闭该文件
	}
	DWORD dwOpenFlag;//打开标记
	MCI_OPEN_PARMS mciOpenParam;//MCI_OPEN_PARMS结构
	mciOpenParam.lpstrDeviceType = "WaveAudio";//MCI设备类型
	mciOpenParam.lpstrElementName = strFileName;//打开文件名
	//初始化MCI设备
	dwOpenFlag = mciSendCommand(NULL, MCI_OPEN, MCI_OPEN_ELEMENT|MCI_OPEN_TYPE, (DWORD)(LPVOID)&mciOpenParam);
	if (dwOpenFlag)//初始化失败
		return dwOpenFlag;//返回错误代码
	m_wDeviceID = mciOpenParam.wDeviceID;//设备ID
	m_bOpen = TRUE;
	dwOpenFlag = 0;
	MCI_SET_PARMS mciSetParam;
	mciSetParam.dwTimeFormat = MCI_FORMAT_MILLISECONDS;//时间参数设置为毫秒
	//改变时间控制设置
	dwOpenFlag = mciSendCommand(m_wDeviceID,MCI_SET,MCI_SET_TIME_FORMAT,(DWORD)(LPVOID)&mciSetParam);
	if (dwOpenFlag)//设置失败
		return dwOpenFlag;//返回错误代码
	return 0;
}

DWORD CMyMCIWave::PlayWave()//播放波形文件
{
	MCI_PLAY_PARMS mciPlayParam;
	DWORD dwPlayFlag;
	dwPlayFlag = mciSendCommand(m_wDeviceID, MCI_PLAY, NULL, (DWORD)(LPVOID)&mciPlayParam);//开始播放数据
	if (dwPlayFlag)//播放失败
		return dwPlayFlag;//返回错误代码
	else
	{
		m_bPlaying = TRUE;
		return 0;
	}
}
void CMyMCIWave::StopWave()//停止播放波形文件
{
	mciSendCommand(m_wDeviceID, MCI_STOP, NULL, NULL);//停止播放
}
DWORD CMyMCIWave::RecordWave()
{
	if (m_bOpen)//如果有文件打开
		CloseWave();//关闭文件
	DWORD dwRecordFlag;
	MCI_OPEN_PARMS mciOpenParam;
	mciOpenParam.lpstrDeviceType = " waveAudio ";
	mciOpenParam.lpstrElementName = NULL;
	//初始化MCI设备
	dwRecordFlag = mciSendCommand(NULL, MCI_OPEN,MCI_OPEN_ELEMENT | MCI_OPEN_TYPE | MCI_WAIT, (DWORD)(LPVOID)&mciOpenParam);
	if (dwRecordFlag)//初始化失败
		return dwRecordFlag;//返回错误代码
	m_wDeviceID = mciOpenParam.wDeviceID;
	MCI_RECORD_PARMS mciRecordParam;
	//开始记录数据
	dwRecordFlag = mciSendCommand(m_wDeviceID, MCI_RECORD,MCI_RECORD_OVERWRITE, (DWORD)(LPVOID)&mciRecordParam);
	if (dwRecordFlag)//记录数据失败
		return dwRecordFlag;//返回错误代码
	m_bRecord = TRUE;
	m_bOpen = TRUE;
	return 0;
}
DWORD CMyMCIWave::SaveWave(CString strFileName)//保存波形文件
{
    if (m_bRecord)//正在录音
        return 0;//返回
	StopWave();//停止录音
	MCI_SAVE_PARMS mciSaveParam;
	mciSaveParam.lpfilename = strFileName;//设置保存的文件
	//保存WAV数据到文件
	DWORD dwSaveFlag = mciSendCommand(m_wDeviceID, MCI_SAVE,MCI_SAVE_FILE | MCI_WAIT, (DWORD)(LPVOID)&mciSaveParam);
	if (dwSaveFlag)//保存失败
		return dwSaveFlag;//返回错误代码
	m_bRecord = FALSE;
	return 0;
}
DWORD CMyMCIWave::CloseWave()
{
	if (m_wDeviceID)//有MCI设备在工作
	{
		DWORD dwCloseFlag;
		mciSendCommand(m_wDeviceID, MCI_STOP, MCI_WAIT, NULL);//停止工作
		dwCloseFlag = mciSendCommand(m_wDeviceID, MCI_CLOSE, NULL, NULL);//关闭设备
		if (dwCloseFlag)
		{
			AfxMessageBox("关闭时出现错误");
			return dwCloseFlag;
		}
	}
	//设置状态变量
	m_bRecord = FALSE;
	m_bOpen = FALSE;
	m_bPlaying = FALSE;
	m_wDeviceID = NULL;
	return 0;
}
DWORD CMyMCIWave::GetSampleRate()//获取采样率
{
	MCI_STATUS_PARMS mciStatusParam;
	mciStatusParam.dwItem = MCI_WAVE_STATUS_SAMPLESPERSEC;//采样频率
	//MCI设备的状态信息（采样频率）
	DWORD dwStatusFlag = mciSendCommand(m_wDeviceID, MCI_STATUS,MCI_WAIT | MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParam);
	if (dwStatusFlag)
		return dwStatusFlag;//返回错误代码
	else
		return mciStatusParam.dwReturn;//返回采样频率
}
DWORD CMyMCIWave::GetChannel()//获取声道数
{
	MCI_STATUS_PARMS mciStatusParam;
	mciStatusParam.dwItem = MCI_WAVE_STATUS_CHANNELS;//声道数
	//MCI设备的状态信息（声道数）
	DWORD dwStatusFlag = mciSendCommand(m_wDeviceID, MCI_STATUS,MCI_WAIT | MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParam);
	if (dwStatusFlag)
		return dwStatusFlag;
	else
		return mciStatusParam.dwReturn;//返回声道数
}
DWORD CMyMCIWave::GetBitLength()//获取声音位长
{
	MCI_STATUS_PARMS mciStatusParam;
	mciStatusParam.dwItem = MCI_WAVE_STATUS_BITSPERSAMPLE;//声音位长
	//MCI设备的状态信息（声音位长）
	DWORD dwStatusFlag = mciSendCommand(m_wDeviceID, MCI_STATUS,MCI_WAIT|MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParam);
	if (dwStatusFlag)
		return dwStatusFlag;
	else
		return mciStatusParam.dwReturn;//返回位长
}
DWORD CMyMCIWave::GetWaveLength()//获取波形文件的时长
{
	MCI_STATUS_PARMS mciStatusParam;
	mciStatusParam.dwItem = MCI_STATUS_LENGTH;//音频长度
	//返回MCI设备的状态信息（音频长度）
	DWORD dwStatusFlag = mciSendCommand(m_wDeviceID, MCI_STATUS,MCI_WAIT | MCI_STATUS_ITEM, (DWORD)(LPVOID)&mciStatusParam);
	if (dwStatusFlag)
		return dwStatusFlag;
	else
		return mciStatusParam.dwReturn;//返回音频长度
}