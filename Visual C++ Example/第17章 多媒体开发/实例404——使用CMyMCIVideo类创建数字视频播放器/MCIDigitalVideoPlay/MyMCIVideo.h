// MyMCIVideo.h: interface for the CMyMCIVideo class.
#include		<Mmsystem.h>   
#pragma   comment(lib,   "Winmm.lib")   
#include "Digitalv.h"
#include "mciavi.h"
class CMyMCIVideo  
{
public:
	CMyMCIVideo();
	virtual ~CMyMCIVideo();
	int OpenAvi(CString ,CWnd *pWnd, int left=0, int top=0, int width=20,int height=20);// 在pWnd窗口中打开视频设备
	int PlayAvi(int Loop=0, int FullScreen=0);    // 播放视频设备
	void Close(void);                     // 关闭视频文件
	void Stop();                         // 停止播放
	void Pause();                        // 暂停播放
	void Forward(int frame);              // 前进 frame帧
	void Backward(int frame);             // 后退frame帧
	int GetWidth();                    // 得到视频宽度
	int GetHeight();                   // 得到视频高度
	int GetFrame();                   // 得到当前帧数
	int GetFrames();                  // 得到视频总帧数
	int IsPlaying();                   // 查询播放状态
	int GetSpeed();                   // 查询播放速度
	BOOL GetPause();                   // 查询是否暂停的状态
	void SetSpeed(int speed);          // 设置播放速度
	BOOL SeekTo(int position);        // 跳到位置position播放
private :
	BOOL m_bOpen;                // 是否有媒体播放；1表示有文件被打开，否则为0
	BOOL m_bPause;               // 是否暂停：1 表示暂停，否则0
	BOOL m_bPlaying;              // 是否正在播放
	WORD m_wDeviceID;           // 播放设备ID
};

