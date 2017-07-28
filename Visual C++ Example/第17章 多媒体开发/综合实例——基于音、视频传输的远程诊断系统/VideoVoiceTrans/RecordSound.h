// RecordSound.h: interface for the RecordSound class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RECORDSOUND_H__EA26EF41_4169_11D6_8886_F00753C10001__INCLUDED_)
#define AFX_RECORDSOUND_H__EA26EF41_4169_11D6_8886_F00753C10001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define WM_RECORDSOUND_STARTRECORDING WM_USER+500
#define WM_RECORDSOUND_STOPRECORDING WM_USER+501
#define WM_RECORDSOUND_ENDTHREAD WM_USER+502

#define SAMPLERSEC 8000
#define MAXRECBUFFER 12
#define RECBUFFER  600

/*  Used for GSM wave format....
#ifndef WAVE_FORMAT_GSM610
#define WAVE_FORMAT_GSM610  (0X0031)
#endif
*/

#include<mmsystem.h>
#include<mmreg.h>



class RecordSound : public CWinThread  
{

	DECLARE_DYNCREATE(RecordSound)
	
	CStdioFile log; 
	CDialog *dlg;
	

	HWAVEIN m_hRecord;
	/* Used for GSM wave format...
	struct wave
	{
	WAVEFORMATEX wfx;
	WORD wSamplesPerBlock;
	}m_WaveFormatEx;
*/
	WAVEFORMATEX m_WaveFormatEx; 
	
	BOOL recording;
	int isallocated;
	LPWAVEHDR rechead[MAXRECBUFFER];


public:
	
	RecordSound();
	RecordSound(CDialog *dlg);
	virtual ~RecordSound();
	void GetDevProperty();
	BOOL InitInstance();
	int ExitInstance();
	void PreCreateHeader();
	void displayError(int errcode,char []);

	afx_msg LRESULT OnStartRecording(WPARAM wp,LPARAM lp);
	afx_msg LRESULT OnStopRecording(WPARAM wp,LPARAM lp);
	afx_msg LRESULT OnEndThread(WPARAM wp,LPARAM lp);
	LRESULT OnSoundData(WPARAM wParam, LPARAM lParam);
	LPWAVEHDR CreateWaveHeader();

DECLARE_MESSAGE_MAP()	
};

#endif // !defined(AFX_RECORDSOUND_H__EA26EF41_4169_11D6_8886_F00753C10001__INCLUDED_)
