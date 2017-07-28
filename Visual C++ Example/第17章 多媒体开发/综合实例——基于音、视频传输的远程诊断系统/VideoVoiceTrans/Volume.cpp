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
//    Name    : Volume.cpp
//    Details : Volume control dialog class
//
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include <mmsystem.h>
#include <afxcmn.h>
#include "Mixer.h"
#include "Volume.h"
#include "Resource.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////
BEGIN_MESSAGE_MAP(Volume,CDialog)
ON_WM_HSCROLL()
END_MESSAGE_MAP()


Volume::Volume(int n):CDialog(n)
{

}

BOOL Volume::OnInitDialog()
{
int min,max;

	//Volume control for recording 
	mixrec=new CMixer(MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE, CMixer::Record,min,max);

	srec=(CSliderCtrl*)GetDlgItem(IDC_SLIDER1);

	srec->SetRange(min,max);
	int pos=mixrec->GetVolume();
	srec->SetPos(pos);

	//Volume control for playing 
	mixplay=new CMixer(MIXERLINE_COMPONENTTYPE_DST_SPEAKERS ,CMixer::Play,min,max);	

	splay=(CSliderCtrl*)GetDlgItem(IDC_SLIDER2);

	splay->SetRange(min,max);
	pos=mixplay->GetVolume();
	splay->SetPos(pos);


return TRUE;
}


//
//  Invoked when slider pointer is changed...
//
void Volume::OnHScroll(UINT code,UINT pos,CScrollBar *scroll)
{
int vol;
	if(srec==(CSliderCtrl*)scroll)
	{
	vol=srec->GetPos();
	mixrec->SetVolume(vol);
	}

	if(splay==(CSliderCtrl*)scroll)
	{
	vol=splay->GetPos();
	mixplay->SetVolume(vol);
	}

}

