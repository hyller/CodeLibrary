// CMyMCICD.h
#include	<Mmsystem.h>   
#pragma   comment(lib,   "Winmm.lib")   
class CMyMCICD
{
public:
	CMyMCICD();
	~CMyMCICD();
	BOOL OpenCD();//打开设备
	void Close();//关闭设备
	BOOL PlayCD();//播放CD
	void Stop();//停止
	void Pause();//暂停
	void CloseDrive();//关闭光驱
	void OpenDrive();//打开光驱
	int GetTotalTracks();//获得曲目数量
	int GetCurrentTrack();//获得当前播放的曲目
	void GetTotalLength(int *pnMinutes, int *pnSeconds );//获得所有曲目的总长度（时间）
	void GetTrackLength(int nTrack, int *pnMinutes, int *pnSeconds);//获得一个曲目的长度
	int GetMinutes();//获得当前播放曲目前已经播放的分钟数
	int GetSeconds();//获得当前播放曲目前经播放的秒数
	int GetFrames();//获得帧数
	BOOL IsDriveReady();//判断光驱里的cd是否正常
	BOOL IsPlaying(BOOL *pbPaused);//判断是否正在播放
	BOOL IsAudioTrack(int nTrack );//判断曲目是否是音乐
	BOOL SeekTo(int nTrack, int nMinute, int nSecond, int nFrame);//跳跃到某个曲目
	void SkipForward(int nSeconds);//向前跳跃给定时间
	void SkipBack(int nSeconds);//向后跳跃给定时间
private:
	BOOL m_bOpened, m_bPaused, m_bPlaying;//播放状态变量
	WORD m_wDeviceID;//播放设备ID
};

