
#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "VideoVoiceTransDlg.h"
#include "PlaySound.h"
#include <mmsystem.h>
#include <mmreg.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
IMPLEMENT_DYNCREATE(PlaySound1, CWinThread)

BEGIN_MESSAGE_MAP(PlaySound1, CWinThread)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_STARTPLAYING, OnStartPlaying)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_STOPPLAYING, OnStopPlaying)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_PLAYBLOCK, OnWriteSoundData)
	ON_THREAD_MESSAGE(MM_WOM_DONE, OnEndPlaySoundData)
	ON_THREAD_MESSAGE(WM_PLAYSOUND_ENDTHREAD,OnEndThread)
END_MESSAGE_MAP()




PlaySound1::PlaySound1()
{


}

PlaySound1::PlaySound1(CDialog *dialog)
{
	
	log.Open("playsound.log",CFile::modeCreate | CFile::modeWrite);
	dlg=dialog;
	
	//GetDevProperty();

/*
	memset(&m_WaveFormatEx,0x00,sizeof(m_WaveFormatEx));
	
	m_WaveFormatEx.wfx.wFormatTag = WAVE_FORMAT_GSM610;
	m_WaveFormatEx.wfx.nChannels = 1;
	m_WaveFormatEx.wfx.wBitsPerSample = 0;
	m_WaveFormatEx.wfx.cbSize = 2;
	m_WaveFormatEx.wfx.nSamplesPerSec = SAMPLEPSEC;
	m_WaveFormatEx.wfx.nAvgBytesPerSec = 1625; //(SAMPLEPSEC/320)*65 ;
	m_WaveFormatEx.wfx.nBlockAlign = 65;
	m_WaveFormatEx.wSamplesPerBlock=320;


*/	
	memset(&m_WaveFormatEx,0x00,sizeof(m_WaveFormatEx));
	
	m_WaveFormatEx.wFormatTag = WAVE_FORMAT_PCM;
	m_WaveFormatEx.nChannels = 1;
	m_WaveFormatEx.wBitsPerSample = 8;
	m_WaveFormatEx.cbSize = 0;
	m_WaveFormatEx.nSamplesPerSec = SAMPLEPSEC;
	m_WaveFormatEx.nAvgBytesPerSec = SAMPLEPSEC ;
	m_WaveFormatEx.nBlockAlign = 1;
	
	  

	Playing = FALSE;
	
	log.WriteString("\n In the constructor of Play sound");

}


PlaySound1::~PlaySound1()
{

}

void PlaySound1::GetDevProperty()
{
CString format;
WAVEOUTCAPS wavecap;
int propno[]= { 
				WAVECAPS_LRVOLUME ,
				WAVECAPS_PITCH ,
				WAVECAPS_PLAYBACKRATE,
				WAVECAPS_SYNC ,
				WAVECAPS_VOLUME,
				WAVECAPS_SAMPLEACCURATE ,
				};

CString propstr[]={
				"WAVECAPS_LRVOLUME ",
				"WAVECAPS_PITCH ",
				"WAVECAPS_PLAYBACKRATE",
				"WAVECAPS_SYNC" ,
				"WAVECAPS_VOLUME",
				"WAVECAPS_SAMPLEACCURATE" ,
				};

	// Special property
	format.Empty();
	format="\nSpecial properties... \n";
		for(int j=0;j<6;j++)
		{
			if( (wavecap.dwSupport & (unsigned)propno[j]) ==(unsigned) propno[j])
			{
			format+=propstr[j]+"\n";	
			}
		}
	
	log.WriteString(format);


}






BOOL PlaySound1::InitInstance()
{

return TRUE;
}






int PlaySound1::ExitInstance()
{
	return CWinThread::ExitInstance();
}





LRESULT PlaySound1::OnStartPlaying(WPARAM wParam, LPARAM lParam)
{
	MMRESULT mmReturn = 0;

	if(Playing)
	return FALSE;

	log.WriteString("\n Starting playing");
	
		// open wavein device
		 mmReturn = ::waveOutOpen( &m_hPlay, WAVE_MAPPER,
			&m_WaveFormatEx, ::GetCurrentThreadId(), 0, CALLBACK_THREAD);
		
		if(mmReturn )
			displayError(mmReturn,"PlayStart");	
		else
		{	
			Playing = TRUE;
			DWORD volume=0xffffffff;
			char str[100];		
			waveOutSetVolume(m_hPlay,volume);
		}			
	
		
return TRUE;
}





void PlaySound1::displayError(int code,char mesg[])
{

char errorbuffer[MAX_PATH];
char errorbuffer1[MAX_PATH];
waveOutGetErrorText( code,errorbuffer,MAX_PATH);
sprintf(errorbuffer1,"PLAY : %s :%x:%s",mesg,code,errorbuffer);
AfxMessageBox(errorbuffer1);  

}



LRESULT PlaySound1::OnStopPlaying(WPARAM wParam, LPARAM lParam)
{
	
	MMRESULT mmReturn = 0;

		if(Playing==FALSE)
		return FALSE;

        log.WriteString("\n Stopped  playing");
		
		
		mmReturn = ::waveOutReset(m_hPlay);
		
		if(!mmReturn)
		{
			Playing = FALSE;
			Sleep(500);
			mmReturn = ::waveOutClose(m_hPlay);
		}


		return mmReturn;
}







LRESULT PlaySound1::OnEndPlaySoundData(WPARAM wParam, LPARAM lParam)
{
	LPWAVEHDR lpHdr = (LPWAVEHDR) lParam;
	
	if(lpHdr)
	{
		::waveOutUnprepareHeader(m_hPlay, lpHdr, sizeof(WAVEHDR));
	
	}

	return ERROR_SUCCESS;
}





LRESULT PlaySound1::OnWriteSoundData(WPARAM wParam, LPARAM lParam)
{
	MMRESULT mmResult = 0;
	int length=(int) wParam;

	if(((CVideoVoiceTransDlg*)dlg)->isAudioReceive==FALSE)
	{
		log.WriteString("\nreception is disabled....");
		return FALSE;
	}

	if(Playing==FALSE)
	return FALSE;

	log.WriteString("\nplaying sound data....");


	// Prepare wave header for playing 
	WAVEHDR *lpHdr=new WAVEHDR;
	memset(lpHdr,0,sizeof(WAVEHDR));
	lpHdr->lpData=(char *)lParam;
	lpHdr->dwBufferLength=length;

	
			mmResult = ::waveOutPrepareHeader(m_hPlay, lpHdr, sizeof(WAVEHDR));
					
			if(mmResult)
			{
				log.WriteString("\nError while preparing header");
				return ERROR_SUCCESS;
			}
		
			mmResult = ::waveOutWrite(m_hPlay, lpHdr, sizeof(WAVEHDR));
			
			if(mmResult)
			{
				log.WriteString("\nError while writing to device");
				return ERROR_SUCCESS;
				
			}
	

	return ERROR_SUCCESS;
}





/**
*	End this thread...
*
*/
LRESULT PlaySound1::OnEndThread(WPARAM wParam, LPARAM lParam)
{
	
	// If already playing then stop it...
	if(Playing==TRUE)
	OnStopPlaying(0,0);
	
	log.WriteString("\nEnding the play device");

	// Quit this thread...
	::PostQuitMessage(0);
	
	return TRUE;
}
