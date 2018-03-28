// PlaySound1.h: interface for the PlaySound1 class.
//
//////////////////////////////////////////////////////////////////////




#if !defined(AFX_PlaySound_H__676E24A1_615E_11D6_889A_000B2B0F84B6__INCLUDED_)
#define AFX_PlaySound_H__676E24A1_615E_11D6_889A_000B2B0F84B6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000



#define WM_PLAYSOUND_STARTPLAYING WM_USER+600
#define WM_PLAYSOUND_STOPPLAYING WM_USER+601
#define WM_PLAYSOUND_PLAYBLOCK WM_USER+602
#define WM_PLAYSOUND_ENDTHREAD  WM_USER+603

#define SOUNDSAMPLES 1000
#define PLAYBUFFER   600
#define SAMPLEPSEC   8000

/*
#ifndef WAVE_FORMAT_GSM610
#define WAVE_FORMAT_GSM610 (0x0031)
#endif

*/

#include<afxmt.h>
#include<mmsystem.h>


class PlaySound1 : public CWinThread  
{
DECLARE_DYNCREATE(PlaySound1)

public:
	/*
	
	 For GSM WAVE FORMAT uncomment this..and comment next line...
	
	 struct wave
	{
	WAVEFORMATEX wfx;
	WORD wSamplesPerBlock;
	}m_WaveFormatEx;
	
	
	*/


	WAVEFORMATEX m_WaveFormatEx; 

	BOOL Playing;
	HWAVEOUT m_hPlay;
	CStdioFile log;
	CDialog *dlg;


	PlaySound1();
	PlaySound1(CDialog *dlg);
	virtual ~PlaySound1();
	BOOL InitInstance();
	int ExitInstance();

	void displayError(int code,char []);
	void displayHeader(LPWAVEHDR lphdr);
	LPWAVEHDR CreateWaveHeader(CString mesg);
	void ProcessSoundData(short int *sound, DWORD dwSamples);
	void GetDevProperty();
	
	afx_msg LRESULT OnStartPlaying(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnStopPlaying(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEndPlaySoundData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnWriteSoundData(WPARAM wParam, LPARAM lParam);
	afx_msg LRESULT OnEndThread(WPARAM wParam, LPARAM lParam);
	
	DECLARE_MESSAGE_MAP()


};





#endif // !defined(AFX_PlaySound_H__676E24A1_615E_11D6_889A_000B2B0F84B6__INCLUDED_)

