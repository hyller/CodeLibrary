////////////////////////////////////////////////////////////////////////////
//
//
//    Project     : VideoVoiceTrans version 1.1.
//    Description : Peer to Peer Video Conferencing over the LAN.
//	  Author      :	Nagareshwar Y Talekar ( nsry2002@yahoo.co.in)
//    Date        : 15-6-2004.
//
//
//    File description : 
//    Name    : RecordSound.cpp
//    Details : Recording audio from the capture device such as microphone
//
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "VideoVoiceTransDlg.h"
#include "RecordSound.h"

#include<mmsystem.h>
#include<mmreg.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(RecordSound, CWinThread)


BEGIN_MESSAGE_MAP(RecordSound,CWinThread)
ON_THREAD_MESSAGE(MM_WIM_DATA, OnSoundData)
ON_THREAD_MESSAGE(WM_RECORDSOUND_STARTRECORDING,OnStartRecording)
ON_THREAD_MESSAGE(WM_RECORDSOUND_STOPRECORDING,OnStopRecording)
ON_THREAD_MESSAGE(WM_RECORDSOUND_ENDTHREAD,OnEndThread)
END_MESSAGE_MAP()


RecordSound::RecordSound()
{

}


RecordSound::RecordSound(CDialog *dialog)
{
	dlg=dialog;
	
	log.Open("recording.log",CFile::modeCreate | CFile::modeWrite);
	log.WriteString("In the Recordsound Constructor\n");	
	recording=FALSE;
	isallocated=0;      //memory is not allocated to wavebuffer
	//Create Headers for buffering
	PreCreateHeader();	
	//Setting WAVEFORMATEX  structure for the audio input
	memset(&m_WaveFormatEx,0x00,sizeof(m_WaveFormatEx));	
	m_WaveFormatEx.wFormatTag=WAVE_FORMAT_PCM;
	m_WaveFormatEx.nChannels=1;
	m_WaveFormatEx.wBitsPerSample=8;
	m_WaveFormatEx.cbSize=0;
	m_WaveFormatEx.nSamplesPerSec=SAMPLERSEC;  //22.05 KHz	
	m_WaveFormatEx.nBlockAlign=1; //(m_WaveFormatEx.wBitsPerSample/8)*m_WaveFormatEx.nChannels;	
	m_WaveFormatEx.nAvgBytesPerSec=SAMPLERSEC ;  //m_WaveFormatEx.nBlockAlign;
}


RecordSound::~RecordSound()
{
	
	if(!isallocated)
	return;

	for(int i=0;i<MAXRECBUFFER;i++)
	{
		if(rechead[i])
		delete rechead[i];
	}
}


BOOL RecordSound::InitInstance()
{
return TRUE;
}

int RecordSound::ExitInstance()
{
	return CWinThread::ExitInstance();
}


void RecordSound::PreCreateHeader()
{

for(int i=0;i<MAXRECBUFFER;i++)
rechead[i]=CreateWaveHeader();

isallocated=1;
}





LRESULT RecordSound::OnStartRecording(WPARAM wp,LPARAM lp)
{
	
	if(recording)
	return FALSE;
	log.WriteString("¿ªÊ¼Â¼Òô....\n");
	MMRESULT mmReturn = ::waveInOpen( &m_hRecord, WAVE_MAPPER,
			&m_WaveFormatEx, ::GetCurrentThreadId(), 0, CALLBACK_THREAD);
	
	//Error has occured while opening device
	if(mmReturn!=MMSYSERR_NOERROR )
	{
		displayError(mmReturn,"Open");
		return FALSE;
	}		
			
	if(mmReturn==MMSYSERR_NOERROR )
	{
			
		for(int i=0; i < MAXRECBUFFER ; i++)
		{
			mmReturn = ::waveInPrepareHeader(m_hRecord,rechead[i], sizeof(WAVEHDR));
			mmReturn = ::waveInAddBuffer(m_hRecord, rechead[i], sizeof(WAVEHDR));
		}							
		mmReturn = ::waveInStart(m_hRecord);		
		if(mmReturn!=MMSYSERR_NOERROR )
			displayError(mmReturn,"Start");
		else
			recording=TRUE;				
		}
	return TRUE;
}

	
void RecordSound::displayError(int mmReturn,char errmsg[])
{
char errorbuffer[MAX_PATH];
char errorbuffer1[MAX_PATH];

	waveInGetErrorText( mmReturn,errorbuffer,MAX_PATH);
	sprintf(errorbuffer1,"RECORD: %s : %x : %s",errmsg,mmReturn,errorbuffer);
	AfxMessageBox(errorbuffer1);  
}




LRESULT RecordSound::OnStopRecording(WPARAM wp,LPARAM lp)
{
MMRESULT mmReturn = 0;

log.WriteString("\nIn the onstop recording");	
	
		if(!recording)
		return FALSE;

		mmReturn = ::waveInStop(m_hRecord);
		
		
		//To get the remaining sound data from buffer
		//Reset will call OnSoundData function	
		
		if(!mmReturn)
		{
			recording = FALSE;
			mmReturn = ::waveInReset(m_hRecord);  
		}
		
		
		Sleep(500); 
	
			if(!mmReturn)
			mmReturn = ::waveInClose(m_hRecord);
	
		return mmReturn;

}




LRESULT RecordSound::OnSoundData(WPARAM wParam, LPARAM lParam)
{
	
	
		log.WriteString("\nIn the onsound data");
		
		if(recording==FALSE)
		return FALSE;
		
	
	
	    LPWAVEHDR lpHdr = (LPWAVEHDR) lParam;

		
		if(lpHdr->dwBytesRecorded==0 || lpHdr==NULL)
		return ERROR_SUCCESS;
		
		::waveInUnprepareHeader(m_hRecord, lpHdr, sizeof(WAVEHDR));

		// Send recorded audio to remote host...
		if(lpHdr->lpData!=NULL )
		( (CVideoVoiceTransDlg*) dlg )->daudio.SendAudioData((unsigned char *)lpHdr->lpData,lpHdr->dwBytesRecorded);
		
		if(recording)
		{
			//Reuse the old buffer
			::waveInPrepareHeader(m_hRecord,lpHdr, sizeof(WAVEHDR));
			::waveInAddBuffer(m_hRecord, lpHdr, sizeof(WAVEHDR));
		}

return ERROR_SUCCESS;

}

LRESULT RecordSound::OnEndThread(WPARAM wp,LPARAM lp)
{
	log.WriteString("\nIN the onendthread");	
	
	if(recording)
	OnStopRecording(0,0);

	::PostQuitMessage(0);
	return TRUE;
}

LPWAVEHDR  RecordSound::CreateWaveHeader()
{
	LPWAVEHDR lpHdr = new WAVEHDR;
	
	if(lpHdr==NULL)
	{
		log.WriteString("\n Unable to allocate the memory");
		return NULL;
	}
	
	ZeroMemory(lpHdr, sizeof(WAVEHDR));
	char* lpByte = new char[RECBUFFER];//m_WaveFormatEx.nBlockAlign*SOUNDSAMPLES)];
	
	if(lpByte==NULL)
	{
		log.WriteString("\n Unable to allocate the memory");
		return NULL;
	}
	lpHdr->lpData =  lpByte;
	lpHdr->dwBufferLength =RECBUFFER;   // (m_WaveFormatEx.nBlockAlign*SOUNDSAMPLES);
	return lpHdr;

}

