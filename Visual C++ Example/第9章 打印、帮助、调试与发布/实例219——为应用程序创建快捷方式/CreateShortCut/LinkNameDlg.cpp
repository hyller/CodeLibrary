// LinkName.cpp : implementation file
//

#include "stdafx.h"
#include "CreateShortCut.h"
#include "LinkNameDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLinkName dialog


CLinkNameDlg::CLinkNameDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLinkNameDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLinkName)
	m_linkname = _T("");
	//}}AFX_DATA_INIT
}


void CLinkNameDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLinkName)
	DDX_Text(pDX, IDC_EDIT1, m_linkname);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CLinkNameDlg, CDialog)
	//{{AFX_MSG_MAP(CLinkName)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLinkName message handlers
