// QuestConnect.cpp : implementation file
//

#include "stdafx.h"
#include "VideoVoiceTrans.h"
#include "QuestConnect.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CQuestConnect dialog


CQuestConnect::CQuestConnect(CWnd* pParent /*=NULL*/)
	: CDialog(CQuestConnect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CQuestConnect)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CQuestConnect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CQuestConnect)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CQuestConnect, CDialog)
	//{{AFX_MSG_MAP(CQuestConnect)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CQuestConnect message handlers

void CQuestConnect::OnQuestconnect() 
{
	// TODO: Add your control notification handler code here
	
}

void CQuestConnect::OnOK() 
{
	// TODO: Add extra validation here
	UpdateData(true);

	
	CDialog::OnOK();
}
