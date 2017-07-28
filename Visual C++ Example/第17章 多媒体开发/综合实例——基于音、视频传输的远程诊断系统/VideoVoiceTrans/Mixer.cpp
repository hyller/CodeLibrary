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
//    Name    : Mixer.cpp
//    Details : Mixer functions for controling volume
//
//
/////////////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "VideoVoiceTrans.h"

#include "Mixer.h"

#include <mmsystem.h>

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////




CMixer::CMixer(DWORD ComponentType, DestKind dkKind,int & min,int & max)
{
	HMIXER hMixer;
	HRESULT hr;
	hr = mixerOpen(&hMixer, 0, 0, 0, 0);
	
	if (hr!= MMSYSERR_NOERROR) 
	return;

	
	 m_dwControlID=-1;
	 m_bOK=FALSE;
	 m_dwChannels=1;
	
	 
	MIXERLINE mxl;
	MIXERCONTROL mxc;
	MIXERLINECONTROLS mxlc;
	DWORD kind, count;

	if (dkKind == Play)
		kind = MIXERLINE_COMPONENTTYPE_DST_SPEAKERS;
	else 
		kind = MIXERLINE_COMPONENTTYPE_DST_WAVEIN;

	mxl.cbStruct = sizeof(mxl);
	mxl.dwComponentType = kind;

    hr = mixerGetLineInfo((HMIXEROBJ)hMixer, &mxl, MIXER_GETLINEINFOF_COMPONENTTYPE |MIXER_OBJECTF_HMIXER);
	

	if (hr!= MMSYSERR_NOERROR)
	{
		mixerClose(hMixer);
		return;
	}

	count = mxl.dwSource;
/*	
	if(count==-1)
	{
	AfxMessageBox("There are no source lines for this destination line");

	return;
	}
	
*/
	// get dwControlID
	
	if(dkKind == Play)
	{
	mxlc.cbStruct = sizeof(MIXERLINECONTROLS);
	mxlc.dwLineID = mxl.dwLineID;
	mxlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
	mxlc.cControls = 1;
	mxlc.cbmxctrl = sizeof(MIXERCONTROL);
	mxlc.pamxctrl = &mxc;
	if (::mixerGetLineControls(reinterpret_cast<HMIXEROBJ>(hMixer),
							   &mxlc,
							   MIXER_OBJECTF_HMIXER |
							   MIXER_GETLINECONTROLSF_ONEBYTYPE)
		!= MMSYSERR_NOERROR)
	{
		return ;
	}
   			m_dwChannels = 1;
			m_dwControlID = mxc.dwControlID;
			min=mxc.Bounds.dwMinimum;
			max=mxc.Bounds.dwMaximum;
	
	}	
	else
	{
	
	for(UINT i = 0; i < count; i++)
	{
		mxl.dwSource = i;
		mixerGetLineInfo((HMIXEROBJ)hMixer, &mxl, MIXER_GETLINEINFOF_SOURCE | MIXER_OBJECTF_HMIXER);
		
		if (mxl.dwComponentType == ComponentType)
		{
			m_dwChannels = mxl.cChannels;
			mxc.cbStruct = sizeof(mxc);
			mxlc.cbStruct = sizeof(mxlc);
			mxlc.dwLineID = mxl.dwLineID;
			mxlc.dwControlType = MIXERCONTROL_CONTROLTYPE_VOLUME;
			mxlc.cControls = 1;
			mxlc.cbmxctrl = sizeof(MIXERCONTROL);
			mxlc.pamxctrl = &mxc;
			hr = mixerGetLineControls((HMIXEROBJ)hMixer, &mxlc, MIXER_GETLINECONTROLSF_ONEBYTYPE | MIXER_OBJECTF_HMIXER);
			m_dwControlID = mxc.dwControlID;
			min=mxc.Bounds.dwMinimum;
			max=mxc.Bounds.dwMaximum;
			break;
		};
	}
	
	}
	
	m_bOK=TRUE;
		
	mixerClose(hMixer);
}

void CMixer::SetVolume(DWORD dwVol)
{
	if (!m_bOK) return;
	
	HMIXER hMixer;
	HRESULT hr;
	hr = mixerOpen(&hMixer, 0, 0, 0, 0);
	
	if (hr!= MMSYSERR_NOERROR)
	return;

	MIXERCONTROLDETAILS mxcd;
	MIXERCONTROLDETAILS_UNSIGNED mxdu;

	mxdu.dwValue = dwVol;

	mxcd.cMultipleItems = 0;       /********Modified code ******/
	mxcd.cChannels = m_dwChannels;
	mxcd.cbStruct = sizeof(mxcd);
	mxcd.dwControlID = m_dwControlID;
	mxcd.cbDetails = sizeof(mxdu);
	mxcd.paDetails = &mxdu;
	
	hr = mixerSetControlDetails((HMIXEROBJ)hMixer, &mxcd, MIXER_SETCONTROLDETAILSF_VALUE | MIXER_OBJECTF_HMIXER);	
	
	mixerClose(hMixer);
}

DWORD CMixer::GetVolume()
{
	if (!m_bOK) return 0;
	HMIXER hMixer;
	HRESULT hr;
	hr = mixerOpen(&hMixer, 0, 0, 0, 0);
	if (FAILED(hr)) return 0;

	MIXERCONTROLDETAILS mxcd;
	MIXERCONTROLDETAILS_UNSIGNED mxdu;


	mxcd.cMultipleItems = 0;  
	mxcd.cChannels = m_dwChannels;
	mxcd.cbStruct = sizeof(mxcd);
	mxcd.dwControlID = m_dwControlID;
	mxcd.cbDetails = sizeof(mxdu);
	mxcd.paDetails = &mxdu;
	hr = mixerGetControlDetails((HMIXEROBJ)hMixer, &mxcd, MIXER_GETCONTROLDETAILSF_VALUE | MIXER_OBJECTF_HMIXER);	
	
	mixerClose(hMixer);
	return mxdu.dwValue;
}
